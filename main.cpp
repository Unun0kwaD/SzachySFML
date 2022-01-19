#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>

#include "struct.h"
#include "figury.h"

using namespace std;
using namespace sf;



int main(){

    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window{{windowWidth,windowHeight},"_ _ARKANOID_ _",sf::Style::Default,settings};
    window.setFramerateLimit(60);
    plansza szachownica;
    pionek pawn('b');
    kwadrat pointer(to_vector2f({0,0}), 3);
    while(true){
        Vector2i mouse_position =Mouse::getPosition( window);
        Vector2i wskaznik=mouse_position/boxHeight;
        wskaznik*=boxHeight;
        pointer.move(to_vector2f(wskaznik));
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // key pressed
                case sf::Event::MouseButtonPressed:
                    if (wskaznik==pawn.position())
                        pawn.select();
                    break;

                // we don't process other types of events
                default:
                    break;
            }
        }
        szachownica.draw(window);
        pointer.draw(window);
        pawn.draw(window,wskaznik);
        window.display();
    }
}