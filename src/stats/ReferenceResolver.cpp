//
// Created by Steve on 5/11/2018.
//

#include <iostream>
#include "ReferenceResolver.h"

ModuleStatsList &ReferenceResolver::ResolveReferenced(ModuleStatsList &stats) {
    ModuleMap moduleMap;
    PopulateModuleMap(stats, moduleMap);
    Resolve(stats, moduleMap);
    return stats;
}

ModuleMap &ReferenceResolver::PopulateModuleMap(ModuleStatsList &stats, ModuleMap &map) {
    for(ModuleStats &stat : stats) {
        map[stat.GetModule()] = &stat;
    }
    return map;
}

ModuleStatsList &ReferenceResolver::Resolve(ModuleStatsList &stats, ModuleMap map) {
    std::string referencedBy;
    for(ModuleStats &stat : stats) {
        referencedBy = stat.GetModule();
        for(std::string reference : stat.GetReferences()) {
            if(map.count(reference) > 0) {
                auto *referenced = map[reference];
                referenced->AddReferencedBy(referencedBy);
            }
        }
    }
    return stats;
}
