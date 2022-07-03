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
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "csprite.cpp"
#include <vector>

using namespace std;
using namespace sf;

class cwindow
{
public :

    RenderWindow window;
    cwindow(int h, int w, string n);
    void MLoop();

    vector<csprite> active_sprites;
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

        // loop through the vector and render all active sprites
        for(int i = 0; i < active_sprites.size(); i++){
            window.draw(active_sprites[i].sprite);
        }

        window.display();
    }
}