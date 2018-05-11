//
// Created by Steve Wagner on 5/1/18.
//
// Lifted from: https://stackoverflow.com/questions/479080/trim-is-not-part-of-the-standard-c-c-library
//

#include <iostream>
#include "StringUtils.h"

const std::string StringUtils::whiteSpaces = " \f\n\r\t\v";

void StringUtils::TrimRight(std::string &str, const std::string &trimChars) {
    std::string::size_type pos = str.find_last_not_of(trimChars);
    str.erase(pos + 1);
}

void StringUtils::TrimLeft(std::string &str, const std::string &trimChars) {
    std::string::size_type pos = str.find_first_not_of(trimChars);
    str.erase(0, pos);
}

void StringUtils::Trim(std::string &str, const std::string &trimChars) {
    TrimRight(str, trimChars);
    TrimLeft(str, trimChars);
}

std::string StringUtils::SubstringBefore(std::string str, std::string find) {
    std::string output;
    unsigned long index = str.find(find);
    if(index != std::string::npos) {
        output = str.substr(0, index);
    } else {
        output = str;
    }
    return output;
}
