#include <iostream>
#include "./src/Args.h"

int main(int argc, char **argv) {
    ArgsMap map;

    auto *args = new Args(argc, argv);

    delete args;
    return 0;
}