//
// Created by Steve Wagner on 5/1/18.
//

#ifndef CLARCH_SCANNER_H
#define CLARCH_SCANNER_H

#include <string>
#include <iostream>
#include "../FileStats.h"

class Scanner {
public:
    Scanner() = default;

    virtual bool tokenOfInterest(std::string) = 0;
    virtual FileStats handleToken(std::string token, std::string value, FileStats stats) = 0;

    std::string trim(std::string input) {
        return input;
    }
};



#endif //CLARCH_SCANNER_H
