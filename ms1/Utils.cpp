/*************************************************************
//                  Utils Module
// File    Utils.cpp
// Version 1.0
// Date    October 31, 2022
// Author  Fardad
// Description:
// Extra Classes and functions needed in the project
// -----------------------------------------------------------
// This was provided in one of the workshops from Fardad on
// GitHub. I fully understand how it works and is implimented.
// -----------------------------------------------------------
*************************************************************/

#include "Utils.h"

namespace sdds {
    // finds length of string without using built in cstring functions
    int strlen(const char* str) {
        int len = 0;
        while (str[len]) {
            len++;
        }
        return len;
    }
    // copy a cstring
    void strcpy(char* des, const char* src, int len) {
        int i;
        for (i = 0; src[i] && (len < 0 || i < len); i++) {
            des[i] = src[i];
        }
        des[i] = 0; // turning the char array des in to a cString by null terminating it.
    }
    // Compare a cstring
    int strcmp(const char* s1, const char* s2) {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
}