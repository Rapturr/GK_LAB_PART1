#include "BitmapHandler.h"

class Player{
private:
BitmapHandler playerbm;
sf::Vector2f position;
int dir = 0;
sf::Vector2u windowSize;
public:
    Player(){
        playerbm.createbm();
    }
    void animate(sf::RenderWindow *window){
        playerbm.animateSprite(window);
        
        windowSize = window->getSize();
    }
    void move(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            position.y-=10;
            dir = 2;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            position.y+=10;
            dir = 3;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            position.x-=10;
            dir = 1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            position.x+=10;
            dir = 0;
        }
        if(position.x>windowSize.x){
            position.x = -130;
		}
        if(position.x<-130){
            position.x = windowSize.x-1;
		}
		if(position.y>windowSize.y){
            std::cout<<"y: "<<position.y<<std::endl;
            position.y = 0;
		}
        if(position.y<0){
            std::cout<<"y: "<<position.y<<std::endl;
            position.y = windowSize.y+1;
		}
        playerbm.changepos(position,dir);
    }
    void draw(sf::RenderWindow *window){
        playerbm.draw(window);
    }
};