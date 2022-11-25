/*************************************************************
//                  Parking Module
// File    Parking.cpp
// Version 1.0
// Date    November 7, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Parking class implimentation
// --------------------------------------
// Name            Date            Reason
// J Giroux       Nov 7, 22       Initial Version 1.0
// J Giroux       Nov 20, 22      Added functionality
// -----------------------------------------------------------
// I have done all the coding myself and only copied the
// code provided from the course repository to complete my
// project milestones.
// -----------------------------------------------------------
*************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Parking.h"
#include "Utils.h"
#include "Car.h"
#include "Motorcycle.h"

using namespace std;

namespace sdds {
    // Parking constructor - if path/filename is valid then allocate
    // memory and load the menus
    Parking::Parking(const char* path, int numSpots) : m_path(nullptr),
        m_menu("Parking Menu, select an action:", 0),
        m_Vmenu("Select type of the vehicle:", 1) {
        if (path && path[0] != '\0' && numSpots <= m_numSpots && numSpots >= 10) {
            m_numSpots = numSpots;
            m_path = ut.alcpy(path);
            for (int i = 0; i < MAX_PARKING_SPOTS; i++)
                m_vehicles[i] = nullptr;
        }
        if (loadData()) { // loads file data and populates menu's
            m_menu << "Park Vehicle" << "Return Vehicle" <<
                "List Parked Vehicles" << "Find Vehicle" <<
                "Close Parking (End of day)" << "Exit Program";
            m_Vmenu << "Car" << "Motorcycle" << "Cancel";
        } else cout << "Error in data file" << endl;
    }
    // parking program - nuts and boltd
    int Parking::run() {
        int choice, ret = 1;
        bool res = false;
        if (!isEmpty()) {
            ret = 0;
            do {
                status();
                choice = m_menu.run();
                if (choice == 1) park();
                else if (choice == 2) returnV();
                else if (choice == 3) list();
                else if (choice == 4) find();
                else if (choice == 5) res = close();
                else if (choice == 6) res = exitApp();
            } while (!res);
        }
        return ret;
    }
    bool Parking::isEmpty() const {
        return m_path == nullptr;
    }
    void Parking::status() const {
        cout << "****** Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout.setf(ios::left);
        cout << setw(5) << m_numSpots - m_numParked << "*****" << endl;
        cout.unsetf(ios::left);
    }
    // created to eliminate duplicate logic from park()
    void Parking::parkVehicle(Vehicle* V, int loc) {
        V->setCsv(false);
        cout << endl;
        V->read();
        V->setParkingSpot(loc + 1);
        cout << endl << "Parking Ticket" << endl;
        V->write(cout);
        cout << endl;
        m_numParked++;
    }
    // park a vehicle using the sub-menu for car or motorcycle
    void Parking::park() {
        int selection, spotFound = -1;
        for (int i = 0; i < m_numSpots && spotFound == -1; i++)
            if (!m_vehicles[i])
                spotFound = i;
        selection = m_Vmenu.run();
        if (spotFound >= 0 && spotFound <= m_numSpots) {
            if (selection == 1) {
                m_vehicles[spotFound] = new Car;
                parkVehicle(m_vehicles[spotFound], spotFound);
            } else if (selection == 2) {
                m_vehicles[spotFound] = new Motorcycle;
                parkVehicle(m_vehicles[spotFound], spotFound);
            } else cout << "Parking cancelled" << endl;
            cout << endl;
        } else cout << "Parking Full!!" << endl << endl;

    }
    // remove a veichle from the lot
    void Parking::returnV() {
        const char* plate;
        int locFound = -1;
        cout << "Return Vehicle" << endl;
        plate = ut.getDynCstr("Enter Licence Plate Number: ");
        int len = ut.strlen(plate);
        while (len < 1 || len > 8) {
            plate = ut.getDynCstr("Invalid Licence Plate, try again: ");
            len = ut.strlen(plate);
        }
        for (int i = 0; i < m_numSpots; i++)
            if (m_vehicles[i])
                if (ut.stricmp(m_vehicles[i]->getLicencePlate(), plate) == 0)
                    locFound = i;
        if (locFound == -1) {
            cout << endl << "Licence plate ";
            ut.toUpper(plate, cout);
            cout << " Not found" << endl << endl;
        } else {
            cout << endl << "Returning:" << endl;
            m_vehicles[locFound]->setCsv(false);
            m_vehicles[locFound]->write();
            cout << "\n\n";
            delete m_vehicles[locFound];
            m_vehicles[locFound] = nullptr;
            m_numParked--;
        }
        delete[] plate;
    }
    // show vehicles in the lot
    void Parking::list() {
        cout << "*** List of parked vehicles ***" << endl;
        for (int i = 0; i < m_numSpots; i++)
            if (m_vehicles[i]) {
                m_vehicles[i]->setCsv(false);
                m_vehicles[i]->write(cout) << endl;
                cout << "-------------------------------" << endl;
            }
    }
    // find a specific vehicle
    void Parking::find() {
        const char* plate;
        int locFound = -1;
        cout << "Vehicle Search" << endl;
        plate = ut.getDynCstr("Enter Licence Plate Number: ");
        int len = ut.strlen(plate);
        while (len < 1 || len > 8) {
            cout << "Invalid Licence Plate, try again: ";
            plate = ut.getDynCstr();
            len = ut.strlen(plate);
        }
        for (int i = 0; i < m_numSpots; i++)
            if (m_vehicles[i])
                if (ut.stricmp(m_vehicles[i]->getLicencePlate(), plate) == 0)
                    locFound = i;
        if (locFound == -1) {
            cout << endl << "Licence plate ";
            ut.toUpper(plate, cout);
            cout << " Not found" << endl << endl;
        } else {
            cout << endl << "Vehicle found:" << endl;
            m_vehicles[locFound]->setCsv(false);
            m_vehicles[locFound]->write();
            cout << "\n\n";
        }
        delete[] plate;
    }
    // close for the day and tow all vehicles from lot
    bool Parking::close() {
        bool res = false;
        if (m_numParked == 0) {
            cout << "Closing Parking" << endl;
            res = true;
        } else {
            cout << "This will Remove and tow all remaining Vehicles from the Parking!!"
                << endl;
            cout << "Are you sure? (Y)es/(N)o: ";
            if (ut.getYN(cin)) {
                res = true;
                cout << "Closing Parking" << endl;
                for (int i = 0; i < m_numSpots; i++)
                    if (m_vehicles[i]) {
                        cout << endl << "Towing request" <<
                            endl << "*********************" << endl;
                        m_vehicles[i]->setCsv(false);
                        m_vehicles[i]->write() << endl;
                        delete m_vehicles[i];
                        m_vehicles[i] = nullptr;
                    }
            }
            saveData();
        }
        return res;
    }
    // closes the app and saves data 
    bool Parking::exitApp() {
        bool res = false;
        cout << "This will terminate the program!!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        if (ut.getYN(cin)) {
            res = true;
            cout << "Exiting program!" << endl;
            saveData();
        }
        return res;
    }
    Parking::~Parking() {
        delete[] m_path;
        for (int i = 0; i < m_numSpots; i++)
            if (m_vehicles[i]) delete m_vehicles[i];
    }
    // loading and saving data to a file
    bool Parking::loadData() {
        bool res = true;
        bool ok = true;
        char ch;
        Vehicle* V{};
        ifstream fin(m_path);
        while (ok && m_numParked < m_numSpots) {
            fin.get(ch);
            if (!fin.eof()) {
                V = nullptr;
                if (ch == 'C' || ch == 'c') V = new Car;
                else if (ch == 'M' || ch == 'm') V = new Motorcycle;
                else res = false;
                fin.ignore(); // ignore , after writeType
                if (res) {
                    V->setCsv(true);
                    V->read(fin);
                    m_vehicles[V->getParkingSpot() - 1] = V;
                    m_numParked++;
                }
            } else ok = false;
        }
        fin.close();
        return res;
    }
    void Parking::saveData() {
        ofstream fout(m_path);
        if (fout) {
            for (int i = 0; i < m_numSpots; i++)
                if (m_vehicles[i]) {
                    m_vehicles[i]->setCsv(true);
                    fout << *m_vehicles[i] << endl;
                }
            fout.close();
        } else cout << "Couldn't open file " << m_path << endl;
    }
}