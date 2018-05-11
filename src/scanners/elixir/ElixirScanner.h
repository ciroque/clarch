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
    FileStats handleToken(std::string token, std::string value, FileStats stats) override;

private:
    std::map<std::string, FileStatsKeys> m_mappings = {
            {"alias", FileStatsKeys::Reference},
            {"behaviour", FileStatsKeys::Reference},
            {"defmodule", FileStatsKeys::Module},
            {"import", FileStatsKeys::Reference},
            {"require", FileStatsKeys::Reference},
            {"use", FileStatsKeys::Reference}
    };

    std::vector<std::string> disentangleMultiAliases(std::string);
};

#endif //CLARCH_ELIXIRSCANNER_H
