#include "Point2d.h"
class LineSegment{
private:
Point2D punkt1;
Point2D punkt2;
std::vector<sf::Vertex> lines;
bool ch;
PrimitiveRenderer prims;
Point2D punkt;
public:
	LineSegment(){
		ch = true;
	}
	void readpoint(sf::RenderWindow *window){
		punkt.readC(window);
		sf::Vertex tmp(punkt.getPos());
		lines.push_back(tmp);
		if(ch){
			punkt1.readC(window);
			ch = false;
		}
		else{
			punkt2.readC(window);
			ch = true;
		}
	}
	//flag: 1-domyślny, 2-przyrostowy
	void makeLine(sf::RenderWindow *window, int flag){
		int i = lines.size()-1;
		if(flag == 1)
			prims.makeline(punkt1.getPos(),punkt2.getPos());
		else if(flag == 2)
			prims.makesfmlline(lines);
	}
	void drawLine(sf::RenderWindow *window){
		punkt1.drawPoint(window);
		punkt2.drawPoint(window);
		prims.drawline(window);
	}
	void reset(){
		for(int i = 0; i < lines.size(); i++){
			lines.clear();
		}
		prims.clearLine();
	}
};