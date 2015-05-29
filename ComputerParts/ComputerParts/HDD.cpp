#include "HDD.h"

HDD::HDD(int price, char* name, int capacity, int frequency){
	setType("HDD");
	setPrice(price);
	setName(name);
	setMemory(capacity, frequency);
}

bool HDD::hasButtons() {
	return false;
}

bool HDD::hasMemory() {
	return true;
}