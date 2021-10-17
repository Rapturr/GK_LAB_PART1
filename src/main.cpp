#define SFML_STATIC
#include <SFML/Graphics.hpp>


class primitives{
private:
	//sf::Vertex vertex;
	sf::VertexArray triangle;
public:
	void shape(int width, int height){
		/*vertex.position = sf::Vector2f(10,50);
		vertex.color = sf::Color::Red;
		vertex.texCoords = sf::Vector2f(100,100);*/
		triangle.setPrimitiveType(sf::Triangles);
		triangle.resize(3);
		triangle[0].position = sf::Vector2f(10, 10);
		triangle[1].position = sf::Vector2f(width*0.5, 10);
		triangle[2].position = sf::Vector2f(width*0.5, height*0.5);
		triangle[0].color = sf::Color::Red;
		triangle[1].color = sf::Color::Blue;
		triangle[2].color = sf::Color::Green;
	}
	void drawshapes(sf::RenderWindow *window){
		window->draw(triangle);
	}
};
/*
class primitives{
private:
sf::RectangleShape rectangle;
sf::CircleShape triangle;
sf::ConvexShape convex;
public:
	void shape(){
		convex.setPointCount(3);
		triangle.setPointCount(3);
		rectangle.setSize(sf::Vector2f(100.0f,100.0f));
		
	}
	void drawshapes(sf::RenderWindow *window){
		sf::Vector2u size = window->getSize();
		int width = size.x;
		int height = size.y;
		convex.setPoint(0, sf::Vector2f(width*0.1f, height*0.3f));
		convex.setPoint(1, sf::Vector2f(width*0.1f, height*0.6f));
		convex.setPoint(2, sf::Vector2f(width*0.3f, height*0.45f));
		convex.setFillColor(sf::Color::Green);
		window->draw(convex);
	}

};
*/
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
				if(evnt.type == evnt.Closed)
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
			prims.drawshapes(&window);

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