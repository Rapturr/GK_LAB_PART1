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

class Point2D{
private:
	int pointx;
	int pointy;
	int pointx1;
	int pointy1;
	bool ch = false;
	PrimitiveRenderer prims;
public:
	int readC(){
		sf::Vector2i pos = sf::Mouse::getPosition();
		if(!pointx){
			pointx = pos.x;
			pointy = pos.y;
		}else if(!pointx1){
			pointx1 = pos.x;
			pointy1 = pos.y;
		}else
			return -1;
		return 0;
	}
	void modC(){
		sf::Vector2i pos = sf::Mouse::getPosition();
		std::cout<<"changed";
		if(ch){
			pointx = pos.x;
			pointy = pos.y;
			ch = false;
		}
		else if(!ch){
			pointx1 = pos.x;
			pointy1 = pos.y;
			ch = true;
		}
	}
	void drawLn(sf::RenderWindow *window){
		if(pointx>0 && pointx < 2000 && pointx1>0 && pointx1 < 2000)
				std::cout<<"przekazywane hello\n y = "<<pointy<<"  y1 = "<<pointy1;
			//jak odkomentujesz to wybuchnie
			//prims.drawline(pointx,pointy,pointx1,pointy1,window);
	}
};

class engine{
private:
	sf::RenderWindow window;
	sf::Vector2u currsize;
	PrimitiveRenderer prims;
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
					prims.shape(currsize.x,currsize.y);
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
			prims.drawline(300,120,1100,600,&window);
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