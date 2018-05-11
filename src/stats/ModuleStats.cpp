//
// Created by Steve Wagner on 5/1/18.
//

#include "ModuleStats.h"
#include <utility>
#include <iostream>

ModuleState::ModuleState(std::string filename) {
    m_filename = std::move(filename);
}

void ModuleState::setNamespace(std::string ns) {
    m_namespace = std::move(ns);
}

void ModuleState::setModule(std::string module) {
    m_module = std::move(module);
}

void ModuleState::addReference(std::string reference) {
    m_references.push_back(reference);
}

void ModuleState::setValue(ModuleStatsKeys key, const std::string &value) {
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

std::string ModuleState::getFilename() {
    return m_filename;
}

std::string ModuleState::getModule() {
    return m_module;
}

std::string ModuleState::getNamespace() {
    return m_namespace;
}

std::vector<std::string> ModuleState::getReferences() {
    return m_references;
}
