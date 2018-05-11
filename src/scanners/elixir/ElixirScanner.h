//
// Created by Steve Wagner on 5/1/18.
//

#ifndef CLARCH_ELIXIRSCANNER_H
#define CLARCH_ELIXIRSCANNER_H

#include <map>
#include "../Scanner.h"

class ElixirScanner : public Scanner {
public:
    ElixirScanner() = default;
    bool tokenOfInterest(std::string) override;
    ModuleState handleToken(std::string token, std::string value, ModuleState stats) override;

private:
    std::map<std::string, ModuleStatsKeys> m_mappings = {
            {"alias", ModuleStatsKeys::Reference},
            {"behaviour", ModuleStatsKeys::Reference},
            {"defmodule", ModuleStatsKeys::Module},
            {"import", ModuleStatsKeys::Reference},
            {"require", ModuleStatsKeys::Reference},
            {"use", ModuleStatsKeys::Reference}
    };

    std::vector<std::string> disentangleMultiAliases(std::string);
};

#endif //CLARCH_ELIXIRSCANNER_H
