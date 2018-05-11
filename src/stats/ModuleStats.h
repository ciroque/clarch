//
// Created by Steve Wagner on 5/1/18.
//

#ifndef CLARCH_MODULESTATS_H
#define CLARCH_MODULESTATS_H

#include <string>
#include <vector>

class ModuleStats;

typedef std::vector<ModuleStats> ModuleStatsList;

enum ModuleStatsKeys : int {
    Namespace = 1,
    Module,
    Reference
};

class ModuleStats {
public:
    explicit ModuleStats(std::string filename);

    void SetValue(ModuleStatsKeys key, const std::string &value);

    void AddReference(std::string);

    std::string GetFilename();
    std::string GetModule();
    std::string GetNamespace();
    std::vector<std::string> GetReferences();

    std::string ToString();

private:
    std::string m_namespace;
    std::string m_module;
    std::string m_filename;
    std::vector<std::string> m_references;
};


#endif //CLARCH_MODULESTATS_H
