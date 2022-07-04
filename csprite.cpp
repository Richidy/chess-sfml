/*
====================================
====================================
====================================
               Sprites
====================================
====================================
====================================

- has a texture
- has a sprite

*/
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class csprite
{
public:
    Sprite sprite;

    vector<csprite>* active_sprites;

    csprite(string, vector<csprite>& sprites_vector, const Texture& t);
    void activate();
    void deactivate();
};

csprite::csprite(string n, vector<csprite>& sprites_vector, const Texture& t)
{
    active_sprites = &sprites_vector;
    sprite.setTexture(t);
}

void csprite::activate()
{
    active_sprites->push_back(*this);
}