#include "DictEntry.h"
#include "Dictionary.h"
#include "Functions.h"
//std::list<DictEntry> dictionary;
//std::list<DictEntry> toSearch;
//wordType dictEntries;
int main(int argc, char **argv) {
    try {
        std::cin.exceptions(std::istream::failbit);
        std::ifstream infile;
        enterProgram(argc, argv, infile);
    } catch (const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
        unknownInput();
    }
}