#include "ComputerPart.h"
#include "HasButtons.h"
#include "HasMemory.h"

int ComputerPart::getPrice(){
	return price;
}

char* ComputerPart::getName(){
	return name;
}

void ComputerPart::setName(char* name){
	this->name = name;
}

void ComputerPart::setPrice(int price){
	this->price = price;
}

void ComputerPart::setType(char* type) {
	this->type = type;
}

char* ComputerPart::getType() {
	return type;
}