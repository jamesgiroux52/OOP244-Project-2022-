/*************************************************************
//                      Utils Module
// File    Utils.h
// Version 1.4
// Date    November 3, 2022
// Author  Fardad / James Giroux
// Description:
// Extra Classes and functions needed in the project
// -----------------------------------------------------------
// The first three prototypes are not mine, they where
// provided with workshops.
// -------------
// See Utils.cpp for revision
// information
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

#include <iostream>

namespace sdds {
    class Utils {
    public:
        // Fardads
        int strlen(const char* str);
        void strcpy(char* des, const char* src, int len = -1);
        int strcmp(const char* s1, const char* s2);
        char* alcpy(const char* cstr);
        char* getDynCstr(const char* prompt = nullptr);
        // my functions - see Utils.cpp for more details
        int getInt(int low, int high);
        bool getYN(std::istream& is = std::cin);
        int getStr(char* str, bool upper, std::istream& is = std::cin);
        std::string trim(const std::string& str,
            const std::string& whitespace = " \t");
        std::string reduce(const std::string& str,
            const std::string& fill = " ",
            const std::string& whitespace = " \t");
        int stricmp(const char* s1, const char* s2);
        std::ostream& toUpper(const char* srt, std::ostream& os);
    };
    extern Utils ut; // able to use utility members without 
    // withoout instantiating - Only has to
    // be done once at the beginning of 
    // Utils.cpp
}

#endif // !SDDS_UTILS_H_