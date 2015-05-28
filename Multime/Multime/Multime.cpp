#include "Multime.h"


Multime::Multime(int n, int e[1000])
{
	this->n = n;
}

Multime::Multime()
{
	this->n = 0;
}

int part(int st, int dr, Multime &A)
{
	int aux, i = st, j = dr, p = A.e[st];
	while (i < j)
	{
		while (A.e[i] < p)
			i++;
		while (A.e[j] > p)
			j--;
		if (i<j)
		{
			aux = A.e[i];
			A.e[i] = A.e[j];
			A.e[j] = aux;
			i++;
			j--;
		}
	}
	if (i == j && A.e[i] > p)
		return j - 1;
	return j;
}

void sort(int st, int dr, Multime &A)
{
	int k;
	if (st < dr)
	{
		k = part(st, dr, A);
		sort(st, k, A);
		sort(k + 1, dr, A);
	}
}

int cautbin(int x, int st, int dr, Multime A)
{
	if (st == dr)
	{
		if (A.e[st] == x) return 1;
		else return 0;
	}
	int m = (st + dr) / 2;
	if (A.e[m] == x) return 1;
	if (x < A.e[m])
		return cautbin(x, st, m, A);
	return cautbin(x, m + 1, dr, A);
}

Multime Multime::operator +(Multime &A)
{
	int i;
	Multime C; C.n = 0;
	if (A.n < n)
	{
		for (i = 0; i < A.n; i++)
			C.e[C.n++] = A.e[i];
		sort(0, A.n - 1, A);
		for (i = 0; i < n; i++)
			if ((cautbin(e[i], 0, A.n - 1, A)) == 0)
				C.e[C.n++] = e[i];
	}
	else
	{
		for (i = 0; i < n; i++)
			C.e[C.n++] = e[i];
		sort(0, n - 1, *this);
		for (i = 0; i < A.n; i++)
			if ((cautbin(A.e[i], 0, n - 1, *this)) == 0)
				C.e[C.n++] = A.e[i];

	}
	if (C.n>1000) throw "reuniunea : prea multe elemente!";
	return C;
}

Multime Multime::operator- (Multime &B) {
	Multime C;
	for (int i = 0; i < n; i++) {
		if (cautbin(e[i], 0, B.n - 1, B) == 0) {
			C.e[C.n++] = e[i];
		}
	}
	return C;
}

Multime Multime::operator*(Multime &B) {
	Multime C;
	if (B.n < n) {
		for (int i = 0; i < B.n; i++) {
			if (B.e[i] < *this) {
				C.e[C.n++] = B.e[i];
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++) {
			if (e[i] < B) {
				C.e[C.n++] = e[i];
			}
		}
	}
	return C;
}

Multime Multime::operator- (int x) {
	Multime C;
	for (int i = 0; i < n; i++) {
		if (e[i] != x) {
			C.e[C.n++] = e[i];
		}
	}
	return C;
}

int operator !(Multime A)
{
	return A.n;
}

int Multime::operator== (Multime B) {
	if (!*this != !B){
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (!(e[i] < B)) {
			return 0;
		}
	}
	return 1;
}

int Multime::operator!= (Multime B) {
	return !(*this == B);
}

int Multime::operator< (Multime A) {
	for (int i = 0; i < n; i++) {
		if (!(e[i] < A)) {
			return 0;
		}
	}
	return 1;
}

int Multime::operator> (Multime B) {
	return B < (*this);
}

int Multime::operator<=(Multime B) {
	return *this == B;
}

int Multime::operator>=(Multime B) {
	return *this == B;
}

void Multime::operator +=(Multime B) {
	*this = *this + B;
}

void Multime::operator -=(Multime B) {
	*this = *this - B;
}

void Multime::operator *=(Multime B) {
	*this = *this * B;
}

int verif(Multime A)
{
	sort(0, A.n - 1, A);
	for (int i = 0; i < A.n - 1; i++)
		if (A.e[i] == A.e[i + 1]) return 0;
	return 1;
}

void main()
{
	int x;
	Multime a, b, c;

	cout << "dati prima multime (numarul elem si multimea) " << endl;
	cin >> a;
	if (!verif(a)) throw "se repeta elemente";
	if (a.n > 1000) throw "prea multe elemente";
	sort(0, a.n - 1, a);

	cout << "dati cea de a doua multime (numarul elem si multimea) " << endl;
	cin >> b;
	if (!verif(b)) throw "se repeta elemente";
	if (b.n > 1000) throw "prea multe elemente";
	sort(0, b.n - 1, b);
	cout << endl;

	cout << "multimea A: " << a << endl;
	cout << "multimea B: " << b << endl << endl;

	c = a;
	c += b;
	sort(0, c.n - 1, c);
	cout << "reuniunea este " << c << endl << endl;

	x = !a;
	cout << "numarul de elem al multimii A este: " << x << endl;
	cout << "numarul de elem al multimii B este: " << !b << endl << endl;

	Multime Y = a;
	Y -= b;
	cout << "diferenta dintre multimile A si B este: " << Y << endl << endl;

	Multime X = a;
	X *= b;
	cout << "intersectia multimilor A si B este: " << X << endl << endl;

	Multime Z = a - 2;
	cout << "multimea A fara elementul 2 este: " << Z << endl << endl;

	cout << "multimea A este egala cu multimea B? " << ((a == b) ? "da" : "nu") << endl << endl;

	cout << "multimea A este diferita de multimea B? " << ((a != b) ? "da" : "nu") << endl << endl;

	cout << "multimea A este inclusa in multimea B? " << ((a < b) ? "da" : "nu") << endl << endl;

	cout << "multimea A este inclusa strict in multimea B? " << ((a <= b) ? "da" : "nu") << endl << endl;

	cout << "multimea A include multimea B? " << ((a > b) ? "da" : "nu") << endl << endl;

	cout << "multimea A include strict multimea B? " << ((a >= b) ? "da" : "nu") << endl << endl;
}
