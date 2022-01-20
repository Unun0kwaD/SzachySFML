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

Figura::Figura(char intyp){
    typ=intyp;
    switch(intyp)
    {
    case 'p':
        tex.loadFromFile("128px/w_pawn_png_shadow_128px.png");
        break;
    case 'P':
        tex.loadFromFile("128px/b_pawn_png_shadow_128px.png");
        break;
    }
    sprite.setTexture(tex);
}; 
void Figura::move(Vector2i v){
    sprite.setPosition(v.x, v.y);
}
void Figura::draw(RenderWindow& window,Vector2i v){
    window.draw(sprite);
}
void Figura::select(){
    
}
Vector2i Figura::position(){
    return to_vector2i(sprite.getPosition());
}