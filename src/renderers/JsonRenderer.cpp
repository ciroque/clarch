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
    output << R"("incomingConnectionCount": )" << moduleStats.GetIncomingConnectionCount() << ",";
    output << R"("outgoingConnectionCount": )" << moduleStats.GetOutgoingConnectionCount() << ",";
    output << R"("instability": )" << moduleStats.GetInstability() << ",";
    JsonRenderer::RenderReferences(output, "references", moduleStats.GetReferences());
    output << ",";
    JsonRenderer::RenderReferences(output, "referencedBy", moduleStats.GetReferencedBy());
    output << "}";
}

void JsonRenderer::RenderReferences(std::ofstream& output, std::string key, std::vector<std::string> references) {
    output << R"(")" << key << R"(": [)";
    if(!references.empty()) {
        auto item = references.begin();
        for(auto end = --references.end(); item != end; ++item) {
            std::string reference = *item;
            output << R"(")" << reference << R"(",)";
        }
        std::string reference = *(--references.end());
        output << R"(")" << reference << R"(")";
    }
    output << R"(])";
}
