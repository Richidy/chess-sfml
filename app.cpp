#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!");

    sf::Texture texture;
    if (!texture.loadFromFile("board.png"))
    {
        cout << "err loading file" << endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}