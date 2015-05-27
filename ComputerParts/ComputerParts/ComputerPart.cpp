#include "ComputerPart.h"

int ComputerPart::getPrice(){
	return price;
}

char * ComputerPart:: getName(){
	return name;
}

void ComputerPart:: setName(char *name){
	this->name=name;
}

void ComputerPart:: setPrice(int price){
	this->price=price;
}