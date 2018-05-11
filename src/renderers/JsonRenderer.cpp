//
// Created by Steve on 5/4/2018.
//

#include <fstream>
#include "JsonRenderer.h"

void JsonRenderer::render(std::string file, std::vector<ModuleState> moduleStats) {
    std::ofstream output(file);

    output << "[";

    for(
        auto it = moduleStats.begin(), end = moduleStats.end();
        it != end;
        it++
    ) {
        ModuleState fs = *it;
        output << "{";

        output << "\"filename\":\"" << fs.getFilename() << "\"";

        output << "}";

        if(it != end) {
            output << ",";
        }
    }

    output << "]";

    output.close();
}
