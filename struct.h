#ifndef STRUCT
#define STRUCT

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define windowWidth 1024
#define windowHeight 1024
#define boxWidth 128
#define boxHeight 128

using namespace sf;
struct boardstate;
Vector2f to_vector2f(Vector2i v);
Vector2i to_vector2i(Vector2f v);
class kwadrat{
    public:
    kwadrat(Vector2f v,int c);
    void draw(RenderWindow& window);
    void move(Vector2f v);
};
class plansza{
    public:
    plansza();
    void draw(RenderWindow& window);
};

#endif