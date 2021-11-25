#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <ctime>

/* Klasa BitmapHandler  - odpowiada za przetrzymywanie obrazów oraz wyświetlanie go na ekranie
*/

class BitmapHandler{
private:
std::vector<sf::Texture> texturevec;
sf::Sprite sprite;
std::time_t starttime;
sf::Clock clock;
int animationframe = 0;
//0 - right; 1 - left; 2 - up; 3 - down
int direction;


/** loadtextures - funkcja odpowiadająca za rysownie tekstur z pliku
*/
void loadtextures(){
	texturevec.resize(16);
	texturevec[0].loadFromFile("../assets/R0.png");
	texturevec[1].loadFromFile("../assets/R1.png");
	texturevec[2].loadFromFile("../assets/R2.png");
	texturevec[3].loadFromFile("../assets/R3.png");
	texturevec[4].loadFromFile("../assets/L0.png");
	texturevec[5].loadFromFile("../assets/L1.png");
	texturevec[6].loadFromFile("../assets/L2.png");
	texturevec[7].loadFromFile("../assets/L3.png");
	texturevec[8].loadFromFile("../assets/U0.png");
	texturevec[9].loadFromFile("../assets/U1.png");
	texturevec[10].loadFromFile("../assets/U2.png");
	texturevec[11].loadFromFile("../assets/U3.png");
	texturevec[12].loadFromFile("../assets/D0.png");
	texturevec[13].loadFromFile("../assets/D1.png");
	texturevec[14].loadFromFile("../assets/D2.png");
	texturevec[15].loadFromFile("../assets/D3.png");
}
public:
	/** kostruktor ustawia czas i pozycje spritów 
	*/
	BitmapHandler(){
		starttime = std::time(nullptr);
		sprite.setPosition(0,0);
		clock.restart();
	}

	/** wywołuję funkcje odpowiadającą za dodawanie tekstur oraz ustawia kierunke w którym postać jest zwrócona 
	*/
	void createbm(){
		direction = 0;
		loadtextures();
	}
	

	/** funkcja zmieniająca pozycje sprita
	*/
	void changepos(sf::Vector2f pos, int dir){
		sprite.setPosition(pos);
		direction = dir;
	}


	/** funkcja odpowaidajaca za zmiane klatek animacji i rysownie jej na ekranie
	* @param window wskaźnik na okno gry
	*/
	void animateSprite(sf::RenderWindow *window){
		if(clock.getElapsedTime().asMilliseconds() > 50.0f){
			sprite.setTexture(texturevec[animationframe+(direction*4)]);
			animationframe++;
			if(animationframe >= 4){
				animationframe = 0;
			}
				clock.restart();
		}
		window->draw(sprite);

	}

	/** funkcja za rysownie sprita
	* @param window wskaźnik na okno gry
	*/
	void draw(sf::RenderWindow *window){
		sprite.setTexture(texturevec[direction+(direction*4)]);
		window->draw(sprite);
	}
};