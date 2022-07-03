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

using namespace std;
using namespace sf;

class cpiece {
private:

    string pieceAddress = "pieces.png";
    Vector2f position;

public:

    void movePiece();

};