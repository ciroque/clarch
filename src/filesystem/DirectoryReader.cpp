//
// Created by Steve on 5/4/2018.
//

#include <experimental/filesystem>
#include "DirectoryReader.h"
#include "FileReader.h"

namespace fs = std::experimental::filesystem;

void DirectoryReader::ProcessDirectory(Args &args, Scanner *scanner, std::vector<ModuleStats> &moduleStats) {
    fs::path rootPath = args.GetArg("path");
    fs::recursive_directory_iterator iterator(rootPath);

    for(decltype(iterator) end; iterator != end; iterator++) {
        fs::directory_entry p = *iterator;
        if(fs::is_directory(p.path())) {
            std::string filename = p.path().filename().generic_u8string();
            if(scanner->ExcludePath(filename)) {
                iterator.disable_recursion_pending();
            }

        } else {
            if(scanner->FileExtensionOfInterest(p.path().extension().generic_u8string())) {
                ModuleStats fs = FileReader::ProcessFile(p.path().generic_u8string(), scanner);
                moduleStats.push_back(fs);
            }
      }
    }
}
