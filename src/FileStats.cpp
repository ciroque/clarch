//
// Created by Steve Wagner on 5/1/18.
//

#include "FileStats.h"
#include <utility>
#include <iostream>

FileStats::FileStats(std::string filename) {
    m_filename = std::move(filename);
}

void FileStats::setNamespace(std::string ns) {
    m_namespace = std::move(ns);
}

void FileStats::setModule(std::string module) {
    m_module = std::move(module);
}

void FileStats::addReference(std::string reference) {
    m_references.push_back(reference);
}

void FileStats::setValue(FileStatsKeys key, const std::string &value) {
    switch(key) {
        case FileStatsKeys::Module: {
            setModule(value);
            break;
        }

        case FileStatsKeys::Namespace: {
            setNamespace(value);
            break;
        }

        case FileStatsKeys ::Reference: {
            addReference(value);
            break;
        }

        default: {
            std::cerr << "Unknown FileStatsKey: " << key;
        }
    }
}

std::string FileStats::getFilename() {
    return m_filename;
}

std::string FileStats::getModule() {
    return m_module;
}

std::string FileStats::getNamespace() {
    return m_namespace;
}

std::vector<std::string> FileStats::getReferences() {
    return m_references;
}
