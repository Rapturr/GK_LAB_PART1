#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine.h"

int main(){
	engine silnik;

	silnik.gamescreen(1280,720);
	
	return EXIT_SUCCESS;
}