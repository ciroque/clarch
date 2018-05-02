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

    // TODO: Refactor this whole method, removing commas should happen
    // AFTER the disentanglement step...
//    index = value.find(',');
//    if(index != std::string::npos) {
//        value = value.substr(0, index);
//    }

    return value;
}

std::vector<std::string> ElixirScanner::disentangleMultiAliases(std::string value) {
    // TODO: Handle nefarious constructs such as "alias Scooter.Sov.{FinalSpendDetail, FinalSpendsPeriod, Spend}"

    std::vector<std::string> aliases;

    unsigned long index = value.find('{');
    if(index != std::string::npos) {
        std::string prefix = value.substr(0, index);

        std::cout << "\r\n!! value >> " << value << "\r\n";

        std::string multis = value.substr(index + 1, (value.length() - (index + 2)));

        std::cout << "\r\n!! prefix >> " << prefix << "\r\n";
        std::cout << "\r\n!! multis >> " << multis << "\r\n";

        aliases.push_back(prefix);
        aliases.push_back(multis);

    } else {
        aliases.push_back(value);
    }

    return aliases;
}
