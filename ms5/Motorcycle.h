/*************************************************************
//                      Motorcycle Module
// File    Motorcycle.h
// Version 1.0
// Date    November 19, 2022
// Author  James Giroux
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

#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H

#include <iostream>
#include "Vehicle.h"

namespace sdds {
    // concrete class Motorcycle
    class Motorcycle : public Vehicle {
        bool m_sidecar = false;
        bool m_valid = false; // added for validity
    public:
        Motorcycle();
        Motorcycle(const char* plate, const char* mkModel);
        Motorcycle(const Motorcycle& M);
        Motorcycle& operator=(const Motorcycle& M);
        virtual ~Motorcycle();
        std::ostream& writeType(std::ostream& os) const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;
    };
}

#endif // !SDDS_MOTORCYCLE_H