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
    static void Render(std::string, std::vector<ModuleStats>);

private:
    static void RenderModuleStats(std::ofstream&, ModuleStats&);
    static void JsonRenderer::RenderReferences(std::ofstream&, std::string, std::vector<std::string>);
};


#endif //CLARCH_JSONRENDERER_H
