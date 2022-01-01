#include "includes.h"

class LevelInfoLayerMod : public LevelInfoLayer {
public:
    CCAction* onPlay(CCObject* target);

    static void init() {
        add_hook<&LevelInfoLayerMod::onPlay>(base + 0x179730);
    }
};

