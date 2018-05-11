//
// Created by Steve on 5/11/2018.
//

#ifndef CLARCH_REFERENCERESOLVER_H
#define CLARCH_REFERENCERESOLVER_H


#include <map>
#include "ModuleStats.h"

typedef std::map<std::string, ModuleStats*> ModuleMap;

class ReferenceResolver {
public:
    static ModuleStatsList &ResolveReferenced(ModuleStatsList&);

private:
    static ModuleMap &PopulateModuleMap(ModuleStatsList&, ModuleMap&);
};


#endif //CLARCH_REFERENCERESOLVER_H
