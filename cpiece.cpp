/*
====================================
====================================
====================================
            Chess Piece
====================================
====================================
====================================

- has a sprite
- has a getmoves function
- position

PROPERTIES:


METHODES:


*/
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "csprite.cpp"
#include "cboard.cpp"

using namespace std;
using namespace sf;

class cpiece {
private:

    string pieceAddress = "pieces.png";
    int position;

public:

    cboard* board;
    int _type; // 0q, 1k, 2r, 3kn, 4b, 5p
    bool color; // true white, false black
    csprite pieceSprite; 
    cpiece(vector<csprite>& v, int t, bool c, int p, cboard* b);
    void movePiece();

};

cpiece::cpiece(vector<csprite>& v, int t, bool c, int p, cboard* b):
    pieceSprite(pieceAddress, v)
{
    _type = t;
    color = c;
    board = b;

    // piece.png is 6 columns and 2 rows
    // 1st row black , 2nd white
    // q , k , r , kn , b , p
    int w = pieceSprite.sprite.getTexture()->getSize().x;
    int h = pieceSprite.sprite.getTexture()->getSize().y;

    int wpiece = w/6;
    int hpiece = h/2;
    int x = wpiece*t;
    int y = hpiece*c;

    pieceSprite.sprite.setTextureRect(IntRect(x, y, wpiece, hpiece));

    position = p;
    Vector2i pixelp = b->getpixelposition(p);
    pieceSprite.sprite.setPosition(pixelp.x, pixelp.y);

    pieceSprite.activate();
}