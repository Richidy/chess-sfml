/*
====================================
====================================
====================================
                Window
====================================
====================================
====================================

- takes care of rendering
- has a list of active sprites
- has a draw loop
- takes care of player input

*/

#define DEBUG

#include <iostream>
#include <SFML/Graphics.hpp>
#include "cboard.cpp"

using namespace std;
using namespace sf;

class cwindow 
{
public :

    #ifdef DEBUG
    string boardAddress = "board.png";
    csprite boardTexture{boardAddress};
    #endif

    RenderWindow window;
    cwindow(int h, int w, string n);
    void MLoop();

};

cwindow::cwindow(int h, int w, string n) :
    window(VideoMode(w,h), n)
{
    
}

void cwindow::MLoop ()
{
    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(boardTexture.sprite);        
        window.display();
    }
}
