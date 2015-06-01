#include <iostream>
#include "Permutare.h"

using namespace std;

Permutare:: Permutare(){
	this->permutare=new int*[2];
	memset(permutare,0,sizeof(permutare));
}

Permutare::Permutare(int size, int ** permutare){

	this->size=size;
	for(int i=0;i<2;i++){
		this->permutare[i]=new int[size];
		for(int j=0;j<this->size;j++)
			this->permutare[i]=permutare[i];
	}
}

Permutare::~Permutare(){
	for(int i=0;i<2;i++){
        delete []permutare[i];
    }
    delete []permutare;
}

int Permutare::getSize(){
	return this->size;
}

void Permutare::setSize(int size){
	this->size=size;
}

int ** Permutare::getPermutare(){
	return this->permutare;
}

void Permutare::setPermutare(int ** permutare){
	for(int i=0;i<2;i++){
		this->permutare[i]=new int[size];
		for(int j=0;j<this->size;j++)
			this->permutare[i]=permutare[i];
	}
}

bool Permutare::isPermutare(){
	int *ap=new int[this->size];
	for(int i=0;i<this->size-1;i++){
		if(permutare[0][i]!=permutare[0][i+1]-1)
			return false;
		ap[permutare[1][i]]++;
	}
	for(int i=0;i<this->size;i++){
		if(ap[i]==0 || ap[i]>1)
			return false;
	}
	return true;
}