#include "Punct2D.h"
#include "Punct2DColorat.h"
#include <fstream>
#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

	ifstream fin("punct.txt");
	char citire[50];
	int x=0,y=0,ok=0,vectorSize=0;
	char culoare[20];
	vector <Punct2DColorat*> vector2DColorat;
	memset(culoare,0,sizeof(culoare));
	while(fin.getline(citire,50)){
		int nr=0;
		bool negativex=false;
		bool negativey=false;
		x=0;
		y=0;
		ok=0;
		for(int i=0;i<strlen(citire);){
			if(citire[i]=='-'){
				if(ok==0)
					negativex=true;
				else
					negativey=true;
				i++;
			}
			if(citire[i]==' '){
				ok=1;
				i++;
			}
			while(isdigit(citire[i])){
				if(ok==0)
					x=x*10+citire[i]-'0';
				else
					y=y*10+citire[i]-'0';
			    i++;
			}
			if(isalpha(citire[i])){
				culoare[nr++]=citire[i];
				i++;
			}
		}
		if(negativex==true){
			x=x*(-1);
		}
		if(negativey==true){
			y=y*(-1);
		}
			if(nr!=0){
				string culoare1(culoare);
				Punct2DColorat *vector2D=new Punct2DColorat(culoare1,x,y);
				vector2DColorat.push_back(vector2D);
				vectorSize++;
			}
	}
	for(int i=0;i<vector2DColorat.size();i++){
		if(vector2DColorat[i]->getCuloare()=="alb" && vector2DColorat[i]->getX()>0 && vector2DColorat[i]->getY()>0){
			cout<<"X:"<<vector2DColorat[i]->getX()<<endl;
			cout<<"Y:"<<vector2DColorat[i]->getY()<<endl;
			cout<<"Culoare:"<<vector2DColorat[i]->getCuloare()<<endl;
		}
	}
	return 0;
}