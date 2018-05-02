//
// Created by Steve Wagner on 5/1/18.
//

#include <sstream>
#include "ElixirScanner.h"
#include "../../StringUtils.h"

bool ElixirScanner::tokenOfInterest(std::string token) {
    return m_mappings.count(token) > 0;
}

FileStats *ElixirScanner::handleToken(std::string token, std::string value, FileStats *stats) {
    value = cleanValue(value);

    auto values = disentangleMultiAliases(value);

    std::vector<std::string>::iterator it;
    for( it = values.begin(); it != values.end(); it++) {
        stats->setValue(m_mappings.at(token), *it);
    }

    return stats;
}

std::string ElixirScanner::cleanValue(std::string value) {
    StringUtils::trim(value);
    unsigned long index = value.find(" do");
    if(index + 3 == value.length()) {
        value = value.substr(0, value.length() - 3);
    }

    // TODO: Refactor this whole method, removing commas should happen
    // AFTER the disentanglement step...
//    index = value.find(',');
//    if(index != std::string::npos) {
//        value = value.substr(0, index);
//    }

    return value;
}

std::vector<std::string> ElixirScanner::disentangleMultiAliases(std::string value) {
    std::vector<std::string> references;

    unsigned long index = value.find('{');
    if(index != std::string::npos) {
        std::string prefix = value.substr(0, index);
        std::istringstream multis(value.substr(index + 1, (value.length() - (index + 2))));
        std::string referenced;
        while(getline(multis, referenced, ',')) {
            StringUtils::trim(referenced);
            references.push_back(prefix + referenced);
        }

    } else {
        references.push_back(value);
    }

    return references;
}
