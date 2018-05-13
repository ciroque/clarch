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
    bool ExcludePath(std::string path) override;
    bool FileExtensionOfInterest(std::string) override;
    ModuleStats HandleToken(std::string token, std::string value, ModuleStats &stats) override;
    bool TokenOfInterest(std::string) override;

private:
    std::map<std::string, bool> excludedDirectories = {
            {"_build", true},
            {"deps", true},
            {".git", true},
            {"assets", true},
            {"test", true}
    };

    std::map<std::string, bool> fileExtensionsOfInterest = {
            {".ex", true}
    };

    std::map<std::string, ModuleStatsKeys> mappings = {
            {"alias", ModuleStatsKeys::Reference},
            {"@behaviour", ModuleStatsKeys::Reference},
            {"defmodule", ModuleStatsKeys::Module},
            {"import", ModuleStatsKeys::Reference},
            {"require", ModuleStatsKeys::Reference},
            {"use", ModuleStatsKeys::Reference}
    };

    std::vector<std::string> DisentangleMultiAliases(std::string);
};

#endif //CLARCH_ELIXIRSCANNER_H
