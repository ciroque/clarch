//
// Created by Steve on 5/11/2018.
//

#include <iostream>
#include "ReferenceResolver.h"

ModuleStatsList &ReferenceResolver::ResolveReferenced(ModuleStatsList &stats) {
    ModuleMap moduleMap;
    PopulateModuleMap(stats, moduleMap);
    std::cout << "Map Count: " << moduleMap.size() << "\n";
    return stats;
}

ModuleMap &ReferenceResolver::PopulateModuleMap(ModuleStatsList &stats, ModuleMap &map) {
    for(ModuleStats stat : stats) {
        map[stat.GetModule()] = &stat;
    }
    return map;
}
