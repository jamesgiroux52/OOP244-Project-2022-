/*************************************************************
//                 Menu Module
// File    Vehicle.cpp
// Version 1.0
// Date    November 12, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Vehicle class implementation
// --------------------------------------
// Name            Date            Reason
// ----            ----            ------
// J Giroux       Nov 12, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the
// code that my professor provided to complete my project
// milestones.
// -----------------------------------------------------------
*************************************************************/

#include <iostream>
#include <cstring>
#include "Vehicle.h"

using namespace std;

namespace sdds {
    void Vehicle::setEmpty() {
        m_makeModel = nullptr;
        m_plate[0] = '\0';
        m_spot = 0;
    }
    bool Vehicle::isEmpty() const {
        return m_makeModel == nullptr;
    }
    const char* Vehicle::getLicencePlate() const {
        return m_plate;
    }
    const char* Vehicle::getMakeModel() const {
        return m_makeModel;
    }
    unsigned Vehicle::getParkingSpot() const {
        return m_spot;
    }
    Vehicle::Vehicle() {
        setEmpty();
    }
    Vehicle::Vehicle(const char* plate, const char* mkModel) {
        size_t plateLen = strlen(plate);
        size_t mkModLen = strlen(mkModel);
        if (plate && mkModel && plateLen > 0 && mkModLen > 1 && plateLen <= 8) {
            strncpy(m_plate, plate, 8);
            if (m_makeModel) delete[] m_makeModel;
            m_makeModel = new char[mkModLen + 1];
            strcpy(m_makeModel, mkModel);
            m_spot = 0;
        } else setEmpty();
    }
    Vehicle::~Vehicle() {
        delete[] m_makeModel;
    }
    Vehicle::Vehicle(const Vehicle& V) {
        strcpy(m_plate, V.m_plate);
        m_spot = V.m_spot;
        if (V.m_makeModel)
            strcpy(m_makeModel, V.m_makeModel);
        else m_makeModel = nullptr;
    }
    Vehicle& Vehicle::operator=(const Vehicle& V) {
        if (this != &V) {
            m_spot = V.m_spot;
            strcpy(m_plate, V.m_plate);
            delete[] m_makeModel;
            if (V.m_makeModel)
                strcpy(m_makeModel, V.m_makeModel);
            else setEmpty();
        }
        return *this;
    }
    void Vehicle::setMakeModel(const char* mkModel) {
        size_t len = strlen(mkModel);
        if (mkModel && len > 0 && len <= 60) {
            if (m_makeModel) delete[] m_makeModel;
            m_makeModel = new char[len + 1];
            strcpy(m_makeModel, mkModel);
        } else setEmpty();
    }
    void Vehicle::setParkingSpot(unsigned spot) {
        m_spot = spot;
    }
    bool Vehicle::operator==(const char* plate) const {
        int res = stricmp(m_plate, plate);
        return res == 0;
    }
    bool Vehicle::operator==(const Vehicle& V) const {
        return stricmp(m_plate, V.m_plate) == 0;
    }
    std::istream& Vehicle::read(std::istream& is) {
        if (ReadWritable::isCsv()) {
            is >> m_spot;
            is.ignore();
            is.get(m_plate, 8, ',');
            is.ignore();
            is.get(m_makeModel, 60, ',');
            is.ignore();
        } else {
            cout << "Enter Licence Plate Number: ";

        }
        return is;
    }
    std::ostream& Vehicle::write(std::ostream& os) const {
        return os;
    }
}