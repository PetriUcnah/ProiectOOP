#include <iostream>
#include <conio.h>
using namespace  std;
class Multime
{
public:
	int n, e[1000];

public:
	Multime(int n, int e[1000]);
	Multime();
	friend int part(int st, int dr, Multime &A);
	friend void sort(int st, int dr, Multime &A);
	friend int cautbin(int x, int st, int dr, Multime A);

	Multime operator+(Multime &);
	Multime operator-(Multime &);
	Multime operator*(Multime &);
	Multime operator-(int);

	friend int operator!(Multime A);

	int operator ==(Multime B);
	int operator !=(Multime B);

	int operator <(Multime A);
	friend int operator <(int x, Multime A)
	{
		int ok = 1;
		sort(0, A.n - 1, A);
		if (!cautbin(x, 0, A.n - 1, A)) ok = 0;
		return ok;
	}

	int operator >(Multime B);
	int operator <=(Multime B);

	int operator >=(Multime B);

	void operator +=(Multime B);
	void operator -=(Multime B);
	void operator *=(Multime B);

	friend int verif(Multime A);

	friend istream& operator>>(istream &is, Multime &A)

	{
		is >> A.n;
		for (int i = 0; i < A.n; i++)
			is >> A.e[i];
		return is;
	}
	friend ostream& operator<<(ostream &os, Multime A)
	{
		for (int i = 0; i < A.n; i++)
			os << A.e[i] << " ";
		return os;
	}
};