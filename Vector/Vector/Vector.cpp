/*
1.Sa se efectueze produsul scalar dintre vectorul cu norma cea mai mare si vectorul cu norma cea mai mica
2.Sa se sorteze vectorii in functie de elementul maxim din fiecare vector
3.Sa se afiseze intr-un alt fisier text doar vectorii care respecta conditia:
au elementele crescatoare pana la un anumit punct si apoi descrescator
4.Sa se afle cosinusul dintre primii vectori de dimensiune k din sir
v1*v2/||v1|| * ||v2||
*/

#include "Vector.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;

Vector::Vector(){
	n=0;
	a=new int[100];
	memset(a,0,100*sizeof(a));
}

Vector::~Vector(){
	delete [] a;
}

int Vector:: samesizeas(int k){
	if(n==k)
		return 1;
	return 0;
}
int Vector:: calculMaxim(){
	int maxim=-999999;
	int maxi;
	for(int i=0;i<n;i++){
		if(maxim<a[i]){
			maxim=a[i];
			maxi=i;
		}
	}
	return maxi;
}
Vector::Vector(const Vector &p){

	this->n=p.n;
	this->a=new int[100];
	for(int i=0;i<p.n;i++)
		this->a[i]=p.a[i];
}

Vector Vector:: operator+(const Vector &p){
	
	Vector tmp;
	tmp.n=n;
	tmp.a=new int[tmp.n];
	for(int i=0;i<tmp.n;i++)
		tmp.a[i]=this->a[i]+p.a[i];
	return tmp;
}

ostream & operator<<(ostream &f1,Vector &p){
	for(int i=0;i<p.n;i++){
		 f1<<p.a[i]<<" ";
	}
	return f1;
}

void Vector:: operator =(Vector &p){
	
	this->n=p.n;
	this->a=new int[100];
	for(int i=0;i<p.n;i++)
		this->a[i]=p.a[i];
}

istream & operator >>( istream &f1,Vector &p){
	f1>>p.n;
	for(int i=0;i<p.n;i++){
		f1>>p.a[i];
	}
	return f1;
}

double Vector:: norma(Vector &p){
	double rezultat=0;
	for(int i=0;i<p.n;i++){
		rezultat+=(p.a[i]*p.a[i]);
	}
	return sqrt(rezultat);
}

bool sortFunction(Vector c1,Vector c2){
	if(c1.geta()[c1.calculMaxim()]>c2.geta()[c1.calculMaxim()]){
		return false;
	}
	return true;
}
void cerinta1(Vector *p,int size){
	double maxim=-999999;
	int maxi;
	double minim=999999;
	int mini;
	double rezultat;
	for(int i=0;i<size;i++){
		rezultat=p[i].norma(p[i]);
		if(rezultat>maxim)
		{
			maxim=rezultat;
			maxi=i;
		}
		if(rezultat<minim)
		{
			minim=rezultat;
			mini=i;
		}
	}
	int vectorMax=0;
	if(p[maxi].getn()>p[mini].getn())
		vectorMax=p[maxi].getn();
	else
		vectorMax=p[mini].getn();
	rezultat=0;
	for(int i=0;i<vectorMax;i++){
		rezultat+=(p[maxi].geta()[i]+p[mini].geta()[i]);
	}
	cout<<"Cerinta 1: "<<rezultat<<endl;

}

void cerinta2(Vector *b,int size){
	cout<<"Cerinta 2:"<<endl;
	sort(b,b+size,sortFunction);
	for(int i=0;i<size;i++){
		cout<<b[i]<<endl;
	}
}

void cerinta3(Vector *b,int size){
	cout<<"Cerinta3:"<<endl;
	for(int i=0;i<size;i++){
		int maxim=b[i].calculMaxim();
		if(maxim==0 || maxim==b[i].getn()-1)
			return;
		for(int j=maxim;j>0;j--)
			if(b[i].geta()[j]<=b[i].geta()[j-1])
				return;
		for(int j=maxim;j<b[i].getn()-1;j++)
			if(b[i].geta()[j]<=b[i].geta()[j+1])
				return;
		cout<<b[i]<<endl;			
	}
}

void cerinta4(Vector *b,int size,int k){
	int first=0;
	int second=0;
	int ok=0;
	for(int i=0;i<size;i++){
		if(b[i].getn()==k){
			if(ok==0){
				first=i;
				ok=1;
			}
			else{
				second=i;
				break;
			}
		}
	}
	int vectorMax=0;
	if(b[first].getn()>b[second].getn())
		vectorMax=b[first].getn();
	else
		vectorMax=b[second].getn();
	int rezultat=0;
	for(int i=0;i<vectorMax;i++){
		rezultat+=(b[first].geta()[i]+b[second].geta()[i]);
	}
	double cosinus=rezultat/(b[first].norma(b[first])*b[second].norma(b[first]));
	cout<<"Cerinta 4:"<<cosinus<<endl;

}
int main(){

	ifstream fin("vector.txt");
	int k;
	fin>>k;
	Vector *b;
	b=new Vector[50];
	int size=0;
	while(fin>>b[size]){
		size++;
		cout<<b[size-1];
		cout<<endl;
	}
	Vector suma;
	suma.setn(k);
	for(int i=0;i<size;i++){
		if(b[i].getn()==k){
			suma=suma+b[i];
		}
	}
	cout<<suma<<endl;
	cerinta1(b,size);
	cerinta2(b,size);
	cerinta3(b,size);
	cerinta4(b,size,k);
	return 0;
}