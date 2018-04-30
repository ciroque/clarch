//
// Created by Steve Wagner on 4/30/18.
//

#ifndef CLARCH_ARGS_H
#define CLARCH_ARGS_H

#include <map>
#include <string>

typedef std::map<std::string, std::string> ArgsMap;

class Args {
public:
    Args(int argc, char **argv);

    std::string getArg(std::string);
    void printAll();

private:
    ArgsMap m_args;
    void parseArg(std::string);
};

#endif //CLARCH_ARGS_H
