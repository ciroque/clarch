//
// Created by Steve Wagner on 5/1/18.
//

#include "ModuleStats.h"
#include <utility>
#include <iostream>

ModuleStats::ModuleStats(std::string filename) {
    m_filename = std::move(filename);
}

void ModuleStats::AddReference(std::string reference) {
    try {
        m_references.push_back(reference);
    } catch(std::exception &ex) {
        std::cerr << ex.what() << "\n";
    }
}

void ModuleStats::AddReferencedBy(std::string referencedBy) {
    try {
        m_referencedBy.push_back(referencedBy);
    } catch(std::exception &ex) {
        std::cerr << ex.what() << "\n";
    }
}

void ModuleStats::SetValue(ModuleStatsKeys key, const std::string &value) {
    switch(key) {
        case ModuleStatsKeys::Module: {
            m_module = value;
            break;
        }

        case ModuleStatsKeys::Namespace: {
            m_namespace = value;
            break;
        }

        case ModuleStatsKeys ::Reference: {
//            m_references.push_back(value);
            AddReference(value);
            break;
        }

        default: {
            std::cerr << "Unknown ModuleStatsKey: " << key;
        }
    }
}

std::string ModuleStats::GetFilename() {
    return m_filename;
}

std::string ModuleStats::GetModule() {
    return m_module;
}

std::string ModuleStats::GetNamespace() {
    return m_namespace;
}

std::vector<std::string> ModuleStats::GetReferences() {
    return m_references;
}

std::string ModuleStats::ToString() {
    std::string moduleStats = "\n-----\nModuleStats instance\n\n";

    moduleStats += "Filename: " + m_filename;
    moduleStats += "\nModule: " + m_module;
    moduleStats += "\nNamespace: " + m_namespace;

    moduleStats += "\nReferences: ";
    for(const auto &ref : m_references) {
        moduleStats += "\n\t-- " + ref;
    }

    moduleStats += "\nReferenced By: ";
    for(const auto &ref : m_referencedBy) {
        moduleStats += "\n\t-- " + ref;
    }

    return moduleStats;
}
