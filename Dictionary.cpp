//
// Created by BK Allen on 3/5/20.
//

#include "Dictionary.h"

/// @brief Implementation of header provided by Dr. Choi
/// @param fileName
/// @param infile
/// @param list
/// @return
std::list<DictEntry>
Dictionary::listBuilder
        (const std::string &filename,std::ifstream &infile, std::list<DictEntry> &list) {
    /// @reference https://en.cppreference.com/w/cpp/filesystem/exists
    bool exists={std::__fs::filesystem::exists(filename)};
    if(exists) {
        infile.open(filename, std::ios_base::in);
        wordType word_type;
        do {
            infile >> word_type;
            auto *newNode = new DictEntry;
            newNode->setWord(word_type);
            list.push_back(*newNode);
        } while (infile.peek() != EOF);
    }
    infile.close();
    infile.clear();
    return list;
}///# listBuilder
/// @brief
/// @param wordList
/// @param findString
/// @return
int Dictionary::searchForward(std::list<DictEntry> &wordList, wordType &findString) {
    auto inDict = false;
    auto count = 0;
    for (auto &i : wordList) {
        count += 1;
        if (i.getWord() == findString) {
            inDict = true;
            break;
        }
    }
    return inDict ? count : false;
}///# searchForward

/// @brief
/// @param wordList
/// @param findString
/// @return
int Dictionary::searchBackward(std::list<DictEntry> &wordList, wordType &findString) {
    auto inDict = false;
    auto count = 0;
    for (auto i = wordList.rbegin(); i != wordList.rend(); ++i)
    /*for (auto &i : boost::adaptors::reverse(wordList)) */{
        count += 1;
        if (i->getWord() == findString) {
            inDict = true;
            break;
        }
    }
    return inDict ? count : false;
}///#searchBackward
/// @brief
/// @param output
/// @param wordList
void Dictionary::revPrintList(std::ostream &outfile, std::list<DictEntry> &wordList) {
    for (auto &i : wordList) { outfile << i.getWord() << " "; }
}

Dictionary::Dictionary() = default;
///#revPrintList

