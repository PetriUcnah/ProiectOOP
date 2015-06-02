#include <fstream>
#include <vector>
#include "Permutare.h"

using namespace std;

void cerinta1(vector <Permutare*> vectorPerm){
	
	for(int i=0;i<vectorPerm.size();i++){
		if(vectorPerm[i]->isPermutare()==true){
			cout<<"Permutare valida"<<endl;
		}
		else{
			cout<<"Permutare invalida"<<endl;
		}
	}
}

int main(){
	ifstream fin("permutare.txt");
	int nrPermutari;
	int permutareSize;
	fin >> nrPermutari;
	vector<Permutare*> vectorPerm;
	int *permutareAux;
	for (int i = 0; i < nrPermutari; i++){
		fin >> permutareSize;
		permutareAux = new int[permutareSize];
		for (int k = 0; k < permutareSize; k++)
			fin >> permutareAux[k];
		vectorPerm.push_back(0);
		vectorPerm[i] = new Permutare(permutareSize, permutareAux);
	}
	cerinta1(vectorPerm);
	return 0;
}