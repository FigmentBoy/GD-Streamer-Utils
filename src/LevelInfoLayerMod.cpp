#include "LevelInfoLayerMod.h"
#include <cmath>

class ConfirmLevelStart : public FLAlertLayerProtocol {
private:
    LevelInfoLayerMod* parent;
    CCObject* target;
public:
    void FLAlert_Clicked(gd::FLAlertLayer* layer, bool btn2) override {
        if (btn2) {
            orig<&LevelInfoLayerMod::onPlay>(parent, target);
        };
    }

    ConfirmLevelStart(LevelInfoLayerMod* p, CCObject* t) 
        : parent(p), target(t) {};
};

CCAction* LevelInfoLayerMod::onPlay(CCObject* target) {
    if (m_pLevel->m_nLikes - m_pLevel->m_nDislikes < 0) {
        FLAlertLayer::create(new ConfirmLevelStart(this, target), "Careful!", "No", "Yes", "This level has <cr>" + std::to_string(std::abs(m_pLevel->m_nLikes - m_pLevel->m_nDislikes)) + "</c> dislikes! Do you still want to play it?")
            ->show();
        return nullptr;
    } else {
        return orig<&LevelInfoLayerMod::onPlay>(this, target);
    }
}