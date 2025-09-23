#ifndef SPRITE_H
#define SPRITE_H

#include "scratchobject.h"

class Sprite : public ScratchObject
{
private:
    short pinSprite;
public:
    Sprite(bool objActive);
    Sprite(bool objActive, short objPin);
    Sprite(SPRITE_TYPE objSpriteType);

    virtual ~Sprite();

    void activate() override;
    void deactivate() override;
    void toggle() override;
    String getStatus() const override;
};

#endif // LIGHTSWITCH_H
