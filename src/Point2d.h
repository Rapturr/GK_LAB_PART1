#include "Primitiverenderer.h"

class Point2D{
private:
	sf::Vector2f point;
	PrimitiveRenderer prims;
public:
	sf::Vector2f getPos(){
		return point;
	}
	Point2D(){
	point.x = -1;
	point.y = -1;
	}
	void readC(sf::RenderWindow *window){
		sf::Vector2i pos = sf::Mouse::getPosition(*window);
		if(point.x < 0){
			point.x = pos.x;
			point.y = pos.y;
		}else
			modC(window);
	}
	void modC(sf::RenderWindow *window){
		sf::Vector2i pos = sf::Mouse::getPosition(*window);
		point.x = pos.x;
		point.y = pos.y;
		
		prims.makepoint(point);
	}
	void drawPoint(sf::RenderWindow *window){
		if(point.x>0 && point.x < 2000){
			prims.drawpoint(window);
		}
	}
};