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

void Figura::changetype(char intyp){
    typ=intyp;
    switch(intyp)
    {
    case 'p':
        tex.loadFromFile("128px/w_pawn_png_shadow_128px.png");
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
Figura::Figura(char intyp,Vector2i v){
    changetype(intyp);
    move(v);
}; 

void Figura::move(Vector2i v){
    sprite.setPosition(v.x, v.y);
}
/*
void Figura::draw(RenderWindow& window){
    window.draw(sprite);
}
*/
void Figura::draw(RenderWindow& window,Vector2i v,char intyp){
    changetype(intyp);
    move(v);
    window.draw(sprite);
}
void Figura::select(){
    
}
Vector2i Figura::position(){
    return to_vector2i(sprite.getPosition());
}