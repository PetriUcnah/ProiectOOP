#pragma once
#include <iostream>

using namespace std;

class Permutare{

private:
	int size;
	int *permutare;

protected:
	void setSize(int);
	void setPermutare(int*);
public:
	int* getPermutare();
	int getSize();
	Permutare();
	Permutare(int, int*);
	~Permutare();
	bool isPermutare();
	bool isIdentitate();

};