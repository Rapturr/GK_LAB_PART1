#include "LineSegment.h"

class Engine{
private:
sf::RenderWindow window;
sf::Vector2u currsize;
sf::Vector2u originalsize;
LineSegment line;
sf::Event evnt;
PrimitiveRenderer kolo;
public:
	Engine(int width, int height){
		window.create(sf::VideoMode(width,height),"Tower Defense", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
		window.setKeyRepeatEnabled(false);
		window.setFramerateLimit(5);
		originalsize = sf::Vector2u(width, height);
	}
	void gamescreen(){
		while(window.isOpen()){
			while (window.pollEvent(evnt)){
				// Close window: exit
				if(evnt.type == evnt.Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
					currsize = window.getSize();
					if(currsize == originalsize){
						window.create(sf::VideoMode(1920,1080),"Tower Defense", sf::Style::Fullscreen);
					}
					else{
						window.create(sf::VideoMode(originalsize.x,originalsize.y),"Tower Defense", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
						window.setPosition(sf::Vector2i(0,0));
					}
				}
			
		/*
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				std::cout<<"Kliklo\n";
				line.readpoint(&window);
				line.makeLine(&window,2);
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				std::cout<<"Kliklo Reft\n";
				line.reset();
			}
			line.drawLine(&window);
		*/
			
			window.clear(sf::Color::White);
			kolo.makeElipsse(sf::Vector2f(100,500),50,60);
			kolo.drawElipsse(&window,0,0,0);

			window.display();
		}
	}
};