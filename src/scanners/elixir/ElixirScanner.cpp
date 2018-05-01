//
// Created by Steve Wagner on 5/1/18.
//

#include "ElixirScanner.h"
#include "../../StringUtils.h"

bool ElixirScanner::tokenOfInterest(std::string token) {
    return m_mappings.count(token) > 0;
}

FileStats *ElixirScanner::handleToken(std::string token, std::string value, FileStats *stats) {
    // TODO: Handle nefarious constructs such as "alias Scooter.Sov.{FinalSpendDetail, FinalSpendsPeriod, Spend}"
    // TODO: Trim values front and back
    StringUtils::trim(value);
    stats->setValue(m_mappings.at(token), value);
    return stats;
}
