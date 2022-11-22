/*************************************************************
//                      Car Module
// File    Car.h
// Version 1.4
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

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include "Vehicle.h"

namespace sdds {
    // concrete car class
    class Car : public Vehicle {
        bool m_wash = false;
        bool m_valid = false;
    public:
        Car();
        Car(const char* plate, const char* mkModel);
        Car(const Car& C);
        Car& operator=(const Car& C);
        virtual ~Car();
        std::ostream& writeType(std::ostream& os) const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;
    };
}

#endif // !SDDS_CAR_H
