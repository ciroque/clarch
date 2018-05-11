//
// Created by Steve on 5/4/2018.
//

#ifndef CLARCH_JSONRENDERER_H
#define CLARCH_JSONRENDERER_H


#include <string>
#include "../FileStats.h"

class JsonRenderer {
public:
    static void render(std::string filename, std::vector<FileStats>);
};


#endif //CLARCH_JSONRENDERER_H
