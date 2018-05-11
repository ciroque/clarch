//
// Created by Steve on 5/4/2018.
//

#include <fstream>
#include "JsonRenderer.h"

void JsonRenderer::Render(std::string file, ModuleStatsList moduleStats) {
    std::ofstream output(file);

    output << "[";

    for(
        auto it = moduleStats.begin(), end = moduleStats.end();
        it != end;
        it++
    ) {
        ModuleStats fs = *it;
        output << "{";

        output << R"("filename":")" << fs.GetFilename() << "\"";

        output << "}";

        if(it != end) {
            output << ",";
        }
    }

    output << "]";

    output.close();
}
