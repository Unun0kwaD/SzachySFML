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
    boardstate ruchy;
    ruchy.clear();
    kwadrat pointer(to_vector2f({0,0}), 3);
    kwadrat selected(to_vector2f({-1,-1}), 4);
    Vector2i select={-1,-1};
    int s=0;
    char player='a';//'A'-black 'a' - white
    while(true){
        Vector2i mouse_position =Mouse::getPosition( window);
        Vector2i wskaznik=mouse_position/boxHeight;
        //cout<<wskaznik.x<<"\t"<<wskaznik.y<<"\n";
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
                        Vector2i tmp=wskaznik/boxHeight;
                        //select new piece
                        //cout<<"select1\n";
                        if(s<=0 && turn(szachownica.checkpiece(tmp))==player ) {// player && szachownica.checkpiece(tmp)<(int)player+26 ){
                            select=tmp;
                            s=1;
                            //cout<<"select2\n";
                            //cout<<szachownica.return_state(select);
                            ruchy=moves(select,szachownica.actualboardstate,szachownica.return_state(select));
                        }
                        // moves should return table of possible moves from Vector on boardstate
                       /* else if (moves(select,szachownica.actualboardstate)[tmp.x][tmp.y]=='*' ||moves(select,szachownica.actualboardstate)[tmp.x][tmp.y]=='x')
                            //try to move selected piecefrom select to mouse actual position
                           // szachownica.actualboardstate.ruch(select,tmp);
                           */
                        else if(s==1 && ruchy.tab[tmp.x][tmp.y]!='0' && !(select.x==tmp.x && select.y==tmp.y)){
                            //cout<<"select3\n";
                            if (szachownica.ruch(select,tmp)){
                                s=0;
                                if(player=='A')
                                    player='a';
                                else if(player=='a')
                                    player='A';
                               
                            }
                            ruchy.clear();
                            szachownica.change_state(tmp,0);
                            select={-1,-1};
                        }
                        //else
                          //  s=-1;  
                    }
                    else if(event.mouseButton.button == sf::Mouse::Right){
                        s=0;
                        select={-1,-1};
                        ruchy.clear();
                        //szachownica.printtab();
                    }
                    break;
                // we don't process other types of events
                default:
                    break;
            }
        }
        selected.move(to_vector2f(select*boxHeight));
        szachownica.draw(window);
        ruchy.drawmoves(window);
        pointer.draw(window);
        selected.draw(window);
        szachownica.figdraw(window);
        window.display();
    }
}