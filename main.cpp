#include <iostream>
#include "./src/Args.h"
#include "src/FileReader.h"
#include "src/scanners/elixir/ElixirScanner.h"

int main(int argc, char **argv) {
    ArgsMap map;

    auto *args = new Args(argc, argv);

    auto elixirScanner = new ElixirScanner();

    auto fileStats = FileReader::processFile(args->getArg("path"), elixirScanner);

    delete args;
    delete fileStats;

    return 0;
}