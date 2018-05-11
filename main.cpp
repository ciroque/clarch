#include <iostream>

#include "./src/Args.h"
#include "src/filesystem/FileReader.h"
#include "src/scanners/elixir/ElixirScanner.h"
#include "src/filesystem/DirectoryReader.h"
#include "src/renderers/JsonRenderer.h"

int main(int argc, char **argv) {
    Args args(argc, argv);
    auto elixirScanner = new ElixirScanner();

    std::vector<ModuleState> allStats;
    DirectoryReader::processDirectory(args, elixirScanner, allStats);

    JsonRenderer::render("output.json", allStats);

    return 0;
}
