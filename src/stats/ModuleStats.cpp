//
// Created by Steve Wagner on 5/1/18.
//

#include "ModuleStats.h"
#include <utility>
#include <iostream>

ModuleStats::ModuleStats(std::string filename) {
    m_filename = std::move(filename);
}

void ModuleStats::setNamespace(std::string ns) {
    m_namespace = std::move(ns);
}

void ModuleStats::setModule(std::string module) {
    m_module = std::move(module);
}

void ModuleStats::addReference(std::string reference) {
    m_references.push_back(reference);
}

void ModuleStats::setValue(ModuleStatsKeys key, const std::string &value) {
    switch(key) {
        case ModuleStatsKeys::Module: {
            setModule(value);
            break;
        }

        case ModuleStatsKeys::Namespace: {
            setNamespace(value);
            break;
        }

        case ModuleStatsKeys ::Reference: {
            addReference(value);
            break;
        }

        default: {
            std::cerr << "Unknown ModuleStatsKey: " << key;
        }
    }
}

std::string ModuleStats::getFilename() {
    return m_filename;
}

std::string ModuleStats::getModule() {
    return m_module;
}

std::string ModuleStats::getNamespace() {
    return m_namespace;
}

std::vector<std::string> ModuleStats::getReferences() {
    return m_references;
}
