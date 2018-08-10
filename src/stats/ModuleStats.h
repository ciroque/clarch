//
// Created by Steve Wagner on 5/1/18.
//

#ifndef CLARCH_MODULESTATS_H
#define CLARCH_MODULESTATS_H

#include <string>
#include <vector>

class ModuleStats;

typedef std::vector<ModuleStats> ModuleStatsList;
typedef std::vector<std::string> StringList;

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
    void AddReferencedBy(std::string);

    std::string GetFilename();
    std::string GetModule();
    std::string GetNamespace();
    std::vector<std::string> GetReferences();
    std::vector<std::string> GetReferencedBy();

    int GetIncomingConnectionCount();
    int GetOutgoingConnectionCount();
    float GetInstability();

    std::string ToString();

private:
    std::string m_namespace;
    std::string m_module;
    std::string m_filename;
    StringList m_references;
    StringList m_referencedBy;
};


#endif //CLARCH_MODULESTATS_H
