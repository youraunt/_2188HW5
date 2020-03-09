//
// Created by BK Allen on 3/7/20.
//

#include "Functions.h"

#include <utility>

#define WHAT_IS(x) std::cerr << #x << " is " << x << std::endl;

/// @brief static const char array to display the menu header
static const char MENU_TITLE[] =
        "\n\x1b[36m"
        "-----------------------------------\n"
        "|            Main Menu            |\n"
        "-----------------------------------\n"
        "\n\x1b[0m";

/// @brief This function displays a list to the console
/// @param wordList list to be displayed
void toConsole(std::list<DictEntry> &wordList) {
    for (auto &i :wordList) {
        std::cout << i.getWord() << " " << std::endl;
    }
} ///# toConsole
/// @brief  This function handles user input with option of entering filename at command line
///         Verifies that the file exists before returning filename
/// @param argc (argument count) the number of strings pointed to by argv should be 1+
/// @param argv (argument vector) A one dimensional array of strings. Each string is one/// @return userInput string
//   of the arguments passed to the program.
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
} ///#getFileName
/// @brief Displays main menu
/// @param userChoice the menu choice selected by user
/// @return integer value of user choice
unsigned int mainMenu() {
    unsigned int userChoice = 0;
    std::cout
            << MENU_TITLE << std::endl
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
}///# MainMenu

/// @brief Displays subMenu
/// @return users choice in integer value
unsigned int sub_Menu() {
    auto userChoice{0};
//    auto loop = true;
//    do {
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

//        if (userChoice == 3) { mainMenu(); }
//        else if (userChoice == 1 || userChoice == 2) { return userChoice; }
//    } while (loop);
    return userChoice;
}///# sub_Menu

/// @brief handles submenu input
/// @param subMenuChoice integer value of users choice of menu item
/// @param argc (argument count) the number of strings pointed to by argv should be 1+
/// @param argv (argument vector) A one dimensional array of strings. Each string is one
//   of the arguments passed to the program.
/// @param infile filestream
/// @param dictionary dictionary list
/// @param toSearch  word to check if present in dictionary
/// @return I couldnt figure out what to return at the bottom because my cases are already returning the appropriate thing
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
            toConsole(toSearch);
            return toSearch;
        case 3:
            break;
        default:
            exitProgram();
            break;
    }

    return std::list<DictEntry>();
}///# sub_Menu_Switch

/// @brief function to display results from search forward
/// @param dictionary dictionary list
/// @param toSearch word to search for list
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
} ///# displaySearchForwards

/// @brief function to display results from search backward
/// @param dictionary dictionary list
/// @param toSearch word to search for list
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
}///# displaySearchBackwards

/// @brief search submenu switch
/// @param subMenuChoice integer value of users selection
/// @param dictionary list of dictionary words
/// @param toSearch list of words to be searched
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
            break;
        default:
            exitProgram();
            break;
    }
}///# search_Sub_Menu_Switch
/// @brief Displays subMenu
/// @return users choice in integer value
unsigned int search_Sub_Menu() {
    auto userChoice{0};
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
    return userChoice;
}///# search_Sub_Menu

/// @brief This is where you enter the program calls function to display menu and handles them witha switch
/// @param argc (argument count) the number of strings pointed to by argv should be 1+
/// @param argv (argument vector) A one dimensional array of strings. Each string is one
//   of the arguments passed to the program.
/// @param infile
/// @return
bool enterProgram(int argc, char **argv, std::ifstream &infile) {
    std::ofstream outfile("revSorted.txt", std::ios_base::out);
    std::list<DictEntry> dictionary;
    std::list<DictEntry> toSearch;
    wordType dictEntries;

    unsigned int choice;
    do {

        unsigned int subMenuChoice;
        choice = mainMenu();
        switch (choice) {
            case 1:
                subMenuChoice = sub_Menu();
                sub_Menu_Switch(subMenuChoice, argc, argv, infile, dictionary, toSearch);
                break;
            case 2:
                dictionary.sort();
                std::cout << "Sorted!" << std::endl;
                toConsole(dictionary);
                break;
            case 3:
                toConsole(dictionary);
                break;
            case 4:
                subMenuChoice = search_Sub_Menu();
                search_Sub_Menu_Switch(subMenuChoice, dictionary, toSearch);
                break;
            case 5:
                Dictionary::revPrintList(outfile, dictionary);
                break;
            case 6:
                exitProgram();
            default:
                break;
        }
    } while (choice != 6);
    return false;
}///# enterProgram

