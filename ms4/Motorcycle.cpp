/*************************************************************
//                      Motorcycle Module
// File    Motorcycle.cpp
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
#include "Motorcycle.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    Motorcycle::Motorcycle() : Vehicle() { }
    Motorcycle::Motorcycle(const char* plate, const char* mkModel)
        : Vehicle(plate, mkModel) 
    {
        if (plate && mkModel) {
            int plateLen = ut.strlen(plate);
            int mkModLen = ut.strlen(mkModel);
            if (plateLen > 0 && mkModLen > 1 && plateLen <= 8)
                m_valid = true;
        } else m_valid = false;
    }
    Motorcycle::Motorcycle(const Motorcycle& M) {
        *this = M;
    }
    Motorcycle& Motorcycle::operator=(const Motorcycle& M) {
        if (this != &M) {
            Vehicle::operator=(M);
            m_valid = true;
        } else m_valid = false;
        return *this;
    }
    Motorcycle::~Motorcycle() {  }
    std::ostream& Motorcycle::writeType(std::ostream& os) const {
        if (Vehicle::ReadWritable::isCsv()) os << "M,";
        else os << "Vehicle type: Motorcycle" << endl;
        return os;
    }
    std::istream& Motorcycle::read(std::istream& is) {
        if (Vehicle::ReadWritable::isCsv()) {
            Vehicle::read();
            m_sidecar = ut.getYN();
            m_valid = true;
        } else {
            cout << "Motorcycle information entry" << endl;
            if (is.peek() == '\n') is.ignore();
            Vehicle::read();
            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            m_sidecar = ut.getYN();
            m_valid = true;
        }
        return is;
    }
    std::ostream& Motorcycle::write(std::ostream& os) const {
        if (m_valid) {
            Vehicle::write();
            if (Vehicle::ReadWritable::isCsv())
                os << m_sidecar;
            else {
                if (m_sidecar) os << "With Sidecar" << endl;
            }
        } else os << "Invalid Motorcycle Object" << endl;
        return os;
    }
}