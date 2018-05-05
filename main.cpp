#include <iostream>

#include "./src/Args.h"
#include "src/FileReader.h"
#include "src/scanners/elixir/ElixirScanner.h"
#include "src/DirectoryReader.h"

int main(int argc, char **argv) {
    ArgsMap map;

    auto *args = new Args(argc, argv);

    auto elixirScanner = new ElixirScanner();

//    auto fileStats = FileReader::processFile(args->getArg("path"), elixirScanner);
//    std::cout << fileStats->getFilename() << "\r\n" << fileStats->getModule() << "\r\n" << fileStats->getNamespace();
//    std::vector<std::string> references = fileStats->getReferences();
//    std::vector<std::string>::iterator it;
//    for(it = references.begin(); it != references.end(); it++) {
//        std::cout << "> " << *it << "\r\n";
//    }
//    delete fileStats;

    std::vector<FileStats*> allStats;
    DirectoryReader::processDirectory(args, elixirScanner, &allStats);

    delete args;

    return 0;
}
