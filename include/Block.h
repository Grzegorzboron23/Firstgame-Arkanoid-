#ifndef BLOCK_H
#define BLOCK_H
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;


class Block :public sf::Drawable
{
    public:
        Block(float t_x , float t_y , float width , float height);
        void update() ;
        Vector2f getPosition() ;
        float left() ;
    float right() ;
    float top() ;
    float bottom() ;


    bool  isdestroyed() ;
    void destroy() ;
    Vector2f getSize() ;
    private:
        void draw(RenderTarget& target, RenderStates state) const override    ;
        RectangleShape shape ;
        bool destroyed {false} ;



};

#endif // BLOCK_H
