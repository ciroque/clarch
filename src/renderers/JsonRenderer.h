//
// Created by Steve on 5/4/2018.
//

#ifndef CLARCH_JSONRENDERER_H
#define CLARCH_JSONRENDERER_H


#include <string>
#include "../stats/ModuleStats.h"
#include "Renderer.h"

class JsonRenderer : public Renderer {
public:
    static void render(std::string filename, std::vector<ModuleStats>);
};


#endif //CLARCH_JSONRENDERER_H
