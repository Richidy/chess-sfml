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
#include "cwindow.cpp"
#include "cpiece.cpp"

using namespace std;
using namespace sf;

class cboard 
{
private:

    int state[64];
    string boardAddress = "board.png";

public:

    Vector2i getpixelposition(int p);
    cboard(vector<csprite>& v, const Texture& t);
    void initialize(int _state[], cwindow& window);
    
    csprite boardSprite;
    Texture piecesTexture;
};

void cboard:: initialize(int _state[], cwindow& window)
{
    for(int i = 0; i < 64; i++){
        state[i] = _state[i];
        if(state[i] != -1){
            cpiece(
                window.active_sprites,
                _state[i],
                i,
                getpixelposition(i),
                piecesTexture
            );
        }
    }
}

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

cboard::cboard(vector<csprite> &v, const Texture& t):
    boardSprite(boardAddress, v, t)
{
    boardSprite.activate();

    if(!piecesTexture.loadFromFile("pieces.png")){
        // err
        cout << "err loading pieces texture" << endl;
    }
}