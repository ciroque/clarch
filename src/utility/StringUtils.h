//
// Created by Steve Wagner on 5/1/18.
//
// Lifted from: https://stackoverflow.com/questions/479080/trim-is-not-part-of-the-standard-c-c-library
//

#ifndef CLARCH_STRINGUTILS_H
#define CLARCH_STRINGUTILS_H


#include <string>

class StringUtils {
private:
    static const std::string whiteSpaces;

public:
    static void TrimRight(std::string &, const std::string &trimChars = whiteSpaces);
    static void TrimLeft(std::string &str, const std::string &trimChars = whiteSpaces);
    static void Trim(std::string &str, const std::string &trimChars = whiteSpaces);

    static std::string SubstringBefore(std::string, std::string);
};


#endif //CLARCH_STRINGUTILS_H
