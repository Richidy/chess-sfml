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
    Texture boardTxt;
    boardTxt.loadFromFile("board.png");
    cboard board(window.active_sprites, boardTxt);
    string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    board.initialize(fen, window);
    board.remove_piece(2, window);

    window.MLoop();

    return 0;
}