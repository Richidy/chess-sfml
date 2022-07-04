//    ____ _   _ _____ ____ ____  
//   / ___| | | | ____/ ___/ ___| 
//  | |   | |_| |  _| \___ \___ \ 
//  | |___|  _  | |___ ___) |__) |
//   \____|_| |_|_____|____/____/ 
//
//  v 1.0.0

#include "cwindow.cpp"
#include "csprite.cpp"
#include "cboard.cpp"
#include "cpiece.cpp"

//#define DEBUG

int main()
{
    cwindow window(512, 512, "Chess");

    #ifdef DEBUG
    string boardAddress = "board.png";
    csprite boardSprite(boardAddress, window.active_sprites);
    boardSprite.activate();
    #endif

    int square[64];
    for(int i = 0; i < 64; i++){
        square[i] = rand() % 100 > 80 ? rand() % 2 + (rand() % 6) * 10 : -1;
    }

    Texture boardTxt;
    boardTxt.loadFromFile("board.png");
    cboard board(window.active_sprites, boardTxt);
    board.initialize(square, window);

    window.MLoop();

    return 0;
}