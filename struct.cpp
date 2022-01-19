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

struct boardstate{
    char tab[8][8];
    
    void reset(){

    }
    void ruch(){

    }
     //plansza
    //male znaki biale
    //duze znaki czarne
    /* PIONY
    pion = 'p'
    wieza = 'w'
    skoczek = 's'
    goniec = 'g'
    krolowa = 'q'
    krol = 'k'
    mozliwe ruchy ='*'
    */
    //puste pole = 0 lub 1 -> czarny 0, bialy 1
};

Vector2f to_vector2f(Vector2i v){
    return {static_cast<float>(v.x),static_cast<float>(v.y)};
}
Vector2i to_vector2i(Vector2f v){
    return {static_cast<int>(v.x),static_cast<int>(v.y)};
}
class kwadrat{
    sf::RectangleShape box;
    public:
    kwadrat(Vector2f v,int c){
        box.setPosition(v.x,v.y);
        box.setSize(to_vector2f({boxWidth,boxHeight}));
        if (c==1) box.setFillColor(Color::Black);
        else if (!c) box.setFillColor(Color::White); 
        else if (c==3) box.setFillColor(Color::Blue);
    }
    void draw(RenderWindow& window){
        window.draw(box);
        //(*zawartosc).draw(window);
    }
    void move(Vector2f v){
        box.setPosition(v);
    }
};

class plansza{
    boardstate actualboardstate;
    vector<kwadrat> tab;
    public:
    plansza(){
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                tab.emplace_back(to_vector2f({i*boxWidth,j*boxHeight}),(i+j)%2);
            }
        }
    }
    void draw(RenderWindow& window){
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                tab[i*8+j].draw(window);
            }
        }
    }

};
