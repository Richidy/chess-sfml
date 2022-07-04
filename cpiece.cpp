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

    int _type; // 0q, 1k, 2r, 3kn, 4b, 5p
    bool color; // true white, false black
    csprite pieceSprite; 
    cpiece(vector<csprite>& v, int t, int p, Vector2i pixelp, const Texture& texture);
    void movePiece();

};

void cpiece::movePiece(){
    
}

cpiece::cpiece(vector<csprite>& v, int t, int p, Vector2i pixelp, const Texture& texture):
    pieceSprite(pieceAddress, v, texture)
{
    _type = ((t-10)/10);
    color = ((t)%10);
    position = p;

    // piece.png is 6 columns and 2 rows
    // 1st row black , 2nd white
    // q , k , r , kn , b , p
    int w = pieceSprite.sprite.getTexture()->getSize().x;
    int h = pieceSprite.sprite.getTexture()->getSize().y;

    int wpiece = w/6;
    int hpiece = h/2;
    int x = wpiece*_type;
    int y = hpiece*color;

    pieceSprite.sprite.setTextureRect(IntRect(x, y, wpiece, hpiece));

    position = p;
    pieceSprite.sprite.setPosition(pixelp.x, pixelp.y);

    pieceSprite.activate();
}