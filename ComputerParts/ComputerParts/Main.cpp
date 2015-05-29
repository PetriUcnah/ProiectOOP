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

void toPrint(ComputerPart* part) {
	cout << part->getName() << " " << part->getType() << endl;

	HasMemory* partWithMemory = dynamic_cast<HasMemory*>(part);
	if (partWithMemory != NULL) {
		cout << "\tMemory capacity :\t" << partWithMemory->getCapacity() << "MB" << endl;
		cout << "\tMemory frequency :\t" << partWithMemory->getFrequency() << "Hz" << endl;
	}

	HasButtons* partWithButtons = dynamic_cast<HasButtons*>(part);
	if (partWithButtons != NULL) {
		cout << "\tNumber of buttons :\t" << partWithButtons->getNumOfButtons() << endl;
	}
	cout << "\t\tPrice :\t$" << part->getPrice() << endl << endl;
}

void generateParts(vector<ComputerPart*> &computerParts) {
	char* computerPart[5] = { "ExternalHDD", "HDD", "Mouse", "Keyboard", "Display" };
	char* names[5] = { "Samsung", "Kingston", "A4Tech", "Logitech", "LG" };
	cout << "Enter number of parts: ";
	int numberOfParts;
	cin >> numberOfParts;
	cout << endl;
	srand(time(NULL));
	for (int i = 0; i < numberOfParts; i++){
		int randomComputerPart = rand() % 5;
		int randomPartName = rand() % 5;
		int randomPrice = rand() % 100;
		int randomFrequency = rand() % 1000 + 1000;
		int randomCapacity = rand() % 1000 + 1000;
		int randomNumberOfButtons = rand() % 19 + 1;
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
		computerParts.push_back(part);
	}
}

void separateParts(vector<ComputerPart*> initialVector, vector<HasMemory*> &partsWithMemory, vector<HasButtons*> &partsWithButtons) {
	for (int i = 0; i < initialVector.size(); i++){
		HasMemory* partWithMemory = dynamic_cast<HasMemory*>(initialVector[i]);
		if (partWithMemory != NULL) {
			partsWithMemory.push_back(partWithMemory);
		}

		HasButtons* partWithButtons = dynamic_cast<HasButtons*>(initialVector[i]);
		if (partWithButtons != NULL) {
			partsWithButtons.push_back(partWithButtons);
		}
	}
}

bool memoryCriteria(HasMemory* first, HasMemory* second) {
	if (first->getCapacity() > second->getCapacity()) {
		return true;
	}
	return false;
}

bool buttonsCriteria(HasButtons* first, HasButtons* second) {
	if (first->getNumOfButtons() > second->getNumOfButtons()) {
		return true;
	}
	return false;
}

void sortVectors(vector<HasMemory*> &partsWithMemory, vector<HasButtons*> &partsWithButtons) {
	sort(partsWithMemory.begin(), partsWithMemory.end(), memoryCriteria);
	sort(partsWithButtons.begin(), partsWithButtons.end(), buttonsCriteria);
}

template <class type>
void showVector(vector<type> partVector) {
	for (int i = 0; i < partVector.size(); i++) {
		ComputerPart* part = dynamic_cast<ComputerPart*>(partVector[i]);
		toPrint(part);
	}
}

int main() {
	vector<ComputerPart*> computerPartVector;

	generateParts(computerPartVector);

	vector<HasMemory*> hasMemoryVector;
	vector<HasButtons*> hasButtonsVector;

	separateParts(computerPartVector, hasMemoryVector, hasButtonsVector);

	sortVectors(hasMemoryVector, hasButtonsVector);

	cout << "Sorted parts with memory:" << endl << endl;
	showVector(hasMemoryVector);
	cout << "Sorted parts with buttons:" << endl << endl;
	showVector(hasButtonsVector);

	return 0;
}