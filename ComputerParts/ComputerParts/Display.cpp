#include "Display.h"

Display::Display(int price,string name, int numOfButtons){
	setType("Display");
	setPrice(price);
	setName(name);
	setNumOfButtons(numOfButtons);
}