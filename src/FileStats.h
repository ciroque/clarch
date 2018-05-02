//
// Created by Steve Wagner on 5/1/18.
//

#ifndef CLARCH_FILESTATS_H
#define CLARCH_FILESTATS_H

#include <string>
#include <vector>

enum FileStatsKeys : int {
    Namespace = 1,
    Module,
    Reference
};

class FileStats {
public:
    explicit FileStats(std::string filename);

    void setValue(FileStatsKeys key, const std::string &value);

    void addReference(std::string);

    std::string getFilename();
    std::string getModule();
    std::string getNamespace();
    std::vector<std::string> getReferences();

    void setModule(std::string);
    void setNamespace(std::string);

private:
    std::string m_namespace;
    std::string m_module;
    std::string m_filename;
    std::vector<std::string> m_references;
};

#endif //CLARCH_FILESTATS_H
