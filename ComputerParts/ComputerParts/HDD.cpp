#include "HDD.h"

HDD::HDD(int price, char *name, int capacity, int frequency){
	setPrice(price);
	setName(name);
	setMemory(capacity, frequency);
}