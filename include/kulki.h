#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;

class Ball :public Drawable // dodanie interfejsu
{
public:
    Ball(float x, float y ) ;
    void update() ;
    float left() ;
    float right() ;
    float top() ;
    float bottom() ;
    void moveup() ;
    void movedown() ;
    void moveright() ;
    void moveleft() ;
    Vector2f getPosition() ;
private:

    CircleShape shape ;
    const float ballRadius{10.0f} ;
    const float ballVelocity{3.0f} ;
    Vector2f velocity {ballVelocity, ballVelocity} ;
    void draw(RenderTarget& target, RenderStates state) const override ;




};


