#include <iostream>

#include "./src/Args.h"
#include "src/filesystem/FileReader.h"
#include "src/scanners/elixir/ElixirScanner.h"
#include "src/filesystem/DirectoryReader.h"
#include "src/renderers/JsonRenderer.h"
#include "src/stats/ReferenceResolver.h"

int main(int argc, char **argv) {
    Args args(argc, argv);
    auto elixirScanner = new ElixirScanner();

    ModuleStatsList stats;
    DirectoryReader::ProcessDirectory(args, elixirScanner, stats);
    ReferenceResolver::ResolveReferenced(stats);
    JsonRenderer::Render("output.json", stats);

    for(auto &stat : stats) {
        std::cout << stat.ToString() << "\n\n";
    }

    return 0;
}
