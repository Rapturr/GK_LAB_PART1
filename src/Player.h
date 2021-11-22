#include "BitmapHandler.h"

class Player{
private:
BitmapHandler playerbm;
sf::Vector2f position;
int dir = 0;
public:
    Player(){
        playerbm.createbm();
    }
    void animate(sf::RenderWindow *window){
        playerbm.animateSprite(window);
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
        playerbm.changepos(position,dir);
    }
    void draw(sf::RenderWindow *window){
        playerbm.draw(window);
    }
};