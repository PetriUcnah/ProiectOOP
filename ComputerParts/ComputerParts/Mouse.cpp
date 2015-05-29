#include "Mouse.h"


Mouse::Mouse(int price, char* name, int numOfButtons){
	setType("Mouse");
	setPrice(price);
	setName(name);
	setNumOfButtons(numOfButtons);
}

bool Mouse::hasButtons() {
	return true;
}

bool Mouse::hasMemory() {
	return false;
}