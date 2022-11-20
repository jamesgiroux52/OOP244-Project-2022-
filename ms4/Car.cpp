/*************************************************************
//                      Car Module
// File    Car.cpp
// Version 1.0
// Date    November 19, 2022
// Author  Fardad / James Giroux
// Description:
// Extra Classes and functions needed in the project
// -----------------------------------------------------------
// The first three prototypes are not mine, they where
// provided with workshops.
// -------------
// Name            Date            Reason
// ----            ----            ------
// J Giroux       Nov 19, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the
// code that my professor provided to complete my project
// milestones.
// -----------------------------------------------------------
*************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Car.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    Car::Car() : Vehicle() { }
    Car::Car(const char* plate, const char* mkModel) : Vehicle(plate,mkModel) {
        if (plate && mkModel) {
            int plateLen = ut.strlen(plate);
            int mkModLen = ut.strlen(mkModel);
            if (plateLen > 0 && mkModLen > 1 && plateLen <= 8)
                m_valid = true;
        } else m_valid = false;
    }
    Car::Car(const Car& C) {
        *this = C;
    }
    Car& Car::operator=(const Car& C) {
        if (this != &C) {
            Vehicle::operator=(C);
            m_valid = true;
        } else m_valid = false;
        return *this;
    }
    Car::~Car() {  } // shuldnt need to do anything here bc parents are virtual
    std::ostream& Car::writeType(std::ostream& os) const {
        if (Vehicle::ReadWritable::isCsv()) os << "C,";
        else os << "Vehicle type: Car" << endl;
        return os;
    }
    std::istream& Car::read(std::istream& is) {
        //bool wash = false;
        if (Vehicle::ReadWritable::isCsv()) {
            Vehicle::read();
            m_wash = ut.getYN();
            m_valid = true;
        } else {
            cout << "Car information entry" << endl;
            Vehicle::read();
            cout << "Carwash while parked? (Y)es/(N)o: ";
            m_wash =  ut.getYN();
            m_valid = true;
        }
        return is;
    }
    std::ostream& Car::write(std::ostream& os) const {
        if (m_valid) {
            Vehicle::write();
            if (Vehicle::ReadWritable::isCsv())
                os << m_wash;
            else
                m_wash ? os << "With Carwash" : os << "Without Carwash"; os << endl;
        } else {
            os << "Invalid Car Object" << endl;
        }
        return os;
    }
}
