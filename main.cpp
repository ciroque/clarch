#include <iostream>
#include <filesystem>

#include "./src/Args.h"
#include "src/FileReader.h"
#include "src/scanners/elixir/ElixirScanner.h"
#include "src/DirectoryReader.h"

using namespace std::experimental::filesystem::v1;

int main(int argc, char **argv) {
    ArgsMap map;

    auto *args = new Args(argc, argv);

    auto elixirScanner = new ElixirScanner();

    auto fileStats = FileReader::processFile(args->getArg("path"), elixirScanner);
    std::cout << fileStats->getFilename() << "\r\n" << fileStats->getModule() << "\r\n" << fileStats->getNamespace();

    std::vector<std::string> references = fileStats->getReferences();
    std::vector<std::string>::iterator it;
    for(it = references.begin(); it != references.end(); it++) {
        std::cout << "> " << *it << "\r\n";
    }

    std::vector<FileStats*> allStats;
    DirectoryReader::processDirectory(args, elixirScanner, &allStats);

    delete args;
    delete fileStats;

    return 0;
}