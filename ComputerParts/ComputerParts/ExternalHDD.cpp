#include "ExternalHDD.h"


ExternalHDD::ExternalHDD(int price, int capacity, int frequency, int numOfButtons, char* name){
	setType("External HDD");
	setPrice(price);
	setName(name);
	setMemory(capacity, frequency);
	setNumOfButtons(numOfButtons);
}

bool ExternalHDD::hasButtons() {
	return true;
}

bool ExternalHDD::hasMemory() {
	return true;
}