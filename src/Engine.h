#include "LineSegment.h"

/** Klasa Engine
 * Glowna klasa silnika, Wywołuje metody związane z silnikiem
 * @param window jest obiektem klasy sf::RenderWindow, służy do stworzenia okna silnika.
 * @param currsize przechowuje aktualny rozmiar okna
 * @param originalsize przechowuje oryginalny rozmiar okna
 * @param line z jego pomocą tworzymy linie, jest to objekt typu LineSegment
 * @param line1 z jego pomocą tworzymy linie, jest to objekt typu LineSegment
 * @param line2 z jego pomocą tworzymy linie, jest to objekt typu LineSegment
 * @param evnt Obsługuje zdarzenia
 * @param kolo z jego pomocą tworzymy koła i elipsy, jest to objekt typu PrimitiveRenderer
 * @param linebool wskazuje na typ rysowanej linii
 * @param player obiekt typu Player służy do stworzenia i poruszania się postaci
 * 
*/
class Engine{
private:
sf::RenderWindow window;
sf::Vector2u currsize;
sf::Vector2u originalsize;
LineSegment line;
LineSegment line1;
LineSegment line2;
sf::Event evnt;
PrimitiveRenderer kolo;
bool linebool = false;
Player player;
public:
	/** Konstruktor klasy Engine
	 * tutaj obslugiwana jest glowna petla programu
	 * Tworzone oraz konfigurowane jest okno silnika
	*/
	Engine(int width, int height){
		window.create(sf::VideoMode(width,height),"Tower Defense", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
		window.setKeyRepeatEnabled(false);
		window.setFramerateLimit(30);
		originalsize = sf::Vector2u(width, height);
	}
	/** gamescreen
	 * główna pętla silnika, działa kiedy okno jest otwarte.
	*/
	void gamescreen(){
		while(window.isOpen()){
			while (window.pollEvent(evnt)){
				// Close window: exit
				if(evnt.type == evnt.Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
					currsize = window.getSize();
					if(currsize == originalsize){
						window.create(sf::VideoMode(1920,1080),"Tower Defense", sf::Style::Fullscreen);
					}
					else{
						window.create(sf::VideoMode(originalsize.x,originalsize.y),"Tower Defense", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
						window.setPosition(sf::Vector2i(0,0));
					}
					window.setFramerateLimit(30);
				}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
				if(linebool)
					line.readpoint(&window, 1);
				else{
					line.readpointln(&window, 1);
				}
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
				if(linebool)
					line1.readpoint(&window, 2);
				else{
					line1.readpointln(&window, 2);
				}
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
				line2.readpointfill(&window);
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				line.reset();
				line1.reset();
				line2.reset();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
				line.reset();
				line1.reset();
				linebool = !linebool;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
				kolo.makeElipsse(sf::Vector2f(100,500),50,60);
				kolo.makeCircle(sf::Vector2f(500,200),60);
			}
			
			window.clear(sf::Color::White);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				player.move();
				player.animate(&window);
			}
			else{
				player.draw(&window);
			}

			line.drawLine(&window);
			line1.drawLine(&window);
			line2.drawLine(&window);
			

			kolo.drawElipsse(&window);
			kolo.drawCircle(&window);

			window.display();
		}
	}
};