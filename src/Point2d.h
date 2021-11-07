#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>
#include "PrimitiveRenderer.h"

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