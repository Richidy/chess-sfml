//    ____ _   _ _____ ____ ____  
//   / ___| | | | ____/ ___/ ___| 
//  | |   | |_| |  _| \___ \___ \ 
//  | |___|  _  | |___ ___) |__) |
//   \____|_| |_|_____|____/____/ 
//
//  v 1.0.0

#include "cwindow.cpp"
#include "csprite.cpp"

#define DEBUG

int main()
{
    cwindow window(512, 512, "Chess");

    #ifdef DEBUG
    string boardAddress = "board.png";
    csprite boardSprite(boardAddress, window.active_sprites);
    boardSprite.activate();
    #endif

    window.MLoop();

    return 0;
}