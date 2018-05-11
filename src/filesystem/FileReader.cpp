//
// Created by Steve Wagner on 5/1/18.
//

#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "../scanners/Scanner.h"

ModuleStats FileReader::processFile(std::string path, Scanner *scanner) {
    std::ifstream input(path);
    std::string token;
    std::string value;

//    auto *stats = new ModuleStats(path);
    ModuleStats stats(path);
    while(input >> token) {
        if(scanner->tokenOfInterest(token)) {
            std::getline(input, value);
            scanner->handleToken(token, value, stats);
        }
    }

    input.close();

    return stats;
}
