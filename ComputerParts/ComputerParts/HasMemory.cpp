#include "HasMemory.h"

void HasMemory:: setMemory(int capacity, int frequency){
	this->capacity = capacity;
	this->frequency = frequency;
}

int HasMemory::getCapacity() {
	return this->capacity;
}

int HasMemory::getFrequency() {
	return this->frequency;
}