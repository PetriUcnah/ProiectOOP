#include <iostream>
#include "Permutare.h"

using namespace std;

Permutare::Permutare()
{
	this->size = 0;
	this->permutare = new int[0];
}

Permutare::Permutare(int size, int* permutare)
{
	setSize(size);
	setPermutare(permutare);
}

int Permutare::getSize()
{
	return this->size;
}

void Permutare::setSize(int size)
{
	this->size = size;
}

int* Permutare::getPermutare()
{
	return this->permutare;
}

void Permutare::setPermutare(int* permutare)
{
	this->permutare = permutare;
}

Permutare Permutare::operator*(const Permutare& p2)
{
	if (this->size != p2.size || !reallyIsPermutare(*this) || !reallyIsPermutare(p2)) {
		cout << endl << "Nu se poate efectua inmultirea!" << endl;
		return *this;
	}
	int *perm = new int[this->size];
	for (int i = 0; i < this->size; i++) {
		perm[i] = p2.permutare[this->permutare[i] - 1];
	}
	Permutare rez(this->size, perm);
	return rez;
}

bool Permutare::operator==(const Permutare& p2)
{
	if (this->size != p2.size) {
		return false;
	}
	for (int i = 0; i < this->size; i++) {
		if (this->permutare[i] != p2.permutare[i]) {
			return false;
		}
	}
	return true;
}

bool reallyIsPermutare(const Permutare& p)
{
	int *ap = new int[p.size];
	memset(ap, 0, p.size * sizeof(int));
	for (int i = 0; i < p.size; i++) {
		if (p.permutare[i] > p.size) {
			delete ap;
			return false;
		}
		ap[p.permutare[i] - 1]++;
	}
	for (int i = 0; i < p.size; i++) {
		if (ap[i] != 1) {
			delete ap;
			return false;
		}
	}
	delete ap;
	return true;
}

bool isIdentity(const Permutare& p)
{
	for (int i = 0; i < p.size; i++) {
		if (p.permutare[i] - 1 != i) {
			return false;
		}
	}
	return true;
}

int factorPentruIdentitate(const Permutare& p)
{
	int k = 1;
	Permutare p2(p);
	while (!isIdentity(p2)) {
		p2 = p2 * p;
		k++;
		if (p2 == p) {
			return 0;
		}
	}
	return k;
}

int semnulPermutarii(const Permutare p)
{
	int nrInv = 0;
	for (int i = 0; i < p.size; i++) {
		if (p.permutare[i] != i + 1) {
			int aux = p.permutare[i] - 1;
			p.permutare[i] = p.permutare[p.permutare[i] - 1];
			p.permutare[aux] = aux + 1;
			nrInv++;
		}
	}
	if (!isIdentity(p)) {
		cout << "S-a intamplat ceva neasteptat!";
		return 0;
	}
	if (nrInv % 2 == 0) {
		return 1;
	}
	return -1;
}

istream& operator>>(istream& in, Permutare& p)
{
	in >> p.size;
	p.permutare = new int[p.size];
	for (int i = 0; i < p.size; i++) {
		in >> p.permutare[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const Permutare& p)
{
	out << endl;
	for (int i = 0; i < p.size; i++) {
		out << i + 1 << " ";
	}
	out << endl;
	for (int i = 0; i < p.size; i++) {
		out << p.permutare[i] << " ";
	}
	out << endl;
	return out;
}