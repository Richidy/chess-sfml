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
    inline static int id_counter;

    int id;
    Sprite sprite;

    vector<csprite>* active_sprites;

    csprite(string n, vector<csprite>& sprites_vector, const Texture& t);
    void activate();
    void deactivate();
};

csprite::csprite(string n, vector<csprite>& sprites_vector, const Texture& t)
{
    id = id_counter;
    id_counter++;

    active_sprites = &sprites_vector;
    sprite.setTexture(t);
}

void csprite::activate()
{
    active_sprites->push_back(*this);
}

void csprite::deactivate()
{
    for(int i = 0; i < active_sprites->size(); i++){
        if(active_sprites->at(i).id == id){
            active_sprites->erase(active_sprites->begin() + i);
            break;
        }
    }
}