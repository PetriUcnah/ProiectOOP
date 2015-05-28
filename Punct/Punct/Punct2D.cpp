#include "Punct2D.h"
#include <iostream>

using namespace std;

Punct2D::Punct2D(int x,int y){
	setX(x);
	setY(y);
}

int Punct2D::getX(){
	return this->x;
}

int Punct2D::getY(){
	return this->y;
}

void Punct2D::setX(int x){
	this->x=x;
}

void Punct2D::setY(int y){
	this->y=y;
}
