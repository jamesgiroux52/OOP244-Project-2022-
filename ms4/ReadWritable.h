/*************************************************************
//                 ReadWritable Module
// File    ReadWritable.h
// Version 1.0
// Date    November 12, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Abstract base class for I/O vehicle
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

#ifndef SDDS_READWRITEABLE_H_
#define SDDS_READWRITEABLE_H_

#include <iostream>

namespace sdds {
    // abstract base class - not an interface bc it has implemented 
    //      functions isCsv() & setCsv()
    class ReadWritable {
        bool m_comma; // user input || read from csv file
    public:
        ReadWritable();
        virtual ~ReadWritable();
        bool isCsv() const;
        void setCsv(bool val);
        // pure virtual functions for I/O
        virtual std::istream& read(std::istream& is = std::cin) = 0;
        virtual std::ostream& write(std::ostream& os = std::cout) const = 0;
    };
    std::ostream& operator<<(std::ostream& os, ReadWritable& R);
    std::istream& operator>>(std::istream& is, ReadWritable& R);
}

#endif // !SDDS_READWRITEABLE_H_