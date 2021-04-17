#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "kulki.h"
#include "paddle.h"
#include "Block.h"


using namespace std;
using namespace sf;

template <class T1 , class T2> bool isIntersecting(T1& A , T2& B)
{
    return A.right() >=B.left() && A.left() <=B.right()
    &&  A.bottom() >= B.top() && A.top() <= B.bottom() ;

}
bool collisiontest(Paddle &paddle , Ball &ball)
{
    if(!isIntersecting(paddle , ball )) return false ;
    ball.moveup() ;
    if(ball.getPosition().x < paddle.getPosition().x )
    {
        ball.moveleft() ;
    }
    else if(ball.getPosition().x > paddle.getPosition().x )
    {
        ball.moveright() ;
    }


}
bool collisionTest(Block &block ,Ball &ball )
{

    if(!isIntersecting(block, ball)) return false ;
    block.destroy() ;
    float overlapleft{ball.right() - block.left()} ;
    float overlapright{block.right() - ball.left()} ;
    float overlaptop{ball.bottom() - block.top()} ;
    float overlapbottom{block.bottom() - ball.top()} ;
    bool ballfromleft( abs(overlapleft)< abs(overlapright)) ;
    bool ballfromtop( abs(overlaptop)< abs(overlapbottom)) ;
    float minoverlapx {ballfromleft ? overlapleft  : overlapright} ;
    float minoverlapy {ballfromtop ? overlaptop  : overlapbottom} ;
    if(abs(minoverlapx ) < abs(minoverlapy))
    {
        ballfromleft ? ball.moveleft() : ball.moveright() ;
    }
    else
    {
        ballfromtop ? ball.moveup() : ball.movedown() ;
    }
}


int main()
{
    Ball ball(400 , 300) ;
    Paddle paddle(400 ,  550) ;
  RenderWindow window  {VideoMode{800,600} , "Pierwsza proba"}; // nowe okno w konsoli
  window.setFramerateLimit(60);
 // dziala 60 razy na sekund
 Event event ;

 unsigned blocksx {10} , blocksy{4} , blockswidth{60} , blocksheight{ 20} ;
 vector <Block> blocks ;
 for(int i=0 ; i<blocksy ; i++)
 {
     for(int j=0 ; j<blocksx ; j++)
     {
         blocks.emplace_back((j+1)*(blockswidth+10) , (i+2)*(blocksheight+5) , blockswidth , blocksheight  )  ;
     }
 }


  while(true)
  {
      window.clear(Color::Black) ; // kolor okna
      window.pollEvent(event) ; // zeby działało

        if(event.type == Event::Closed) // zamykanie okna
        {
            window.close() ;
            break ;

        }
        ball.update() ;
        paddle.update() ;
        collisiontest(paddle , ball) ;
        for( auto& block : blocks) if(collisionTest(block ,ball) ) break ;
        auto iterator = remove_if(begin(blocks) , end(blocks) , [](Block& block ){return block.isdestroyed() ;}) ;
        blocks.erase(iterator , end(blocks)) ;



       window.draw(ball) ;
       window.draw(paddle) ;

       for(auto& block : blocks)
       {
           window.draw(block) ;
       }


window.display() ;
  }




  return 0 ;

}
