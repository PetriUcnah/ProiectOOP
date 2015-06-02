#include <iostream>
#include "Permutare.h"

using namespace std;

Permutare::Permutare(){
	this->permutare = new int[2];
	memset(permutare, 0, sizeof(permutare));
}

Permutare::Permutare(int size, int* permutare){

	setSize(size);
	setPermutare(permutare);
}

Permutare::~Permutare(){
	delete[] permutare;
}

int Permutare::getSize(){
	return this->size;
}

void Permutare::setSize(int size){
	this->size = size;
}

int* Permutare::getPermutare(){
	return this->permutare;
}

void Permutare::setPermutare(int* permutare){
	this->permutare = permutare;
}

bool Permutare::isPermutare(){
	int *ap = new int[this->size];
	memset(ap,0,(size+1)*sizeof(ap));
	for (int i = 0; i < this->size; i++){
		ap[permutare[i]]++;
	}
	for (int i = 1; i <= this->size; i++){
		if (ap[i] != 1)
			return false;
	}
	return true;
}