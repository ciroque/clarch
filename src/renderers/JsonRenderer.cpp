//
// Created by Steve on 5/4/2018.
//

#include <fstream>
#include "JsonRenderer.h"

void JsonRenderer::Render(std::string file, ModuleStatsList moduleStats) {
    std::ofstream output(file);

    output << "[";

    auto item = moduleStats.begin();
    for(
        auto end = --moduleStats.end();
        item != end;
        ++item
    ) {
        ModuleStats fs = *item;
        JsonRenderer::RenderModuleStats(output, fs);
        output << ", ";
    }

    ModuleStats fs = *(--moduleStats.end());
    JsonRenderer::RenderModuleStats(output, fs);

    output << "]";

    output.close();
}

void JsonRenderer::RenderModuleStats(std::ofstream& output, ModuleStats& moduleStats) {
    output << "{";

    output << R"("filename": ")" << moduleStats.GetFilename() << "\",";
    output << R"("modulename": ")" << moduleStats.GetModule() << "\",";
    output << R"("namespace": ")" << moduleStats.GetNamespace() << "\",";
    output << R"("references": [])";
    output << "}";
}
