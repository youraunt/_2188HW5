//
// Created by BK Allen on 3/5/20.
// See implementation file for documentation
//

#ifndef _2188HW5_DICTIONARY_H
#define _2188HW5_DICTIONARY_H



#include "DictEntry.h"
#include "Functions.h"
#include <iostream>
#include <fstream>
#include <list>
class Dictionary {
public:
    //typedef string wordType;
    Dictionary();

    /*Read in a list of words from the Dictionary file*/
    static std::list<DictEntry>
    listBuilder(const std::string &filename, std::ifstream &infile, std::list<DictEntry> &list);

    /*Searches the list starting at the front of the list and moving to the back
     Returns the number of searches it took to find the findString, or a -1 if not found*/
    static int searchForward(std::list<DictEntry> &wordList, wordType &findString);

    /*Searches the list starting at the back of the list and moving to the front
     Returns the number of searches it took to find the findString, or a -1 if not found*/
    static int searchBackward(std::list<DictEntry> &wordList, wordType &findString);

    /*Prints the list of words in reverse alphabetic order to a file*/
    static void revPrintList(std::ostream &output, std::list<DictEntry> &wordList);


};


#endif //_2188HW5_DICTIONARY_H
