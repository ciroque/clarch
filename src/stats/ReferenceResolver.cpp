//
// Created by Steve on 5/11/2018.
//

#include <iostream>
#include "ReferenceResolver.h"

ModuleStatsList &ReferenceResolver::ResolveReferenced(ModuleStatsList &stats) {
    BuildModuleMap(stats);
    return stats;
}

const ModuleMap ReferenceResolver::BuildModuleMap(ModuleStatsList &stats) {
    ModuleMap map;
    for(ModuleStats stat : stats) {
        std::cout << "... " << stat.GetModule() << "\r\n";
    }
    return map;
}
