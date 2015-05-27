#include "ExternalHDD.h"

ExternalHDD::ExternalHDD(int price, char *name, int capacity, int frequency, int numOfButtons){
	setPrice(price);
	setName(name);
	setMemory(capacity, frequency);
	setNumOfButtons(numOfButtons);
}