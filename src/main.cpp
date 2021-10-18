#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>


class primitives{
private:
	sf::VertexArray triangle;
public:
	void shape(int width, int height){
		triangle.setPrimitiveType(sf::Triangles);
		triangle.resize(3);
		triangle[0].position = sf::Vector2f(10, 10);
		triangle[1].position = sf::Vector2f(width*0.5, 10);
		triangle[2].position = sf::Vector2f(width*0.5, height*0.5);
		triangle[0].color = sf::Color::Red;
		triangle[1].color = sf::Color::Blue;
		triangle[2].color = sf::Color::Green;
	}
	void drawline(int x, int y, int x1, int y1, sf::RenderWindow *window, int px){
		float difx = x1-x;
		float dify = y1-y;
		float diff = dify/difx;
		int cx = x;
		int cy = y;
		std::vector<sf::Vertex> vertices;
		if(x1!=x && y1!=y){
			for(cx = x; cx<=x1; cx+=diff, cy+=diff){
				for(int i = cx-(px/2); i <= cx+(px-(px/2)); i++){
					for(int j = cy-(px/2); j <= cy+(px-(px/2)); j++){
						vertices.push_back(sf::Vertex(sf::Vector2f(x+i,y+j),sf::Color::Black));
					}
				}
			}
			window->draw(&vertices[0],vertices.size(),sf::Triangles);
		}
		/*sf::Vertex line[]{
			sf::Vertex(sf::Vector2f(10,10),sf::Color::Black),
			sf::Vertex(sf::Vector2f(10,11),sf::Color::Black),
			sf::Vertex(sf::Vector2f(11,10),sf::Color::Black),
			sf::Vertex(sf::Vector2f(11,11),sf::Color::Black),
			sf::Vertex(sf::Vector2f(12,11),sf::Color::Black),
			sf::Vertex(sf::Vector2f(11,12),sf::Color::Black),
			sf::Vertex(sf::Vector2f(10,12),sf::Color::Black),
			sf::Vertex(sf::Vector2f(12,10),sf::Color::Black),
		};
		window->draw(line,2,sf::LinesStrip);*/
	}
	void drawshapes(sf::RenderWindow *window){
		window->draw(triangle);
	}
};

class engine{
private:
	sf::RenderWindow window;
	sf::Vector2u currsize;
	sf::ContextSettings settings;
	primitives prims;
public:
	void gamescreen(int width, int height){
		settings.antialiasingLevel = 8;
		window.create(sf::VideoMode(width,height),"Tower Defense", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize, settings);
		window.setKeyRepeatEnabled(false);
		window.setFramerateLimit(60);
		currsize = window.getSize();
		prims.shape(currsize.x,currsize.y);

		while(window.isOpen()){

			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				// Close window: exit
				if(evnt.type == evnt.Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
					prims.shape(currsize.x,currsize.y);
					currsize = window.getSize();
					if(currsize == sf::Vector2u(width,height)){

						window.create(sf::VideoMode(1920,1080),"Tower Defense", sf::Style::Fullscreen, settings);
					}
					else{
						window.create(sf::VideoMode(width,height),"Tower Defense", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize, settings);
						window.setPosition(sf::Vector2i(0,0));
					}
				}

			window.setActive(true);

			window.clear(sf::Color::Blue);
			//prims.drawshapes(&window);
			prims.drawline(10,10,30,300,&window,10);

			window.display();
			}
		}
		window.~RenderWindow();
	}
};

int main(){
	engine silnik;

	silnik.gamescreen(1280,720);
	
	return EXIT_SUCCESS;
}