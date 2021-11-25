#include "Primitiverenderer.h"

/** Point2D jest klasą przechowującą współrzędne punktu
 * @param point objekt typu sf::Vector2f przechowuje pozycje x i y punktu
 * @param prims objekt typu PrimitiveRenderer wykorzystywany do narysowania punkty na ekranie
*/
class Point2D{
private:
	sf::Vector2f point;
	PrimitiveRenderer prims;
public:
	/** 
	 * Konstruktor klasy Point2D
	*/
	Point2D(){
	point.x = -1;
	point.y = -1;
	}
	/** getPos
	 * funkcja zwracająca wektor pozycji punktu
	*/
	sf::Vector2f getPos(){
		return point;
	}
	/** readC
	 * odczytuje pozycje myszy
	 * @param window wskaźnik na okno gry
	*/
	void readC(sf::RenderWindow *window){
		sf::Vector2i pos = sf::Mouse::getPosition(*window);
		modC(window, pos);
	}
	/** modC
	 * modyfikuje pozycje punktu oraz wywołuje funkcję która zaznaczy ten punkt na ekranie
	 * @param window wskaźnik na okno gry
	 * @param pos pozycja myszy
	*/
	void modC(sf::RenderWindow *window, sf::Vector2i pos){
		point.x = pos.x;
		point.y = pos.y;
		
		prims.makepoint(point);
	}
	/** drawPoint
	 * wyświetla narysowany punkt
	 * @param window wskaźnik na okno gry
	*/
	void drawPoint(sf::RenderWindow *window){
		if(point.x>0 && point.x < 2000){
			prims.drawpoint(window);
		}
	}
};