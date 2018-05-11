#include <iostream>
#include <list>

#include "./src/Args.h"
#include "src/filesystem/FileReader.h"
#include "src/scanners/elixir/ElixirScanner.h"
#include "src/filesystem/DirectoryReader.h"
#include "src/renderers/JsonRenderer.h"
#include "src/stats/ReferenceResolver.h"

void PrintSortedModules(ModuleStatsList &stats) {
    std::list<std::string> things;
    for(auto &stat : stats) {
        things.push_back(stat.GetModule());
    }
    things.sort();

    for(auto &thing : things) {
        std::cout << thing << "\n";
    }
}

void PrintAllStats(ModuleStatsList &stats) {
    for(auto &stat : stats) {
        std::cout << stat.ToString() << "\n\n";
    }
}

int main(int argc, char **argv) {
    Args args(argc, argv);
    auto elixirScanner = new ElixirScanner();

    ModuleStatsList stats;
    DirectoryReader::ProcessDirectory(args, elixirScanner, stats);
    ReferenceResolver::ResolveReferenced(stats);
    JsonRenderer::Render("output.json", stats);

//    PrintSortedModules(stats);

    PrintAllStats(stats);

    return 0;
}

