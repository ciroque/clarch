//
// Created by Steve on 5/4/2018.
//

#include <fstream>
#include "JsonRenderer.h"

void JsonRenderer::render(std::string file, std::vector<FileStats> fileStats) {
    std::ofstream output(file);

    output << "[";

//    for(auto const &fs: fileStats) {
    ;
    for(
        auto it = fileStats.begin(), end = fileStats.end();
        it != end;
        it++
    ) {
        FileStats fs = *it;
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
