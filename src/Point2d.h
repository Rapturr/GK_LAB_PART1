#include "Primitiverenderer.h"

class Point2D{
private:
	int pointx;
	int pointy;
	int pointx1;
	int pointy1;
	bool ch = false;
	PrimitiveRenderer prims;
public:
	Point2D(){
	pointx = -1;
	pointy = -1;
	pointx1 = -1;
	pointy1 = -1;
	}
	void readC(sf::RenderWindow *window){
		sf::Vector2i pos = sf::Mouse::getPosition(*window);

		if(pointx < 0){
			pointx = pos.x;
			pointy = pos.y;
		}else if(pointx1 < 0){
			pointx1 = pos.x;
			pointy1 = pos.y;
		}else
			modC(window);
	}
	void modC(sf::RenderWindow *window){
		sf::Vector2i pos = sf::Mouse::getPosition(*window);
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
		prims.makeline(pointx,pointy,pointx1,pointy1);
	}
	void drawLn(sf::RenderWindow *window){
		if(pointx>0 && pointx < 2000 && pointx1>0 && pointx1 < 2000){
			//std::cout<<"przekazywane hello\n y = "<<pointy<<"  y1 = "<<pointy1;
			//jak odkomentujesz to wybuchnie
			prims.drawline(window);
		}
	}
	void drawLn(int x,int y, int x1, int y1, sf::RenderWindow *window){
		prims.drawline(window);
	}
};