/*************************************************************
//                 Parking Module
// File    Parking.h
// Version 1.0
// Date    November 7, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Parking class header file
// --------------------------------------
// Name            Date            Reason
// ----            ----            ------
// J Giroux       Nov 7, 22       Initial Version 1.0
//
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the
// code that my professor provided to complete my project
// milestones.
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_

#include "Menu.h"

namespace sdds {
    // parking class -- HAS Menu(s) - not IS a Menu
    class Parking {
        char* m_path;
        Menu m_menu;
        Menu m_Vmenu;
        bool isEmpty();
        void status();
        void park();
        void returnV();
        void list();
        void find();
        bool close();
        bool exitApp();
        bool loadData();
        void saveData();
    public:
        Parking(const char* path, int indent = 0);
        Parking(const Parking& P) = delete;
        Parking& operator=(const Parking& P) = delete;
        int run();
        // making distructor virtual ensures that if Parking inherited a base class 
        // and our main() was using pointers or references to a Parking obj, 
        // the base class destructors would still get called and we won't have 
        // memory leaks
        virtual ~Parking();
        
    };
}

#endif // !SDDS_PARKING_H_