#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class BitmapHandler{
private:
std::vector<sf::Texture> texturevec;
sf::Sprite sprite;
int direction;
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
	void createbm(){
		direction = 0;
		loadtextures();
	}
	
	void deletesprite(){
	}

	void loadffile(){

	}
	void savetfile(){

	}
	void animateSprite(sf::RenderWindow *window){
		for(int i = 0; i < 16; i ++){
			sprite.setTexture(texturevec[i]);
			sprite.setPosition(sf::Vector2f(400,400));
			window->draw(sprite);
		}
	}

	sf::Sprite copy(){
		
	}
};