#include "HDD.h"

HDD::HDD(int price, string name, int capacity, int frequency){
	setType("HDD");
	setPrice(price);
	setName(name);
	setMemory(capacity, frequency);
}