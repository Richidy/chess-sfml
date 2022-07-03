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

    Texture texture;
    Sprite sprite;

    vector<csprite>* active_sprites;

    csprite(string, vector<csprite>& sprites_vector);
    void activate();
    void deactivate();
};

csprite::csprite(string n, vector<csprite>& sprites_vector)
{
    if(!texture.loadFromFile(n))
    {
        cout << "error texture not loaded";
    }

    active_sprites = &sprites_vector;
    sprite = Sprite(texture);
}

void csprite::activate()
{
    active_sprites->push_back(*this);
}