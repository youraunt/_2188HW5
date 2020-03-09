//
// Created by BK Allen on 3/5/20.
// File provided
//

#ifndef _2188HW5_DICTENTRY_H
#define _2188HW5_DICTENTRY_H

#include <string>
#include <utility>

typedef std::string wordType;

class DictEntry {
private:
     wordType word;

public:
    wordType getWord() { return word; }

    void setWord(wordType _word) { word = std::move(_word); }

    bool operator<(const DictEntry &entry) const { return (word < entry.word); }

};

#endif //_2188HW5_DICTENTRY_H
