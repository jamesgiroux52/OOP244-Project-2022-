/*************************************************************
//                  Utils Module
// File    Utils.cpp
// Version 1.1
// Date    October 31, 2022
// Author  Fardad
// Description:
// Extra Classes and functions needed in the project
// -----------------------------------------------------------
// This was provided in one of the workshops from Fardad on
// GitHub. I fully understand how it works and is implimented.
//
// James Giroux - Nov 3, 2022
// Added getInt() - used to get a number from istream
//              and returns a number in a valid range.
// -----------------------------------------------------------
*************************************************************/

#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds {
    // instantiating Utils object
    Utils ut;
    // finds length of string without using built in cstring functions
    int Utils::strlen(const char* str) {
        int len = 0;
        while (str[len])
            len++;
        return len;
    }
    // copy a cstring
    void Utils::strcpy(char* des, const char* src, int len) {
        int i;
        for (i = 0; src[i] && (len < 0 || i < len); i++)
            des[i] = src[i];
        des[i] = 0; // turning the char array des in to a cString by null terminating it.
    }
    // Compare a cstring
    int Utils::strcmp(const char* s1, const char* s2) {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
    // used in Menu logic to receive a valid menu list item
    int Utils::getInt(int low, int high) {
        int num;
        bool ok = false;
        do {
            cin >> num;
            if (!cin) {
                cout << "Invalid Integer, try again: ";
                cin.clear();
            } else if (num < low || num > high)
                cout << "Invalid selection, try again: ";
            else ok = true;
            cin.ignore(1000, '\n');
        } while (!ok);
        return num;
    }
}