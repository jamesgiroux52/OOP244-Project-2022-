/*************************************************************
//                 Menu Module
// File    ReadWritable.cpp
// Version 1.0
// Date    November 12, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// ReadWritable implementation
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

#include "ReadWritable.h"

namespace sdds {
    // default constructor
    ReadWritable::ReadWritable() {
        m_comma = false;
    }
    // default virtual destructor
    ReadWritable::~ReadWritable() { }
    // return the member to determine if we are getting
    // input from a user or a .csv file
    bool ReadWritable::isCsv() const {
        return m_comma;
    }
    // set the flag
    void ReadWritable::setCsv(bool val) {
        m_comma = val;
    }
    // I/O helpers call the unimplemented pure virtual functions
    std::ostream& operator<<(std::ostream& os, ReadWritable& R) {
        R.write(os);
        return os;
    }
    std::istream& operator>>(std::istream& is, ReadWritable& R) {
        R.read(is);
        return is;
    }
}