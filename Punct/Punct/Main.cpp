#include "Punct2D.h"
#include "Punct2DColorat.h"
#include <fstream>
#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	FILE *fis = fopen("punct.txt", "r");
	int x, y, aux = 0;
	char culoare[20];

	//am incercat sa le pun pe toate intr-un singur vector.
	//aceeasi problema, nu stiu apoi cum sa le separ unele de altele.
	//le-am pus separat, vom modifica.

	vector <Punct2D*> vectorPuncte;
	vector <Punct2DColorat*> vectorPuncteColorate;

	while (!feof(fis)){
		if (fscanf(fis, "%d %d %d", &x, &y, &aux) == 3) {
			Punct2D *punct = new Punct2D(x, y);
			vectorPuncte.push_back(punct);
			x = aux;
			while (!feof(fis) && fscanf(fis, "%d %d", &y, &aux) == 2) {
				punct = new Punct2D(x, y);
				vectorPuncte.push_back(punct);
				x = aux;
			}
		}
		fscanf(fis, "%s", &culoare);
		Punct2DColorat *punct = new Punct2DColorat(culoare, x, y);
		vectorPuncteColorate.push_back(punct);
	}
	for (int i = 0; i < vectorPuncteColorate.size(); i++) {
		if (vectorPuncteColorate[i]->getX() > 0 && vectorPuncteColorate[i]->getY() > 0 && vectorPuncteColorate[i]->getCuloare() == "alb")
			cout << *vectorPuncteColorate[i];
	}
	cout << endl;
	return 0;
}