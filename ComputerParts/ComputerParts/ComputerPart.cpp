#include "ComputerPart.h"
#include "HasButtons.h"
#include "HasMemory.h"

int ComputerPart::getPrice(){
	return price;
}

string ComputerPart::getName(){
	return name;
}

void ComputerPart::setName(string name){
	this->name = name;
}

void ComputerPart::setPrice(int price){
	this->price = price;
}

void ComputerPart::setType(string type) {
	this->type = type;
}

string ComputerPart::getType() {
	return type;
}