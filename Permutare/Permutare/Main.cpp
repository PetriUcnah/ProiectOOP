#include <fstream>
#include "Permutare.h"

using namespace std;

int main(){
	ifstream fin("permutare.txt");
	int nrPermutari;
	int permutareSize;
	fin>>nrPermutari;
	Permutare *permutareArray;
	int **permutareAux;
	permutareAux=new int*[2];
	for(int i=0;i<nrPermutari;i++){
		fin>>permutareSize;
		for(int j=0;j<2;j++){
			permutareAux[j]=new int[permutareSize];
			for(int k=0;k<permutareSize;k++){
				fin>>permutareAux[j][k];
			}
		}
		permutareArray[i]=new Permutare(permutareSize,permutareAux);

	}
	return 0;
}