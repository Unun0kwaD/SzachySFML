#pragma once

#define windowWidth 1024
#define windowHeight 1024
#define boxWidth 128
#define boxHeight 128

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
#include "figury.h"

using namespace sf;
using namespace std;

struct boardstate{
    char tab[8][9]={
            "wsgkqgsw",
            "pppppppp",
            "00000000",
            "00000000",
            "00000000",
            "00000000",
            "PPPPPPPP",
            "WSGKQGSW"
        };
    void reset();
    void ruch();
};
Vector2f to_vector2f(Vector2i v);
Vector2i to_vector2i(Vector2f v);
class kwadrat{
    sf::RectangleShape box;
    public:
    kwadrat(Vector2f v,int c);
    void draw(RenderWindow& window);
    void move(Vector2f v);
};
class plansza{
    boardstate actualboardstate,moves;
    vector<kwadrat> tab;
    vector<Figura> figtab;
    public:
    plansza();
    void draw(RenderWindow& window);
    void figdraw(RenderWindow& window);
};
