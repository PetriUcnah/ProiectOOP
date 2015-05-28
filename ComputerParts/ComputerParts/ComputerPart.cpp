#include "ComputerPart.h"

int ComputerPart::getPrice(){
	return price;
}

string ComputerPart:: getName(){
	return name;
}

void ComputerPart:: setName(string name){
	this->name=name;
}

void ComputerPart:: setPrice(int price){
	this->price=price;
}