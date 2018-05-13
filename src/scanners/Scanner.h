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

    virtual bool ExcludePath(std::string path) = 0;
    virtual bool FileExtensionOfInterest(std::string) = 0;
    virtual ModuleStats HandleToken(std::string token, std::string value, ModuleStats &stats) = 0;
    virtual bool TokenOfInterest(std::string) = 0;
};

#endif //CLARCH_SCANNER_H
