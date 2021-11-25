#include "Point2d.h"

/** Klasa LineSegment
 * Odpowiada za rysowanie linii
 * @param punkt objekt klasy Point2D przechowuje współrzędne punktu w oknie
 * @param punkt1 objekt klasy Point2D przechowuje współrzędne punktu w oknie
 * @param punkt2 objekt klasy Point2D przechowuje współrzędne punktu w oknie
 * @param lines wektor przechowujący punkty wykorzystywane do stworzenia linii
 * @param ch pomaga w zapisywaniu współrzędnych linii
 * @param prims objekt typu PrimitiveRenderer, to w nim dochodzi do narysowania kształtów
*/
class LineSegment{
private:
Point2D punkt;
Point2D punkt1;
Point2D punkt2;
std::vector<sf::Vertex> lines;
bool ch;
PrimitiveRenderer prims;

/** Makeline
 * funkcja odpowiadająca za przełączanie pomiędzy rysowanie linii. Możemy ją rysować ręcznie albo za pomocą funkcji wbudowanych w silnik.
 * @param window wskaźnik na okno na którym jest wyświetlany obiekt
 * @param flag flaga która określa jakim spoosbem odbędzie się rysowanie linii
 * 
*/
	void makeLine(sf::RenderWindow *window, int flag){
		int i = lines.size()-1;
		if(flag == 1)
			prims.makeline(lines);
		else if(flag == 2)
			prims.makesfmlline(lines);
	}
	/** makeLineln 
	 * funkcja odpowiadająca za przełączanie pomiędzy rysowanie krzywej. Możemy ją rysować ręcznie albo za pomocą funkcji wbudowanych w silnik.
	 * @param window wskaźnik na okno na którym jest wyświetlany obiekt
 	 * @param flag flaga która określa jakim spoosbem odbędzie się rysowanie linii
	*/
	void makeLineln(sf::RenderWindow *window, int flag){
		int i = lines.size()-1;
		if(flag == 1)
			prims.makelineln(punkt1.getPos(),punkt2.getPos());
		else if(flag == 2)
			prims.makesfmllineln(punkt1.getPos(),punkt2.getPos());
	}
	/** Makeline
 	* Funkcja odpowiadająca za wypełnianie obszaru. 
	* @param window wskaźnik na okno na którym jest wyświetlany obiekt.
	*/
	void makefilledarea(sf::RenderWindow *window){
		int i = lines.size()-1;
		prims.makesfmlline(lines);
		if(i>2){
			prims.fillArea(sf::Color::Blue);
		}
	}

public:
	/** LineSegment() 
	 * Konstruktor klasy LineSegment
	*/
	LineSegment(){
		ch = true;
	}
	//flag: 1-domyślny, 2-przyrostowy
	/** readpoint
	 * służy do odczytania pozycji myszki i zapisania jej w wektorze
	 * wywołuje funkcję makeLine
	 * @param window wskaźnik na okno na którym jest wyświetlany obiekt
 	 * @param flag flaga która określa jakim spoosbem odbędzie się rysowanie linii
	*/
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
	
	/** readpointln
	 * służy do odczytania pozycji myszki i zapisania jej w wektorze
	 * wywołuje funkcję makeLineln
	 * @param window wskaźnik na okno na którym jest wyświetlany obiekt
 	 * @param flag flaga która określa jakim spoosbem odbędzie się rysowanie linii
	*/
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
	/** readpointfill
	 * służy do odczytania pozycji myszki i zapisania jej w wektorze
	 * wywołuje funkcję makefilledarea
	 * @param window wskaźnik na okno gry
	*/
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

	/** reset
	* funkcja odpowiada za rysownie linia na ekranie
	@param window wskaźnik na okno gry
	*/
	void drawLine(sf::RenderWindow *window){
		punkt1.drawPoint(window);
		punkt2.drawPoint(window);
		prims.drawline(window);
	}

	/** reset
	* funkcja odpowiada za sprzątanie linii z ekranu 
	*/
	void reset(){
		for(int i = 0; i < lines.size(); i++){
			lines.clear();
		}
		prims.clearLine();
	}
};