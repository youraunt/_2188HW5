//
// Created by BK Allen on 3/7/20.
//

#ifndef _2188HW5_FUNCTIONS_H
#define _2188HW5_FUNCTIONS_H

#include "Dictionary.h"
#include "DictEntry.h"
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <fstream>
#include <list>


void toConsole(std::list<DictEntry> &wordList);


unsigned int mainMenu(unsigned int choice);

unsigned int sub_Menu();

unsigned int search_Sub_Menu(std::list<DictEntry> &list, std::list<DictEntry> &list1, wordType &wordType);

std::string getFileName(int argc, char **argv);

bool enterProgram(int argc, char **argv, std::ifstream &infile);

/// @brief Exits program successfully with message
inline std::string exitProgram() {
    std::cout << "Exiting program!" << std::endl;
    /// @brief I used EXIT_SUCCESS here to unwind the stack
    exit(EXIT_SUCCESS);
}

inline void unknownInput() {
    std::cerr << "\nError?! Unknown input.\n" << std::endl;
    exitProgram();
}

#endif //_2188HW5_FUNCTIONS_H
