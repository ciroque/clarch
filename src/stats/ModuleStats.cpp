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
        std::cerr << ex.what() << "\r\n";
    }
}

void ModuleStats::AddReferencedBy(std::string referencedBy) {
    try {
        m_referencedBy.push_back(referencedBy);
    } catch(std::exception &ex) {
        std::cerr << ex.what() << "\r\n";
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

std::vector<std::string> ModuleStats::GetReferencedBy() {
    return m_referencedBy;
}

std::string ModuleStats::ToString() {
    std::string moduleStats = "-----\nModuleStats instance\n\n";

    moduleStats += "Filename: " + m_filename;
    moduleStats += "\nModule: " + m_module;
    moduleStats += "\nNamespace: " + m_namespace;

    moduleStats += "\nReferences: ";
    for(const auto &ref : m_references) {
        moduleStats += "\n\t-- " + ref;
    }

    moduleStats += "\r\nReferenced By: ";
    for(const auto &ref : m_referencedBy) {
        moduleStats += "\n\t-- " + ref;
    }

    moduleStats += "\nIncoming Reference Count: " + std::to_string(GetIncomingConnectionCount());
    moduleStats += "\nOutgoing Reference Count: " + std::to_string(GetOutgoingConnectionCount());
    moduleStats += "\nInstability: " + std::to_string(GetInstability());
    return moduleStats;
}

int ModuleStats::GetIncomingConnectionCount() {
    return m_referencedBy.size();
}

int ModuleStats::GetOutgoingConnectionCount() {
    return m_references.size();
}

float ModuleStats::GetInstability() {
    int fanIn = GetIncomingConnectionCount();
    int fanOut = GetOutgoingConnectionCount();
    return (fanIn == 0 && fanOut == 0) ? 0 : ((float)fanOut / (fanIn + fanOut));
}
