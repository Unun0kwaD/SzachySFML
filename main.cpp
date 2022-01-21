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
    RenderWindow window{{windowWidth,windowHeight},"CHESS",sf::Style::Default,settings};
    window.setFramerateLimit(60);
    plansza szachownica;
    kwadrat pointer(to_vector2f({0,0}), 3);
    kwadrat selected(to_vector2f({-1,-1}), 4);
    Vector2i select={-1,-1};
    char player='a';//'A'-black 'a' - white
    while(true){
        Vector2i mouse_position =Mouse::getPosition( window);
        Vector2i wskaznik=mouse_position/boxHeight;
        cout<<select.x<<"\t"<<select.y<<"\n";
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
                    return 0;
                    break;

                // key pressed
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        Vector2i tmp=Mouse::getPosition(window)/(int)boxHeight;
                        //select new piece
                        if(select==(Vector2i){-1,-1} && szachownica.checkpiece(tmp)>player &&szachownica.checkpiece(tmp)<player+26 )
                            select=tmp;
                        // moves should return table of possible moves from Vector on boardstate
                       // else if (moves(select,szachownica.actualboardstate)[tmp.x][tmp.y]=='*' ||moves(select,szachownica.actualboardstate)[tmp.x][tmp.y]=='x')
                            //try to move selected piecefrom select to mouse actual position
                    }
                    else if(event.mouseButton.button == sf::Mouse::Right){
                        select={-1,-1};
                    }
                    break;

                // we don't process other types of events
                default:
                    break;
            }
        }
        selected.move(to_vector2f(select*boxHeight));
        szachownica.draw(window);
        pointer.draw(window);
        selected.draw(window);
        szachownica.figdraw(window);
        window.display();
    }
}