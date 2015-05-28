#pragma once
#include <iostream>

using namespace std;

class Vector{
private:
	int n;
	int *a;

public:
	Vector();
	Vector(int);
	~Vector();
	int sameSizeAs(int k);
	int getn(){
		return n;
	}
	int *geta(){
		return a;
	}
	void setn(int n){
		this->n = n;
	}
	void seta(int *a){
		this->a = a;
	}
	Vector suma(Vector &p);
	Vector(const Vector &p);
	Vector operator +(const Vector &);
	void operator =(Vector &);
	friend ostream & operator<<(ostream &fl, Vector &p);
	friend istream & operator>>(istream &fl, Vector &p);
	int calculMaxim();
	double norma(Vector &p);
};