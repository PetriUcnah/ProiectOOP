#pragma once
#include <iostream>

using namespace std;

class Permutare
{
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
	Permutare operator*(const Permutare&);
	bool operator==(const Permutare&);
	friend bool reallyIsPermutare(const Permutare&);
	friend bool isIdentity(const Permutare&);
	friend int factorPentruIdentitate(const Permutare&);
	friend int semnulPermutarii(const Permutare);
	friend istream& operator>>(istream&, Permutare&);
	friend ostream& operator<<(ostream&, const Permutare&);
};