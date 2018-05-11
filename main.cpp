#include <iostream>

#include "./src/Args.h"
#include "src/filesystem/FileReader.h"
#include "src/scanners/elixir/ElixirScanner.h"
#include "src/filesystem/DirectoryReader.h"
#include "src/renderers/JsonRenderer.h"

int main(int argc, char **argv) {
    Args args(argc, argv);
    auto elixirScanner = new ElixirScanner();

    ModuleStatsList stats;
    DirectoryReader::processDirectory(args, elixirScanner, stats);

    JsonRenderer::render("output.json", stats);

    return 0;
}
