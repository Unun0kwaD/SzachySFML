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
    public:
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
    char checkpiece(Vector2i v);
    void reset();
    void drawmoves(RenderWindow& window);
    void clear();
    void ruch(Vector2i f,Vector2i t);
};
boardstate moves(Vector2i v, boardstate board,int initialstate);
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
    vector<kwadrat> tab;
    vector<Figura> figtab;
    int postab[8][8];
    public:
    boardstate actualboardstate;
    plansza();
    int return_state(Vector2i v);
    void change_state(Vector2i v,int n);
    void printtab();
    void draw(RenderWindow& window);
    void figdraw(RenderWindow& window);
    char checkpiece(Vector2i v);
    bool ruch(Vector2i f, Vector2i t,RenderWindow& window);
    int szach();
    int mat=0;
};

void write_text(RenderWindow& okno,string tekst,Vector2f pos);