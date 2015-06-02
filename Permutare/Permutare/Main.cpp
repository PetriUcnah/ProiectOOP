#include <fstream>
#include <vector>
#include <time.h>
#include "Permutare.h"

using namespace std;

void citirePermutari(vector<Permutare> &vectorP)
{
	ifstream fin("permutare.txt");
	Permutare permAux;
	while (fin >> permAux) {
		vectorP.push_back(permAux);
	}
}

void afisareAnalizarePermutari(const vector<Permutare> vectorP)
{
	for (int i = 0; i < vectorP.size(); i++) {
		cout << vectorP[i];
		if (reallyIsPermutare(vectorP[i])) {
			cout << "Este permutare, ";
		}
		else {
			cout << "Nu este permutare, ";
		}
		if (isIdentity(vectorP[i])) {
			cout << "este identitate.";
		}
		else {
			cout << "nu este identitate.";
		}
		cout << endl;
	}
	cout << endl;
}

Permutare generarePermValida(int n)
{
	int *perm = new int[n];
	int *ap = new int[n];
	memset(perm, 0, n * sizeof(int));
	memset(ap, 0, n * sizeof(int));
	for (int i = 0; i < n; i++) {
		do {
			perm[i] = rand() % n + 1;
		} while (ap[perm[i] - 1] == 1);
		ap[perm[i] - 1] = 1;
	}
	Permutare newP(n, perm);
	return newP;
}

void generarePermutariValide(int nrPerm, int dimPerm)
{
	cout << "Permutari generate aleator:" << endl;
	for (int i = 0; i < nrPerm; i++) {
		Permutare pGenerata = generarePermValida(dimPerm);
		cout << pGenerata;
	}
	cout << endl;
	return;
}

void exempluInmultire()
{
	cout << "Introduceti 2 permutari de compus (numarul de elemente si vectorul permutarii):" << endl << endl;
	Permutare p1, p2, c;
	cin >> p1 >> p2;
	c = p1 * p2;
	cout << endl << "Rezultat:";
	cout << c;
	cout << endl;
	return;
}

void exempluFactorIdentitate()
{
	cout << endl << "Introduceti o permutare pentru aflarea factorului pentru identitate:" << endl << endl;
	Permutare p;
	cin >> p;
	if (factorPentruIdentitate(p) == 0) {
		cout << endl << "Nu se poate ajunge la identitate!";
		cout << endl << endl;
		return;
	}
	cout << endl << "Permutarea trebuie ridicata la puterea " << factorPentruIdentitate(p) << " pentru a ajunge la identitate";
	cout << endl << endl;
	return;
}

void exempluSemnPerm()
{
	cout << endl << "Introduceti o permutare pentru verificarea semnului:" << endl << endl;
	Permutare p;
	cin >> p;
	cout << endl << "Semnul permutarii este ";
	if (semnulPermutarii(p) < 0) {
		cout << "minus.";
	}
	else if (semnulPermutarii(p) > 0) {
		cout << "plus.";
	}
	else {
		cout << "necunoscut.";
	}
	cout << endl << endl;
	return;
}

int main()
{
	srand(time(NULL));

	vector<Permutare> vectorPerm;

	citirePermutari(vectorPerm);

	afisareAnalizarePermutari(vectorPerm);

	generarePermutariValide(3, 6);

	exempluInmultire();

	exempluFactorIdentitate();

	exempluSemnPerm();

	return 0;
}