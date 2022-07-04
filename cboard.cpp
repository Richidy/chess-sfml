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
#include <string>
#include <cctype> 
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
    vector<cpiece> pieces_on_board;

public:

    Vector2i getpixelposition(int p);
    cboard(vector<csprite>& v, const Texture& t);
    void initialize(int _state[], cwindow& window);
    void initialize(string& n, cwindow& window);
    
    csprite boardSprite;
    Texture piecesTexture;
};

void cboard::initialize(string& fen, cwindow& window)
{
    const size_t size = fen.size();
    size_t iter = 0;
    int index = 0;
    int piece_type;
    int fen_board[64] = {0};

    // parse the board first
    for (; (iter < size) and (fen[iter] != ' '); iter++)
    {
        if (fen[iter] == '/')
            continue;


        if (isdigit(fen[iter]))
            index += (fen[iter] - '0'); // converts char digit to int. `5` to 5

        else
        {   
            switch (fen[iter])
            {
            case 'q': piece_type = 10;
                break; 
            
            case 'Q': piece_type = 11;
                break;
            
            case 'k': piece_type = 20;
                break;
            
            case 'K': piece_type = 21;
                break;
            
            case 'r': piece_type = 30;
                break;
            
            case 'R': piece_type = 31;
                break;

            case 'n': piece_type = 40;
                break;
            
            case 'N': piece_type = 41;
                break;

            case 'b': piece_type = 50;
                break;
            
            case 'B': piece_type = 51;
                break;

            case 'p': piece_type = 60;
                break;
            
            case 'P': piece_type = 61;
                break;
            }
            fen_board[index] = piece_type;
            ++index;
        }
    }

    bool turn = fen[iter + 1] == 'w' ? 1 : 0;

    for(int i = 0; i < 64; i++)
    {
        if(fen_board[i] != 0)
        {
            cpiece (
                window.active_sprites,
                fen_board[i],
                i,
                getpixelposition(i),
                piecesTexture
            );
        }
    }
}

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