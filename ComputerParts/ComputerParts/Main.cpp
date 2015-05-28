#include <iostream>
#include "ComputerPart.h"
#include "Display.h"
#include "ExternalHDD.h"
#include "HasButtons.h"
#include "HasMemory.h"
#include "HDD.h"
#include "Keyboard.h"
#include "Mouse.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>
#include <typeinfo>

using namespace std;

void toPrint(ComputerPart& part) {
	cout << part.getName() << " " << part.getType() << " (" << typeid(part).name() << ")" << endl;

	//daca se poate converti la obiect de tip HasMemory
	if (HasMemory* partWithMemory = dynamic_cast<HasMemory*>(&part)) {
		cout << "\tMemory capacity :\t" << partWithMemory->getCapacity() << "MB" << endl;
		cout << "\tMemory frequency :\t" << partWithMemory->getFrequency() << "Hz" << endl;
	}				//niciodata nu se intra in if-urile astea 2.
					//	asta e exact ce trebuie rezolvat pentru ca sa putem sa impartim vectorul in cele 2 parti.
	//daca se poate converti la obiect de tip HasButtons
	if (HasButtons* partWithButtons = dynamic_cast<HasButtons*>(&part)) {
		cout << "\tNumber of buttons :\t" << partWithButtons->getNumOfButtons() << endl;
	}
	cout << "\t\tPrice :\t$" << part.getPrice() << endl << endl;
}

int main(){
	const char computerPart[5][20] = { "ExternalHDD", "HDD", "Mouse", "Keyboard", "Display" };
	const string names[5] = { "Samsung", "Kingston", "A4Tech", "Logitech", "LG" };
	cout << "Introduceti numarul de componente:";
	int numberOfParts;
	cin >> numberOfParts;
	vector<ComputerPart*> computerPartVector;
	srand(time(NULL));
	for (int i = 0; i < numberOfParts; i++){
		int randomComputerPart = rand() % 5;
		int randomPartName = rand() % 5;
		int randomPrice = rand() % 100;
		int randomFrequency = rand() % 1000 + 1000;
		int randomCapacity = rand() % 1000 + 1000;
		int randomNumberOfButtons = rand() % 20;
		ComputerPart *part;
		switch (randomComputerPart){
		case 0: {
			part = new ExternalHDD(randomPrice, randomCapacity, randomFrequency, randomNumberOfButtons, names[randomPartName]);
			break;
		}
		case 1: {
			part = new HDD(randomPrice, names[randomPartName], randomCapacity, randomFrequency);
			break;
		}
		case 2: {
			part = new Mouse(randomPrice, names[randomPartName], randomNumberOfButtons);
			break;
		}
		case 3: {
			part = new Keyboard(randomPrice, names[randomPartName], randomNumberOfButtons);
			break;
		}
		case 4: {
			part = new Display(randomPrice, names[randomPartName], randomNumberOfButtons);
			break;
		}
		}
		computerPartVector.push_back(part);
	}

	vector<HasButtons*> hasButtonsVector;
	vector<HasMemory*> hasMemoryVector;
	cout << "Your computer parts:" << endl << endl;
	for (int i = 0; i < numberOfParts; i++){
		toPrint(*computerPartVector[i]);
	}
	return 0;
}