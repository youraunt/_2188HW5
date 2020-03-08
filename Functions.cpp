//
// Created by BK Allen on 3/7/20.
//

#include "Functions.h"

#include <utility>


/// @brief
/// @param wordList
void toConsole(std::list<DictEntry> &wordList) {
    for (auto &i :wordList) {
        std::cout << i.getWord() << " " << std::endl;
    }
}

std::string getFileName(int argc, char **argv) {
    std::string userInput{};
    /// @brief I am a mac user and not familiar with command line prompts
    /// I got this from a geeks for geeks post
    /// if more than one argument is passed use it.
    if (argc > 1) { userInput = argv[1]; }
        /// else get input from user do/while to continue until valid file is found.
    else {
        do {// until file is found
            std::cout << "Please enter your file name: " << std::endl
                      << "\x1b[32m> \x1b[0m";
            std::cin >> userInput;
            /// @reference https://en.cppreference.com/w/cpp/filesystem/exists
            bool valid{std::__fs::filesystem::exists(userInput)};
            if (!valid) {
                std::cout << "I could not fine your file." << std::endl
                          << "Please, try again." << std::endl;
                continue;
            }
            break;
        } while (true);
    }///# else
    return std::string(userInput);
}

unsigned int mainMenu(unsigned int userChoice) {
    std::cout
            << "<-------Main menu------->" << std::endl
            << "Please select one of the following options by entering it's "
            << "number in the prompt below and pressing [ENTER] " << std::endl
            << "1. Load files" << std::endl
            << "2. Sort" << std::endl
            << "3. Display" << std::endl
            << "4. Search" << std::endl
            << "5. Write out" << std::endl
            << "6. Exit" << std::endl
            << "\x1b[32m> \x1b[0m";
    std::cin >> userChoice;
    return userChoice;
}

unsigned int sub_Menu() {
    auto userChoice{0};
    auto loop = true;
    do {
        std::cout
                << "<-------Load Sub Menu------->"
                << std::endl
                << "Please select one of the following options by entering it's "
                << "number in the prompt below and pressing [ENTER] " << std::endl
                << "1. Load new dictionary" << std::endl
                << "2. Load words to search" << std::endl
                << "3. Return to Main Menu" << std::endl
                << "\x1b[32m> \x1b[0m";
        std::cin >> userChoice;
        if (userChoice == 3) { mainMenu(0); }
        else if (userChoice == 1 || userChoice == 2) { return userChoice; }
    } while (loop);
    return userChoice = 0;
};

std::list<DictEntry> sub_Menu_Switch(unsigned int &subMenuChoice, int argc, char **argv, std::ifstream &infile,
                                     std::list<DictEntry> &dictionary, std::list<DictEntry> &toSearch) {
    auto choice = subMenuChoice;

    switch (choice) {
        case 1:
            dictionary = Dictionary::listBuilder(getFileName(argc, argv), infile, dictionary);
            toConsole(dictionary);
            return dictionary;
        case 2:
            toSearch = Dictionary::listBuilder(getFileName(argc, argv), infile, toSearch);
            return toSearch;
        case 3:
            mainMenu(0);
            break;
        default:
            exitProgram();
            break;
    }
    return std::list<DictEntry>();
}

void displaySearchForward(std::list<DictEntry> &dictionary, std::list<DictEntry> &toSearch) {
    unsigned int forwardCounter;
    auto wordToSearch = toSearch.begin();
    do {
        wordType word = wordToSearch->getWord();
        forwardCounter = Dictionary::searchForward(dictionary, word);
        if (forwardCounter != 0) {
            std::cout << "\nSearching for: " << word << std::endl;
            std::cout << "searchForward iterations: " << forwardCounter << std::endl;
        } else {
            std::cout << std::endl;
            std::cout << word << " is not in this dictionary!" << std::endl;
        }
        ++wordToSearch;
    } while (toSearch.end() != wordToSearch);
}
void displaySearchBackward(std::list<DictEntry> &dictionary, std::list<DictEntry> &toSearch) {
    unsigned int reverseCounter;
    auto wordToSearch = toSearch.begin();
    do {
        wordType word = wordToSearch->getWord();
        reverseCounter = Dictionary::searchForward(dictionary, word);
        if (reverseCounter != 0) {
            std::cout << "\nSearching for: " << word << std::endl;
            reverseCounter = Dictionary::searchBackward(dictionary, word);
            std::cout << "searchBackwards iterations: " << reverseCounter << std::endl;
        } else {
            std::cout << std::endl;
            std::cout << word << " is not in this dictionary!" << std::endl;
        }
        ++wordToSearch;
    } while (toSearch.end() != wordToSearch);
}

void
search_Sub_Menu_Switch(unsigned int &subMenuChoice, std::list<DictEntry> &dictionary,
                       std::list<DictEntry> &toSearch) {
    auto choice = subMenuChoice;

    switch (choice) {
        case 1:
            displaySearchForward(dictionary, toSearch);
            break;
        case 2:
            displaySearchBackward(dictionary, toSearch);
            break;
        case 3:
            mainMenu(0);
            break;
        default:
            exitProgram();
            break;
    }
}

unsigned int search_Sub_Menu(std::list<DictEntry> &list, std::list<DictEntry> &list1, wordType &findString) {
    auto userChoice{0};
    auto loop = true;
    do {
        std::cout
                << "<-------Search Sub Menu------->"
                << std::endl
                << "Please select one of the following options by entering it's "
                << "number in the prompt below and pressing [ENTER] " << std::endl
                << "1. Search forwards" << std::endl
                << "2. Search backwards" << std::endl
                << "3. Return to Main Menu" << std::endl
                << "\x1b[32m> \x1b[0m";
        std::cin >> userChoice;
        if (userChoice == 3) { mainMenu(0); }
        else if (userChoice == 1 || userChoice == 2) { return userChoice; }
    } while (true);
    return 0;
};


bool enterProgram(int argc, char **argv, std::ifstream &infile) {
    std::list<DictEntry> dictionary;
    std::list<DictEntry> toSearch;
    wordType dictEntries;
    unsigned int choice{};
    unsigned int subMenuChoice{};
    do {
        choice = mainMenu(choice);
        switch (choice) {
            case 1:
                subMenuChoice = sub_Menu();
                sub_Menu_Switch(subMenuChoice, argc, argv, infile, dictionary, toSearch);
                break;
            case 2:
                dictionary.sort();
                std::cout << "Sorted!" << std::endl;
                break;
            case 3:
                toConsole(dictionary);
                break;
            case 4:
                subMenuChoice = search_Sub_Menu(dictionary, toSearch, dictEntries);
                search_Sub_Menu_Switch(subMenuChoice, dictionary, toSearch);
                break;
            case 5:
                std::cout << "to file" << std::endl;
                break;
            case 6:
                exitProgram();
            default:
                break;
        }
    } while (choice != 6);
    return false;
}

