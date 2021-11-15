#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>


class PrimitiveRenderer{ 
private:
	sf::VertexArray triangle;
	sf::VertexArray vertices;
	sf::Vertex point;
	std::vector<sf::Vertex> linesvector;
	std::vector<sf::Vertex> circlevector;
	std::vector<sf::Vertex> elipssevector;
	sf::VertexArray lines;
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
	/*void drawline(int x, int y, int x1, int y1, sf::RenderWindow *window){
		float difx = x1-x;
		float dify = y1-y;
		float diff = dify/difx;
		int cx = x;
		int cy = y;
		if(x1>x && y1>y){
			if(cx < x1)
			for(cx = x; cx<=x1; cx+=diff, cy+=diff){
				sf::Vertex vertices(sf::Vector2f(cx,cy), sf::Color::Black);
				window->draw(&vertices,1,sf::Points);
			}
		}
	}*/
	void makeline(sf::Vector2f pos1, sf::Vector2f pos2){
		int x = pos1.x;
		int y = pos1.y;
		int x1 = pos2.x;
		int y1 = pos2.y;
		if(x>x1){
			int tempx = x;
			x = x1;
			x1 = tempx;
			int tempy = y;
			y = y1;
			y1 = tempy;
		}
		

		if(x<x1 && y<y1){


			
			std::cout<<std::endl<<(x1-x)/(y1-y)<<std::endl;
			if( (y1-y)/(x1-x) < 1 ){

				std::cout<<"jestem mniejszy od 45 stopni."<<std::endl;
				float difx = x1-x;
				float dify = y1-y;
				float diffy = dify/difx;
				float diffx = difx/dify;
				float cx = x;
				float cy = y;
				int j = 0;
				int i = 0;
				std::vector<sf::Vertex> vericec;
				for(cx = x; cx<=x1; cx++, cy+=diffy){
					j++;
				}
				vertices.resize(j);

				for(cx = x, cy = y; cx<=x1; cx++, cy+=diffy, i++){
					vertices[i].position = sf::Vector2f(cx,cy);
					vertices[i].color = sf::Color::Black;
					//Do wektora
					linesvector.push_back(vertices[i]);
					//i++;
					//sf::Vertex vert(sf::Vector2f(cx,cy), sf::Color::Black);
				}
			}
			else
			{
				std::cout<<"jestem wiekszy od 45 stopni."<<std::endl;
				float difx = x1-x;
				float dify = y1-y;
				float diffy = dify/difx;
				float diffx = difx/dify;
				float cx = x;
				float cy = y;
				int j = 0;
				int i = 0;
				std::vector<sf::Vertex> vericec;
				for(cx = x; cx<=x1; cx+=diffx, cy++){
					j++;
				}
				vertices.resize(j);

				for(cx = x, cy = y; cx<=x1; cx+=diffx, cy++, i++){
					vertices[i].position = sf::Vector2f(cx,cy);
					vertices[i].color = sf::Color::Black;
					//Do wektora
					linesvector.push_back(vertices[i]);
					//i++;
					//sf::Vertex vert(sf::Vector2f(cx,cy), sf::Color::Black);
				}
			}
		}
		
		
	}
	void drawline(sf::RenderWindow *window){
		//std::cout<<"rysuje sie\n";
		//window->draw(vertices);
		window->draw(&linesvector[0],linesvector.size(),sf::LineStrip);
	}
	
	void drawRectangle(sf::RenderWindow *window, int posx, int posy, int sizex, int sizey){
		sf::RectangleShape rectangle(sf::Vector2f(sizex,sizey));
		rectangle.setPosition(sf::Vector2f(posx,posy));
		rectangle.setFillColor(sf::Color::Red);
		window->draw(rectangle);
	}

	void makeCircle(sf::Vector2f center, float radius){
		circlevector.resize(500);
		for(float i = 0 ;i<3.14/2;i += 0.01){
			circlevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x + (radius * std::cos(i))), ((int)center.y + (radius * std::sin(i)))),sf::Color::Black));
			circlevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x - (radius * std::cos(i))), ((int)center.y + (radius * std::sin(i)))),sf::Color::Black));
			circlevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x + (radius * std::cos(i))), ((int)center.y - (radius * std::sin(i)))),sf::Color::Black));
			circlevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x - (radius * std::cos(i))), ((int)center.y - (radius * std::sin(i)))),sf::Color::Black));
		}


	}
	void drawCircle(sf::RenderWindow *window){

		window->draw(&circlevector[0],circlevector.size(),sf::Points);

	}
	void makeElipsse(sf::Vector2f center, float radiusx, float radiusy){
		circlevector.resize(500);
		for(float i = 0 ;i<3.14/2;i += 0.01){
			elipssevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x + (radiusx * std::cos(i))), ((int)center.y + (radiusy * std::sin(i)))),sf::Color::Black));
			elipssevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x - (radiusx * std::cos(i))), ((int)center.y + (radiusy * std::sin(i)))),sf::Color::Black));
			elipssevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x + (radiusx * std::cos(i))), ((int)center.y - (radiusy * std::sin(i)))),sf::Color::Black));
			elipssevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x - (radiusx * std::cos(i))), ((int)center.y - (radiusy * std::sin(i)))),sf::Color::Black));
		}


	}
	void drawElipsse(sf::RenderWindow *window){

		window->draw(&elipssevector[0],elipssevector.size(),sf::Points);

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

	void makepoint(sf::Vector2f p){
		point.position = p;
		point.color = sf::Color(sf::Color::Black);
	}
	void drawpoint(sf::RenderWindow *window){
		//window->draw(point, 1, sf::Points);
	}

	void makesfmlline(std::vector<sf::Vertex> line){
		linesvector.clear();
		lines.resize(line.size());
		for(int i = 0; i < line.size(); i++){
			lines[i].position = line[i].position;
			lines[i].color = sf::Color(rand()%255,rand()%255,rand()%255);
			linesvector.push_back(lines[i]);
		}
	}
	void clearLine(){
		lines.clear();
		linesvector.clear();
	}
};