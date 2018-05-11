//
// Created by Steve on 5/11/2018.
//

#ifndef CLARCH_RENDERER_H
#define CLARCH_RENDERER_H

#include <string>
#include "../FileStats.h"

class Renderer {
public:
    virtual void Render(std::string, std::vector<FileStats>) = 0;
};

#endif //CLARCH_RENDERER_H
