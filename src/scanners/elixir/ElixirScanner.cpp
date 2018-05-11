//
// Created by Steve Wagner on 5/1/18.
//

#include <sstream>
#include "ElixirScanner.h"
#include "../../utility/StringUtils.h"

bool ElixirScanner::tokenOfInterest(std::string token) {
    return m_mappings.count(token) > 0;
}

ModuleState ElixirScanner::handleToken(std::string token, std::string value, ModuleState stats) {
    value = StringUtils::substrBefore(value, " do");

    auto values = disentangleMultiAliases(value);

    std::string cleaned;

    std::vector<std::string>::iterator it;
    for( it = values.begin(); it != values.end(); it++) {
        cleaned = StringUtils::substrBefore(*it, ",");
        stats.setValue(m_mappings.at(token), cleaned);
    }

    return stats;
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
