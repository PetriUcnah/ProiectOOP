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

int main(){
	const char computerPart[5][20]={"ExternalHDD","HDD","Mouse","Keyboard","Display"};
	const string names[5] ={"Samsung","Kingston","A4Tech","Logitech","LG"};
	cout<<"Introduceti numarul de componente:";
	int numberOfParts;
	cin>>numberOfParts;
	ComputerPart **computerPartVector=new ComputerPart*[numberOfParts];
	srand(time(NULL));
	for(int i=0;i<numberOfParts;i++){
		int randomComputerPart=rand() %5;
		int randomPartName=rand()%5;
		int randomPrice=rand()%100;
		int randomFrequency=rand()%100;
		int randomCapacity=rand()%1024;
		int randomNumberOfButtons=rand()%20;
		switch(randomComputerPart){
			case 0:{
				computerPartVector[i]=new ExternalHDD(randomPrice,randomCapacity,randomFrequency,randomNumberOfButtons,names[randomPartName]);
				break;
			}
			case 1:{
				computerPartVector[i]=new HDD(randomPrice,names[randomPartName],randomCapacity,randomFrequency);
				break;
			}
			case 2:{
			
				computerPartVector[i]=new Mouse(randomPrice,names[randomPartName],randomNumberOfButtons);
				break;
			}
			case 3:{
				computerPartVector[i]= new Keyboard(randomPrice,names[randomPartName],randomNumberOfButtons);
				break;
			}
			case 4:{
				computerPartVector[i]=new Display(randomPrice,names[randomPartName],randomNumberOfButtons);
				break;
			}	 
		}
	}
	HasButtons *hasButtonsVector=new HasButtons[numberOfParts];
	HasMemory *hasMemoryVector=new HasMemory[numberOfParts];
	int nr=0;
	for(int i=0;i<numberOfParts;i++){
		cout<<typeid(*computerPartVector[i]).name()<<endl;
		if(typeid(Keyboard)==typeid(*computerPartVector[i])){
			//hasButtonsVector[i]=computerPartVector[i];
		}
		if(typeid(Mouse)==typeid(*computerPartVector[i])){
			//
		}
		if(typeid(HDD)==typeid(*computerPartVector[i])){
			//
		}
		if(typeid(ExternalHDD)==typeid(*computerPartVector[i])){
			//
		}
		if(typeid(Display)==typeid(*computerPartVector[i])){
			//
		}
	}
	return 0;
}