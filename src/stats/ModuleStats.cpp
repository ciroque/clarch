//
// Created by Steve Wagner on 5/1/18.
//

#include "ModuleStats.h"
#include <utility>
#include <iostream>

ModuleStats::ModuleStats(std::string filename) {
    m_filename = std::move(filename);
}

void ModuleStats::SetNamespace(std::string ns) {
    m_namespace = std::move(ns);
}

void ModuleStats::SetModule(std::string module) {
    m_module = std::move(module);
}

void ModuleStats::AddReference(std::string reference) {
    m_references.push_back(reference);
}

void ModuleStats::SetValue(ModuleStatsKeys key, const std::string &value) {
    switch(key) {
        case ModuleStatsKeys::Module: {
            SetModule(value);
            break;
        }

        case ModuleStatsKeys::Namespace: {
            SetNamespace(value);
            break;
        }

        case ModuleStatsKeys ::Reference: {
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
