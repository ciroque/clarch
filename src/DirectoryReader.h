//
// Created by Steve on 5/4/2018.
//

#ifndef CLARCH_DIRECTORYREADER_H
#define CLARCH_DIRECTORYREADER_H


#include "Args.h"
#include "scanners/Scanner.h"

class DirectoryReader {
public:
    static void processDirectory(Args&, Scanner*, std::vector<FileStats>&);
};


#endif //CLARCH_DIRECTORYREADER_H
