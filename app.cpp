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

    cboard board(window.active_sprites);
    
    cpiece pawn(window.active_sprites, 5, 1, 0, &board);
    cpiece pawn2(window.active_sprites, 2, 0, 43, &board);
    cpiece pawn3(window.active_sprites, 3, 0, 58, &board);
    cpiece pawn4(window.active_sprites, 1, 1, 22, &board);


    window.MLoop();

    return 0;
}