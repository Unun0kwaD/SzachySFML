#include "struct.h"

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


using namespace sf;
using namespace std;

    
    void boardstate::reset(){

    }
    void boardstate::ruch(){

    }
    char boardstate::checkpiece(Vector2i v){
        return tab[v.x][v.y];
    }
     //plansza
    //male znaki biale
    //duze znaki czarne
    /* PIONY
    puste = '0'
    pion = 'p'
    wieza = 'w'
    skoczek = 's'
    goniec = 'g'
    krolowa = 'q'
    krol = 'k'
    mozliwe ruchy ='*'
    mozliwe bicia = 'x'
    */
    //puste pole = 0 lub 1 -> czarny 0, bialy 1


Vector2f to_vector2f(Vector2i v){
    return {static_cast<float>(v.x),static_cast<float>(v.y)};
}
Vector2i to_vector2i(Vector2f v){
    return {static_cast<int>(v.x),static_cast<int>(v.y)};
}
    kwadrat::kwadrat(Vector2f v,int c){
        box.setPosition(v.x,v.y);
        box.setSize(to_vector2f({boxWidth,boxHeight}));
        if (c==1) box.setFillColor(Color::Black);
        else if (!c) box.setFillColor(Color::White); 
        else if (c==3) box.setFillColor(Color::Blue);
        else if (c==4) box.setFillColor(Color::Green);
    }
    void kwadrat::draw(RenderWindow& window){
        window.draw(box);
        //(*zawartosc).draw(window);
    }
    void kwadrat::move(Vector2f v){
        box.setPosition(v);
    }

    plansza::plansza(){
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                tab.emplace_back(to_vector2f({i*boxWidth,j*boxHeight}),(i+j)%2);
                figtab.emplace_back(actualboardstate.tab[i][j],to_vector2i({i*boxWidth,j*boxHeight}));
            }
        }
    }
    void plansza::draw(RenderWindow& window){
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                tab[i*8+j].draw(window);
            }
        }
    }
    void plansza::figdraw(RenderWindow& window){
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                if(figtab[i*8+j].typ)
                    figtab[i*8+j].draw(window,{i*boxHeight,j*boxWidth},actualboardstate.tab[i][j]);
            }
        }
    }

    char plansza::checkpiece(Vector2i v){
        return actualboardstate.checkpiece(v);
    }