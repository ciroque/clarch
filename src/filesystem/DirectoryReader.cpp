//
// Created by Steve on 5/4/2018.
//

#include <experimental/filesystem>
#include "DirectoryReader.h"
#include "FileReader.h"

namespace fs = std::experimental::filesystem;

void DirectoryReader::processDirectory(Args &args, Scanner *scanner, std::vector<ModuleStats> &moduleStats) {
    std::map<std::string, bool > excludeList = { {"_build", true}, {"deps", true}, {".git", true}};

    fs::path rootPath = args.getArg("path");

    fs::recursive_directory_iterator iterator(rootPath);

    for(decltype(iterator) end; iterator != end; iterator++) {

        fs::directory_entry p = *iterator;

        if(fs::is_directory(p.path())) {
            std::string filename = p.path().filename().generic_u8string();
            bool excluded = excludeList.count(filename) > 0;
            if(excluded) {
                iterator.disable_recursion_pending();
            }

        } else {
            if(p.path().extension() == ".ex") {
                ModuleStats fs = FileReader::processFile(p.path().generic_u8string(), scanner);
                moduleStats.push_back(fs);
            }
      }
    }
}
