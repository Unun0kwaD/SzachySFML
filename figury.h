#pragma once

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
char turn(char typ);

class Figura{
    
    Texture tex;
    Sprite sprite;
    public: 
    /* Typy
    male biale
    duze czarne
    pion = 'p'
    wieza = 'w'
    skoczek = 's'
    goniec = 'g'
    krolowa = 'q'
    krol = 'k'
    */
    int initialstate=1;
    char typ;
    void changetype(char intyp);
    Figura(Vector2f v,char intyp);
    //Figura(char intyp,Vector2i v);
    void move(Vector2f v);
    void draw(RenderWindow& window,Vector2f v,char typ);
    void set(Vector2f v,char intyp);
    //void Figura::draw(RenderWindow& window);
    void select();
    Vector2i position();
    void toqueen();
};