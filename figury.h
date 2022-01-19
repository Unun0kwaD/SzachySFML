#ifndef FIGURY
#define FIGURY

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Figura{

    public:
    void move(Vector2i v);
    void draw(RenderWindow& window,Vector2i v);
    void select();
    Vector2i position();
};

class pionek: Figura{
    public:
    pionek(char color);
};

#endif