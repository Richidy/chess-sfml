/*
====================================
====================================
====================================
               Sprites
====================================
====================================
====================================

- has a texture
- has a sprite

*/

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class csprite 
{
public:

    Texture texture;
    Sprite sprite;
    csprite(string);
    
};

csprite::csprite(string n)
{
    if(!texture.loadFromFile(n))
    {
        cout << "error texture not loaded";
    }

    sprite = Sprite(texture);
}
