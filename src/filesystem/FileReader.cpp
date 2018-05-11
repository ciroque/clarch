//
// Created by Steve Wagner on 5/1/18.
//

#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "../scanners/Scanner.h"

ModuleStats FileReader::ProcessFile(std::string path, Scanner *scanner) {
    std::ifstream input(path);
    std::string token;
    std::string value;

    ModuleStats stats(path);
    while(input >> token) {
        if(scanner->TokenOfInterest(token)) {
            std::getline(input, value);
            scanner->HandleToken(token, value, stats);
        }
    }

    input.close();

    return stats;
}
