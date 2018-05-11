//
// Created by Steve Wagner on 5/1/18.
//

#ifndef CLARCH_SCANNER_H
#define CLARCH_SCANNER_H

#include <string>
#include <iostream>
#include "../stats/ModuleStats.h"

class Scanner {
public:
    Scanner() = default;

    virtual bool tokenOfInterest(std::string) = 0;
    virtual ModuleState handleToken(std::string token, std::string value, ModuleState stats) = 0;

    std::string trim(std::string input) {
        return input;
    }
};



#endif //CLARCH_SCANNER_H
