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

    std::string GetArg(std::string);
    void PrintAll();

private:
    ArgsMap m_args;
    void ParseArg(std::string);
};

#endif //CLARCH_ARGS_H
