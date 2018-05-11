//
// Created by Steve on 5/4/2018.
//

#include <fstream>
#include "JsonRenderer.h"

void JsonRenderer::render(std::string file, std::vector<ModuleStats> moduleStats) {
    std::ofstream output(file);

    output << "[";

    for(
        auto it = moduleStats.begin(), end = moduleStats.end();
        it != end;
        it++
    ) {
        ModuleStats fs = *it;
        output << "{";

        output << R"("filename":")" << fs.getFilename() << "\"";

        output << "}";

        if(it != end) {
            output << ",";
        }
    }

    output << "]";

    output.close();
}
