#include "Keyboard.h"

Keyboard::Keyboard(int price, char* name, int numOfButtons){
	setType("Keyboard");
	setPrice(price);
	setName(name);
	setNumOfButtons(numOfButtons);
}

bool Keyboard::hasButtons() {
	return true;
}

bool Keyboard::hasMemory() {
	return false;
}