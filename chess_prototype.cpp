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

using namespace std;
using namespace sf;

constexpr int windowWidth{128*8},windowHeight{128*8};
constexpr int boxWidth{128},boxHeight{128};

Vector2f to_vector2f(Vector2i v){
    return {static_cast<float>(v.x),static_cast<float>(v.y)};
}
Vector2i to_vector2i(Vector2f v){
    return {static_cast<int>(v.x),static_cast<int>(v.y)};
}
struct pionek {
    // Declare and load a texture
    sf::Texture tex;
    sf::Sprite sprite;
    bool attached=false;
    pionek(){
        tex.loadFromFile("128px/b_pawn_png_shadow_128px.png");
        // Create a sprite
        sprite.setTexture(tex);
        //sprite.setScale({1,1});
        //sprite.setColor(sf::Color(255, 255, 255, 200));
        sprite.setOrigin({0,0});
        sprite.setPosition(0, 0);
    }
   
    void move(Vector2i v){
        sprite.setPosition(v.x, v.y);
    }
    void draw(RenderWindow& window,Vector2i v){
        if (attached){
           // v.x=+50;
            //v.y=+50;
            move(v);
        }
        cerr<<"pionek:"<<v.x<<" "<<v.y<<endl;
        window.draw(sprite);
    }
    void attach(){
        attached=!attached;
    }
    Vector2i position(){
        return to_vector2i(sprite.getPosition());
    }
    
};

struct kwadrat{
    RectangleShape box;
    //pionek zawartosc;
    //pionek* zawartosc;
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
struct plansza{
    vector<kwadrat> tab;
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
int main(){

    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window{{windowWidth,windowHeight},"_ _ARKANOID_ _",sf::Style::Default,settings};
    window.setFramerateLimit(60);
    plansza szachownica;
    pionek pawn;
    kwadrat pointer(to_vector2f({0,0}),3);
    while(true){
        Vector2i mouse_position =Mouse::getPosition( window);
        cerr<<"mouse_position:"<<mouse_position.x<<" "<<mouse_position.y<<endl;

        Vector2i wskaznik=mouse_position/boxHeight;
        wskaznik*=boxHeight;
        cerr<<"wskaznik:"<<wskaznik.x<<" "<<wskaznik.y<<endl;
        pointer.move(to_vector2f(wskaznik));
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // key pressed
                case sf::Event::MouseButtonPressed:
                    if (wskaznik==pawn.position())
                        pawn.attach();
                    break;

                // we don't process other types of events
                default:
                    break;
            }
        }
        szachownica.draw(window);
        pointer.draw(window);
        pawn.draw(window,wskaznik);
        window.display();
    }
}