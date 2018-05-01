//
// Created by Steve Wagner on 5/1/18.
//

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

    return value;
}

std::vector<std::string> ElixirScanner::disentangleMultiAliases(std::string value) {
    // TODO: Handle nefarious constructs such as "alias Scooter.Sov.{FinalSpendDetail, FinalSpendsPeriod, Spend}"
    std::vector<std::string> aliases = { value };
    return aliases;
}
