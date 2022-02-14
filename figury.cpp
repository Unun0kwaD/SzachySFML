#include "figury.h"

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

char turn(char typ){
    if(typ>='a')
        return 'a';
    else if (typ>='A')
        return 'A';
    else return '0';
}

void Figura::toqueen(){
    Texture tex2;
    if (typ>'A'){
        tex2.loadFromFile("128px/b_queen_png_shadow_128px.png");
    }
    else 
        tex2.loadFromFile("128px/w_queen_png_shadow_128px.png");
    tex=tex2;
    sprite.setTexture(tex2);
}
void Figura::changetype(char intyp){
    typ=intyp;
    switch(intyp)
    {
    case 'p':
        tex.loadFromFile("128px/w_pawn_png_shadow_128px.png");
        //cerr<<"loaded\n";
        break;
    case 'P':
        tex.loadFromFile("128px/b_pawn_png_shadow_128px.png");
        break;
    case 'w':
        tex.loadFromFile("128px/w_rook_png_shadow_128px.png");
        break;
    case 'W':
        tex.loadFromFile("128px/b_rook_png_shadow_128px.png");
        break;
    case 's':
        tex.loadFromFile("128px/w_knight_png_shadow_128px.png");
        break;
    case 'S':
        tex.loadFromFile("128px/b_knight_png_shadow_128px.png");
        break;
    case 'g':
        tex.loadFromFile("128px/w_bishop_png_shadow_128px.png");
        break;
    case 'G':
        tex.loadFromFile("128px/b_bishop_png_shadow_128px.png");
        break;
    case 'q':
        tex.loadFromFile("128px/w_queen_png_shadow_128px.png");
        break;
    case 'Q':
        tex.loadFromFile("128px/b_queen_png_shadow_128px.png");
        break;
    case 'k':
        tex.loadFromFile("128px/w_king_png_shadow_128px.png");
        break;
    case 'K':
        tex.loadFromFile("128px/b_king_png_shadow_128px.png");
        break;
    }
    sprite.setTexture(tex);

}

Figura::Figura(Vector2f v,char intyp){
   // tex.create(128,128);
   initialstate=1;
    changetype(intyp);
    move(v);
}; 

void Figura::move(Vector2f v){
    sprite.setPosition(v.x*boxWidth, v.y*boxHeight);
}
/*
void Figura::draw(RenderWindow& window){
    window.draw(sprite);
}
*/
 void Figura::set(Vector2f v,char intyp){
    changetype(intyp);
    move(v);
 }
void Figura::draw(RenderWindow& window,Vector2f v,char typ){
    set(v,typ);
    window.draw(sprite);
}
void Figura::select(){
    
}
Vector2i Figura::position(){
    return to_vector2i(sprite.getPosition());
}