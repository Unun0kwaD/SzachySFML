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

class Figura{
    Texture tex;
    Sprite sprite;
    public: 
    char typ;
    /* Typy
    pion = 'p'
    wieza = 'w'
    skoczek = 's'
    goniec = 'g'
    krolowa = 'q'
    krol = 'k'
    */
    Figura(char intyp);
    void move(Vector2i v);
    void draw(RenderWindow& window,Vector2i v);
    void select();
    Vector2i position();
};