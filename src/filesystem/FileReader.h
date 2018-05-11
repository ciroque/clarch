//
// Created by Steve Wagner on 5/1/18.
//

#ifndef CLARCH_FILEREADER_H
#define CLARCH_FILEREADER_H


#include <string>
#include "../stats/ModuleStats.h"
#include "../scanners/Scanner.h"

class FileReader {
public:
    static ModuleStats ProcessFile(std::string, Scanner *scanner);

private:
    Scanner *m_scanner;
};


#endif //CLARCH_FILEREADER_H
