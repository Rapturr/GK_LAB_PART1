#include "Point2d.h"


class Engine{
private:
sf::RenderWindow window;
sf::Vector2u currsize;
sf::Vector2u originalsize;
Point2D points;
sf::Event evnt;
public:
	Engine(int width, int height){
		window.create(sf::VideoMode(width,height),"Tower Defense", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
		window.setKeyRepeatEnabled(false);
		window.setFramerateLimit(5);
		originalsize = sf::Vector2u(width, height);
	}
	void gamescreen(){
		while(window.isOpen()){
			while (window.pollEvent(evnt))
			{
				// Close window: exit
				if(evnt.type == evnt.Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
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
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				std::cout<<"Kliklo\n";
				points.readC(&window);
				}
			}
			window.clear(sf::Color::White);

			points.drawLn(&window);

			window.display();
		}
	}
};

/*class engine{
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
				std::cout<<"Kliklo\n";
				points.readC(&window);
			}
			//window.setActive(true);

			window.clear(sf::Color::White);
			//prims.drawshapes(&window);
			points.drawLn(&window);
			//points.drawLn(10,10,100,100,&window);

			window.display();
			}
		}
		window.~RenderWindow();
	}
};
*/