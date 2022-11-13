/*************************************************************
//                 Menu Module
// File    Vehicle.h
// Version 1.0
// Date    November 12, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Vehicle class
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

#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_

#include "ReadWritable.h"

namespace sdds {
    class Vehicle : public ReadWritable {
        char m_plate[9]{ '\0' };
        char* m_makeModel = nullptr;
        unsigned m_spot = 0;
        void setEmpty();
        bool isEmpty() const;
        const char* getLicencePlate() const;
        const char* getMakeModel() const;
        unsigned getParkingSpot() const;
    public:
        Vehicle();
        Vehicle(const char* plate, const char* mkModel);
        virtual ~Vehicle();
        Vehicle(const Vehicle& V);
        Vehicle& operator=(const Vehicle& V);
        void setMakeModel(const char* mkModel);
        void setParkingSpot(unsigned spot);
        bool operator==(const char* plate) const;
        bool operator==(const Vehicle& V) const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;
        virtual std::ostream& writeType(std::ostream& os) const = 0;
     };
}

#endif // !SDDS_VEHICLE_H_