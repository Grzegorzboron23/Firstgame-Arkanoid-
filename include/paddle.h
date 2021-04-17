#ifndef PADDLE_H
#define PADDLE_H
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;


class Paddle : public sf::Drawable
{
    public:
        Paddle(float t_x , float t_y );
        void update() ;
        Vector2f getPosition() ;
    float left() ;
    float right() ;
    float top() ;
    float bottom() ;

    private :

        RectangleShape shape ;
        const float paddleWidth {80.0f} ;
        const float paddleHeight{20.0f} ;
        const float paddleVelocity{6.0f} ;
        Vector2f velocity{paddleVelocity , 0.f} ;
        void draw(RenderTarget& target, RenderStates state) const override    ;


};

#endif // PADDLE_H
