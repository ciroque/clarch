#include <iostream>

#include "./src/Args.h"
#include "src/FileReader.h"
#include "src/scanners/elixir/ElixirScanner.h"
#include "src/DirectoryReader.h"
#include "src/renderers/JsonRenderer.h"

int main(int argc, char **argv) {
    Args args(argc, argv);
    auto elixirScanner = new ElixirScanner();

    std::vector<FileStats> allStats;
    DirectoryReader::processDirectory(args, elixirScanner, allStats);

    JsonRenderer::render("output.json", allStats);

    return 0;
}
