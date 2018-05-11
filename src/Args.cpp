//
// Created by Steve Wagner on 4/30/18.
//

#include <iostream>
#include "Args.h"

Args::Args(int argc, char **argv) {
    while(argc--) {
        ParseArg(*argv++);
    }
}

void Args::ParseArg(std::string arg) {
    size_t pos = arg.find("=");
    std::string key = arg.substr(0, pos);
    std::string value = arg.substr(pos + 1);
    m_args[key] = value;
}

void Args::PrintAll() {
    for(auto& arg : m_args) {
        std::cout << arg.first << " :: " << arg.second << "\n";
    }
}

std::string Args::GetArg(std::string key) {
    return m_args[key];
}
