#include "ExternalHDD.h"


ExternalHDD::ExternalHDD(int price, int capacity, int frequency, int numOfButtons,string name){
	setType("External HDD");
	setPrice(price);
	setName(name);
	setMemory(capacity, frequency);
	setNumOfButtons(numOfButtons);
}