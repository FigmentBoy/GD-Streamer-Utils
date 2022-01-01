#include "includes.h"
#include <matdash/boilerplate.hpp>
#include <matdash/minhook.hpp>
#include "LevelInfoLayerMod.h"

void mod_main(HMODULE) {
    LevelInfoLayerMod::init();    
}