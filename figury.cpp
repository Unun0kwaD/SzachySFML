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

class Figura{
    public: 
    sf::Texture tex;
    sf::Sprite sprite;
    char color;//'w'-'b'
    void move(Vector2i v){
        sprite.setPosition(v.x, v.y);
    }
    void draw(RenderWindow& window,Vector2i v){
        window.draw(sprite);
    }
    void select(){
        
    }
    Vector2i position(){
        return to_vector2i(sprite.getPosition());
    }
};
class pionek: public Figura{

    public:
    pionek(char color){
        if(color='w')
            tex.loadFromFile("128px/w_pawn_png_shadow_128px.png");
        else
            tex.loadFromFile("128px/b_pawn_png_shadow_128px.png");
        sprite.setTexture(tex);
    }
};