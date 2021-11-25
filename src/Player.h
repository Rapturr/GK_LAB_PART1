#include "BitmapHandler.h"

/** Player
 * Klasa postaci np. gracza
 * @param playerbm objekt typu BitmapHandler, są tu przechowywane bitmapy postaci
 * @param position przechowywuje pozycję postaci
 * @param dir to kierunek w którym postać jest zwrócona
 * @param windowSize przechowuje rozmiar ekranu
 * @param speed szybkość postaci
*/
class Player{
private:
BitmapHandler playerbm;
sf::Vector2f position;
int dir = 0;
sf::Vector2u windowSize;
float speed = 10;
public:
    /** Player()
     * jest konstruktorem klasy Player
     * wywołuje funkcję createbm() klasy BitmapHandler
    */
    Player(){
        playerbm.createbm();
    }
    /** animate()
     * wywołuje funkcję animateSprite() klasy BitmapHandler, która wyświetla animacje postaci
     * @param window wskaźnik na okno gry
    */
    void animate(sf::RenderWindow *window){
        playerbm.animateSprite(window);
        
        windowSize = window->getSize();
    }
    /** move()
     * klasa odpowiedzialna za ruch i kierunek postaci
    */
    void move(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            position.y-=speed;
            dir = 2;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            position.y+=speed;
            dir = 3;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            position.x-=speed;
            dir = 1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            position.x+=speed;
            dir = 0;
        }
        if(position.x>windowSize.x){
            position.x = -130;
		}
        if(position.x<-130){
            position.x = windowSize.x-1;
		}
		if(position.y>windowSize.y){
            position.y = 0;
		}
        if(position.y<0){
            position.y = windowSize.y+1;
		}
        playerbm.changepos(position,dir);
    }
    /** draw
     * rysuje postać na ekranie
     * @param window wskaźnik na okno gry
    */
    void draw(sf::RenderWindow *window){
        playerbm.draw(window);
    }
};