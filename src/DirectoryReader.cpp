//
// Created by Steve on 5/4/2018.
//

#include <filesystem>
#include "DirectoryReader.h"

namespace fs = std::experimental::filesystem;

void DirectoryReader::processDirectory(Args *args, Scanner *scanner, std::vector<FileStats*> *fileStats) {
    for(auto& p: fs::recursive_directory_iterator(args->getArg("path"))) {
        if(p.is_directory() && p.path().filename() == "deps") {
            continue;
        }

        if(p.path().has_extension()) {
            if(p.path().extension() == ".ex") {
//                std::cout << p.path().filename() << "\r\n";
                fileStats->push_back(new FileStats(p.path().string()));
            }
        }
    }
}
