#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>


class PrimitiveRenderer{
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
	void drawline(int x, int y, int x1, int y1, sf::RenderWindow *window){
		
		float difx = x1-x;
		float dify = y1-y;
		float diff = dify/difx;
		int cx = x;
		int cy = y;
		if(x1!=x && y1!=y){
			if(cx < x1)
			for(cx = x; cx<=x1; cx+=diff, cy+=diff){
				sf::Vertex vertices(sf::Vector2f(cx,cy), sf::Color::Black);
				window->draw(&vertices,2,sf::Points);
				
			}
		}
	}
	void drawRectangle(sf::RenderWindow *window, int posx, int posy, int sizex, int sizey){
		sf::RectangleShape rectangle(sf::Vector2f(sizex,sizey));
		rectangle.setPosition(sf::Vector2f(posx,posy));
		rectangle.setFillColor(sf::Color::Red);
		window->draw(rectangle);
	}

	void drawCircle(sf::RenderWindow *window, int posx, int posy, int size){
		sf::CircleShape circle(size);
		circle.setPosition(sf::Vector2f(posx,posy));
		circle.setFillColor(sf::Color::Red);
		window->draw(circle);
	}

	void drawTriangle(sf::RenderWindow *window, int posx, int posy, int size){
		sf::CircleShape circle(size,3);
		circle.setPosition(sf::Vector2f(posx,posy));
		circle.setFillColor(sf::Color::Red);
		window->draw(circle);
	}

	void drawshapes(sf::RenderWindow *window){
		window->draw(triangle);
	}
};