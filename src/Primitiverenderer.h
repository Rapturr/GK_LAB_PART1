#include "Player.h"

/** PrimitiveRenderer
 * odpowiada za tworzenie i rysowanie punktów linii i figur
 * @param fillshape objekt typu ConvexShape służący do narysowania krzywej wypełnionej
 * @param vertices Obiekt typu vertexArray, który wykorzystujemy do narysowania linii i krzywej
 * @param lines Obiekt typu vertexArray, który wykorzystujemy do narysowania linii i krzywej
 * @param point obiekt typu Vertex, który wykorzystujemy do narysowania koła i elipsy
 * @param linesvector wektor obiektów Vertex, który jest wykorzystywany do narysowania linii i krzywej
 * @param linesvectorfill wektor obiektów Vertex, który jest wykorzystywany do narysowania Krzywej wypełnionej
 * @param circlevector wektor obiektów Vertex, który jest wykorzystywany do narysowania koła
 * @param ellipssevector wektor obiektów Vertex, który jest wykorzystywany do narysowania elipsy
*/
class PrimitiveRenderer{ 
private:
	sf::ConvexShape fillshape;
	sf::VertexArray vertices;
	sf::VertexArray lines;
	sf::Vertex point;
	std::vector<sf::Vertex> linesvector;
	std::vector<sf::Vertex> linesvectorfill;
	std::vector<sf::Vertex> circlevector;
	std::vector<sf::Vertex> elipssevector;
public:
	/** makeline
	 * służy do sworzenia krzywej
	 * @param line wektor punktów typu Vertex
	*/
	void makeline(std::vector<sf::Vertex> line){
		linesvector.clear();
		lines.resize(line.size());
		for(int ln = 0; ln < line.size()-1; ln++){

		int x = line[ln].position.x; //pos1.x;
		int y = line[ln].position.y;
		int x1 = line[ln+1].position.x;
		int y1 = line[ln+1].position.y;
		if(x>x1){
			int tempx = x;
			x = x1;
			x1 = tempx;
			int tempy = y;
			y = y1;
			y1 = tempy;
		}
		

		if(x<x1 && y<y1){

			//std::cout<<std::endl<<(x1-x)/(y1-y)<<std::endl;
			if( (y1-y)/(x1-x) < 1 ){

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
	}
	/** makeline
	 * służy do sworzenia linii prostej
	 * @param pos1 pozycja pierwszego punktu
	 * @param pos2 pozycja ostatniego punktu
	*/
	void makelineln(sf::Vector2f pos1, sf::Vector2f pos2){
		linesvector.clear();
		int x = pos1.x; //pos1.x;
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

			//std::cout<<std::endl<<(x1-x)/(y1-y)<<std::endl;
			if( (y1-y)/(x1-x) < 1 ){

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
	/** drawline
	 * rysuje stworzone linie
	 * @param window wskaźnik na okno gry
	*/
	void drawline(sf::RenderWindow *window){
		//std::cout<<"rysuje sie\n";
		//window->draw(vertices);
		
		window->draw(&linesvector[0],linesvector.size(),sf::LineStrip);
		window->draw(fillshape);
		//window->draw(&linesvectorfill[0],linesvectorfill.size(),sf::LineStrip);
	}
	/** drawRectangle
	 * Rysuje prostokat
	 * @param window wskaźnik na okno gry
	 * @param posx pozycja x prostokata
	 * @param posy pozycja y prostokata
	 * @param sizex rozmiar x prostokata
	 * @param sizey rozmiar y prostokata
	*/
	void drawRectangle(sf::RenderWindow *window, int posx, int posy, int sizex, int sizey){
		sf::RectangleShape rectangle(sf::Vector2f(sizex,sizey));
		rectangle.setPosition(sf::Vector2f(posx,posy));
		rectangle.setFillColor(sf::Color::Red);
		window->draw(rectangle);
	}

	/** makeCircle
	 * Tworzy kolo
	 * @param center pozycja środka kola
	 * @param radius promień koła
	*/
	void makeCircle(sf::Vector2f center, float radius){
		circlevector.resize(500);
		for(float i = 0 ;i<3.14/2;i += 0.01){
			circlevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x + (radius * std::cos(i))), ((int)center.y + (radius * std::sin(i)))),sf::Color::Black));
			circlevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x - (radius * std::cos(i))), ((int)center.y + (radius * std::sin(i)))),sf::Color::Black));
			circlevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x + (radius * std::cos(i))), ((int)center.y - (radius * std::sin(i)))),sf::Color::Black));
			circlevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x - (radius * std::cos(i))), ((int)center.y - (radius * std::sin(i)))),sf::Color::Black));
		}
	}
	/** drawCircle
	 * rysuje koło
	 * @param window wskaźnik na okno gry
	 */
	void drawCircle(sf::RenderWindow *window){
		window->draw(&circlevector[0],circlevector.size(),sf::Points);
	}

	/** makeElipsse
	 * Tworzy elipsę
	 * @param center pozycja środka elipsy
	 * @param radiusx promień x
	 * @param radiusy promień y
	*/
	void makeElipsse(sf::Vector2f center, float radiusx, float radiusy){
		circlevector.resize(500);
		for(float i = 0 ;i<3.14/2;i += 0.01){
			elipssevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x + (radiusx * std::cos(i))), ((int)center.y + (radiusy * std::sin(i)))),sf::Color::Black));
			elipssevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x - (radiusx * std::cos(i))), ((int)center.y + (radiusy * std::sin(i)))),sf::Color::Black));
			elipssevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x + (radiusx * std::cos(i))), ((int)center.y - (radiusy * std::sin(i)))),sf::Color::Black));
			elipssevector.push_back(sf::Vertex(sf::Vector2f((int)(center.x - (radiusx * std::cos(i))), ((int)center.y - (radiusy * std::sin(i)))),sf::Color::Black));
		}
	}
	
	/** drawElipsse
	 * Rysuje elipsę
	 * @param window wskaźnik na okno gry
	*/
	void drawElipsse(sf::RenderWindow *window){

		window->draw(&elipssevector[0],elipssevector.size(),sf::Points);

	}

	/** makepoint
	 * Tworzy punkt
	 * @param p wektor pozycji punktu
	*/
	void makepoint(sf::Vector2f p){
		point.position = p;
		point.color = sf::Color(sf::Color::Black);
	}
	/** drawpoint
	 * rysuje punkt
	 * @param window wskaźnik na okno gry
	*/
	void drawpoint(sf::RenderWindow *window){
		window->draw(&point, 1, sf::Points);
	}
	/** makesfmlline
	 * tworzy krzywą za pomocą funkcji wbudowanej w sfml
	 * @param line wektor objektow Vertex
	*/
	void makesfmlline(std::vector<sf::Vertex> line){
		linesvector.clear();
		lines.resize(line.size());
		for(int i = 0; i < line.size(); i++){
			lines[i].position = line[i].position;
			lines[i].color = sf::Color(rand()%255,rand()%255,rand()%255);
			linesvector.push_back(lines[i]);
		}
	}
	/** makesfmllineln
	 * tworzy line za pomocą funkcji wbudowanej w sfml
	 * @param pos1 pozycja startowa/poprzednia
	 * @param pos2 pozycja kolejna/ostatnia
	*/
	void makesfmllineln(sf::Vector2f pos1, sf::Vector2f pos2){
		linesvector.clear();
		sf::Vertex vert;
		vert.position.x = pos1.x;
		vert.position.y = pos1.y;
		vert.color = sf::Color(rand()%255,rand()%255,rand()%255);
		linesvector.push_back(vert);
		vert.position.x = pos2.x;
		vert.position.y = pos2.y;
		vert.color = sf::Color(rand()%255,rand()%255,rand()%255);
		linesvector.push_back(vert);
	}

	/** clearLine
	 * usuwa narysowane linie
	*/
	void clearLine(){
		lines.clear();
		linesvector.clear();
		fillshape.setPointCount(0);
	}
	
	/** fillArea
	 * służy do stworzenia krzywej wypełnionej
	 * @param myColor kolor wypełnienia
	*/
	void fillArea(sf::Color myColor){
		linesvectorfill = linesvector;
		fillshape.setPointCount(linesvectorfill.size());
		//fillshape.resize(linesvectorfill.size());
		for(int i = 0; i < linesvectorfill.size(); i++){
			fillshape.setPoint(i, linesvectorfill[i].position);
			fillshape.setOutlineColor(myColor);
			fillshape.setFillColor(myColor);
		}
	}
};