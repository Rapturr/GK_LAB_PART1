#include "Engine.h"

/** main()
 * Funkcja main, tutaj wywołuje się ekran silnika graficznego
 * @param silnik jest obiektem klasy Engine
 * @param Engine jest klasą która przechowuje i wywołuje wszystkie metody związane z silnikiem.
*/
int main(){
	Engine silnik(1280,720);

	silnik.gamescreen();
	
	return EXIT_SUCCESS;
}