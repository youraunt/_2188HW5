//
// Created by BK Allen on 3/5/20.
//

#include "Dictionary.h"

/// @brief Implementation of header provided by Dr. Choi
/// @param fileName string of filename entered by user pre-verified but doulby checked
/// @param infile file stream
/// @param std::list doubly linked list to be built
/// @return newly created std::list
std::list<DictEntry>
Dictionary::listBuilder
        (const std::string &filename, std::ifstream &infile, std::list<DictEntry> &list) {
    /// @reference https://en.cppreference.com/w/cpp/filesystem/exists
    bool exists = {std::__fs::filesystem::exists(filename)};/// checks if file exists
    if (exists) {
        infile.open(filename, std::ios_base::in);/// opens file stream
        wordType word_type;
        /// builds list word by word
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

/// @brief function to search for matches in dictionary
/// @param wordList list of words that we are searching for
/// @param findString string that we are searching for
/// @return if the word is found return how many iterations it took to find else return false
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

/// @brief function to search for matches in dictionary
/// @param wordList list of words that we are searching for
/// @param findString string that we are searching for
/// @return if the word is found return how many iterations it took to find else return false
/// @brief I wanted to use boost here to clean up the code, but I have yet been able to integrate boost on csegrid
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

/// @brief This function writes the dictionary out
/// @param outfile file stream
/// @param wordList list of words to be printed
/// I wanted to use boost reverse to iterate backwards here but cant on csegrid
void Dictionary::revPrintList(std::ostream &outfile, std::list<DictEntry> &wordList) {
    //for (auto &i : boost::adaptors::reverse::(wordList)) { outfile << i.getWord() << " "; }
    std::list<DictEntry>::reverse_iterator reverseIterator;
    for (reverseIterator = wordList.rbegin();
         reverseIterator != wordList.rend();
         ++reverseIterator) {
        outfile << reverseIterator->getWord() << std::endl;
    }
    std::cout << "Successful!" << std::endl;
}///#revPrintList

Dictionary::Dictionary() = default;


