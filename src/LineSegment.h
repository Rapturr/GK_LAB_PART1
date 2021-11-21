#include "Point2d.h"
class LineSegment{
private:
Point2D punkt1;
Point2D punkt2;
std::vector<sf::Vertex> lines;
bool ch;
PrimitiveRenderer prims;
Point2D punkt;

	void makeLine(sf::RenderWindow *window, int flag){
		int i = lines.size()-1;
		if(flag == 1)
			prims.makeline(lines);
			//prims.makeline(punkt1.getPos(),punkt2.getPos());
		else if(flag == 2)
			prims.makesfmlline(lines);
	}

	void makeLineln(sf::RenderWindow *window, int flag){
		int i = lines.size()-1;
		if(flag == 1)
			prims.makelineln(punkt1.getPos(),punkt2.getPos());
		else if(flag == 2)
			prims.makesfmllineln(punkt1.getPos(),punkt2.getPos());
	}
	void makefilledarea(sf::RenderWindow *window){
		int i = lines.size()-1;
		prims.makesfmlline(lines);
		if(i>2){
			prims.fillArea(sf::Color::Blue);
			std::cout<<"filling\n";
		}
	}

public:
	LineSegment(){
		ch = true;
	}
	//flag: 1-domyślny, 2-przyrostowy
	void readpoint(sf::RenderWindow *window, int flag){
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
		makeLine(window, flag);
	}
	
	void readpointln(sf::RenderWindow *window, int flag){
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
		makeLineln(window, flag);
	}

	void readpointfill(sf::RenderWindow *window){
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
		makefilledarea(window);
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