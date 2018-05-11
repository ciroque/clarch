//
// Created by Steve on 5/11/2018.
//

#ifndef CLARCH_RENDERER_H
#define CLARCH_RENDERER_H

#include <string>
#include "../stats/ModuleStats.h"

class Renderer {
public:
    // TODO: Instead of a string, how about a device...?
    virtual void Render(std::string, std::vector<ModuleStats>) = 0;
};

#endif //CLARCH_RENDERER_H
