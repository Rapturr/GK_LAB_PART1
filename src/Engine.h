#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Point2d.h"

class engine{
private:
	sf::RenderWindow window;
	sf::Vector2u currsize;
	
	Point2D points;
public:
	void gamescreen(int width, int height){
		window.create(sf::VideoMode(width,height),"Tower Defense", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
		window.setKeyRepeatEnabled(false);
		window.setFramerateLimit(5);
		currsize = window.getSize();
		//prims.shape(currsize.x,currsize.y);

		while(window.isOpen()){

			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				// Close window: exit
				if(evnt.type == evnt.Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
					currsize = window.getSize();
					if(currsize == sf::Vector2u(width,height)){
						window.create(sf::VideoMode(1920,1080),"Tower Defense", sf::Style::Fullscreen);
					}
					else{
						window.create(sf::VideoMode(width,height),"Tower Defense", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
						window.setPosition(sf::Vector2i(0,0));
					}
				}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				if(points.readC()<0){
					points.modC();
				}
			}
			//window.setActive(true);

			window.clear(sf::Color::White);
			//prims.drawshapes(&window);
			//points.drawLn(&window);
			window.display();
			}
		}
		window.~RenderWindow();
	}
};