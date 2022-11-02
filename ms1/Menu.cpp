/*************************************************************
//                  Menu Module
// File    Menu.cpp
// Version 1.0
// Date    October 31, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Menu class implimentation
// --------------------------------------
// Name            Date            Reason
// J Giroux       Nov 1, 22       Initial Version 1.0
//
// -----------------------------------------------------------
// I have done all the coding myself and only copied the
// code that my professor provided to complete my project
// milestones.
// -----------------------------------------------------------
*************************************************************/

#include <iostream>
#include "Menu.h"

using namespace std;

namespace sdds {
    // Menu constructor
    Menu::Menu(const char* title, int indent) : m_title{ 0 } {
        if (title) {
            m_valid = true;
            m_indent = indent;
            strcpy(m_title, title, 50);
        } else m_valid = false;
    }
    // private queries and helpers
    bool Menu::isEmpty() const {
        return m_numItems == 0;
    }
    bool Menu::isFull() const {
        return m_numItems == MAX_NO_OF_ITEMS;
    }
    bool Menu::isValid() const {
        return m_valid;
    }
    Menu::operator bool() const {
        return isValid();
    }
    Menu::operator int() const {
        return run();
    }
    void Menu::indent(int num) const {
        for (int i = 0; i < num; i++) cout << "    ";
    }
    void Menu::addItem(const char* item) {
        if (item && !isFull() && isValid()) {
            strcpy(m_items[m_numItems].m_item, item, 50);
            m_numItems++;
        } else m_valid = false;
    }
    // set menu empty
    void Menu::clear() {
        m_title[0] = 0;
        m_indent = 0;
        m_numItems = 0;
    }
    // set the menu title with = overload
    Menu& Menu::operator=(const char* newTitle) {
        if (newTitle)
            strcpy(m_title, newTitle, 50);
        else m_valid = false;
        return *this;
    }
    // add items to the menu using << overload and add()
    Menu& Menu::operator<<(const char* item) {
        addItem(item);
        return *this;
    }
    void Menu::add(const char* item) {
        addItem(item);
    }
    // display menu and get selection from user
    int Menu::run() const {
        int num = 0;
        bool ok = false;
        display();
        if (!isEmpty() && isValid()) {
            do {
                cin >> num;
                if (!cin) {
                    cout << "Invalid Integer, try again: ";
                    cin.clear();
                } else if (num < 1 || num > m_numItems)
                    cout << "Invalid selection, try again: ";
                else ok = true;
                cin.ignore(1000, '\n');
            } while (!ok);
        }
        return num;
    }
    // display returning ostream reference
    std::ostream& Menu::display(std::ostream& ostr) const {
        if (!isValid())
            ostr << "Invalid Menu!" << endl;
        else if (isEmpty()) {
            ostr << m_title << endl;
            ostr << "No Items to display!" << endl;
        } else {
            indent(m_indent);
            ostr << m_title << endl;
            for (int i = 0; i < m_numItems; i++) {
                indent(m_indent);
                ostr << i + 1 << "- ";
                m_items[i].display(ostr);
            }
            indent(m_indent);
            ostr << "> ";
        }
        return ostr;
    }
    // output helper
    std::ostream& operator<<(Menu& menu, std::ostream& ostr) {
        menu.display(ostr);
        return ostr;
    }
}