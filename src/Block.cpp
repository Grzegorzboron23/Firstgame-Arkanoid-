#include "Block.h"


using namespace std;
using namespace sf;

Block::Block(float t_x , float t_y , float width , float height)
{
    shape.setPosition(t_x , t_y) ;
shape.setSize({width , height} ) ;
shape.setFillColor(Color::Yellow);
shape.setOrigin(width/2.f , height/2.f) ;
}
void Block::draw(RenderTarget& target , RenderStates state) const
{
    target.draw(this->shape , state) ;
}
float  Block::left()
{
     return this->shape.getPosition().x -shape.getSize().x /2.f ;
}
float  Block::right()
{
    return this->shape.getPosition().x + shape.getSize().x /2.f ;
}

float   Block::top()
{
     return this->shape.getPosition().y - shape.getSize().y /2.f ;

}
float   Block::bottom()
{
     return this->shape.getPosition().y + shape.getSize().y /2.f ;

}
 Vector2f Block::getPosition()
 {
     return shape.getPosition() ;
 }
bool  Block::isdestroyed()
{
   return this-> destroyed ;
}
void Block::destroy()
{
    this->destroyed = true;
}

Vector2f Block::getSize()
{
    return shape.getSize() ;
}
void update()
{

}


