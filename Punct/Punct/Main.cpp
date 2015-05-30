#include "Punct2D.h"
#include "Punct2DColorat.h"
#include <fstream>
#include<iostream>
#include <string.h>
#include <vector>
using namespace std;

void citirePuncte(vector<Punct2D*> &vectorP) {
	FILE *fis = fopen("punct.txt", "r");
	int x, y, aux;
	char culoare[20];
	while (!feof(fis)){
		if (fscanf(fis, "%d %d %d", &x, &y, &aux) == 3) {
			Punct2D *punct = new Punct2D(x, y);
			vectorP.push_back(punct);
			x = aux;
			while (!feof(fis) && fscanf(fis, "%d %d", &y, &aux) == 2) {
				punct = new Punct2D(x, y);
				vectorP.push_back(punct);
				x = aux;
			}
		}
		fscanf(fis, "%s", &culoare);
		Punct2DColorat *punct = new Punct2DColorat(culoare, x, y);
		vectorP.push_back(punct);
	}

	for (int i = 0; i < vectorP.size(); i++) {
		Punct2DColorat* punctCol = dynamic_cast<Punct2DColorat*>(vectorP[i]);
		if (punctCol != NULL) {
			if (punctCol->getX() > 0 && punctCol->getY() > 0) {
				cout << ((Punct2DColorat*)vectorP[i]);
			}
		}
	}
	cout << endl;
}

/*void afisareAlbeCadI(vector<Punct2D*> vectorP) {
	for (int i = 0; i < vectorP.size(); i++) {
		Punct2DColorat* punctCol = dynamic_cast<Punct2DColorat*>(vectorP[i]);
		if (punctCol != NULL) {
			if (punctCol->getX() > 0 && punctCol->getY() > 0) {
				cout << ((Punct2DColorat*)vectorP[i]);
			}
		}
	}
	cout << endl;
}*/

int main()
{
	vector<Punct2D*> vectorPuncte;

	citirePuncte(vectorPuncte);

	//afisareAlbeCadI(vectorPuncte);

	return 0;
}