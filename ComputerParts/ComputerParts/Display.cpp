#include "Display.h"

Display::Display(int price, char* name, int numOfButtons){
	setType("Display");
	setPrice(price);
	setName(name);
	setNumOfButtons(numOfButtons);
}

bool Display::hasButtons() {
	return true;
}

bool Display::hasMemory() {
	return false;
}