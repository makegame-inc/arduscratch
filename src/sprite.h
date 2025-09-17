#ifndef SPRITE_H
#define SPRITE_H

#include "scratchobject.h"

class Sprite : public ScratchObject
{
public:
    Sprite(bool objActive);

    virtual ~Sprite();

    void activate() override;
    void deactivate() override;
    void toggle() override;
    String getStatus() const override;
};

#endif // LIGHTSWITCH_H
