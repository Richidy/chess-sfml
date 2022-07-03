/*
====================================
====================================
====================================
            Chess Board Class
====================================
====================================
====================================

- has a bunch of pieces
- array of squares
- 

*/

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "csprite.cpp"

using namespace std;
using namespace sf;

class cboard 
{
private:

    int Square[64];
    string boardAddress = "board.png";

public:

    Vector2i getpixelposition(int p);
    csprite boardSprite;
    cboard(vector<csprite>& v);
    
};

Vector2i cboard::getpixelposition(int p)
{
    int w = boardSprite.sprite.getTexture()->getSize().x;
    int h = boardSprite.sprite.getTexture()->getSize().y;
    int xsquare = w/8;
    int ysquare = h/8;

    int x = (p%8)*xsquare;
    int y = (p/8)*ysquare;

    return Vector2i(x, y);
}

cboard::cboard(vector<csprite> &v) :
    boardSprite(boardAddress, v)
{
    boardSprite.activate();
}