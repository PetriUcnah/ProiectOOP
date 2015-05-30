# include <iostream>
# include <math.h>
# include <string.h>
# include <vector>
using namespace std;
# define pi 3.14159;

class figura
{
protected:
	char denumire[50];
public:
	virtual float arie() = 0;
	virtual float perim() = 0;
	char *getdenumire()
	{
		return denumire;
	}
};


class elipsa : public figura
{
protected:
	float x, y, Rx, Ry;
public:
	elipsa(float x, float y, float Rx, float Ry)
	{
		this->x = x;
		this->y = y;
		this->Rx = Rx;
		this->Ry = Ry;
		strcpy_s(denumire, "elipsa");
	}
	float arie()
	{
		return Rx*Ry*pi;
	}
	float perim()
	{
		return (Rx + Ry)*pi;
	}
};

class poligon : public figura
{
protected:
	int n;
	float x[1000], y[1000];
public:
	poligon(int N, float *X, float *Y)
	{
		if (N <= 2 || N > 1000)
			throw "Numar de varfuri invalid";
		n = N;
		for (int i = 0; i < n; i++)
		{
			x[i] = X[i];
			y[i] = Y[i];
		}
		strcpy_s(denumire, "poligon");
	}
	float perim()
	{
		double s = 0;
		for (int i = 0; i < n - 1; i++)
			s += sqrt((x[i + 1] - x[i])*(x[i + 1] - x[i]) + (y[i + 1] - y[i])*(y[i + 1] - y[i]));
		s += sqrt((x[n - 1] - x[0])*(x[n - 1] - x[0]) + (y[n - 1] - y[0])*(y[n - 1] - y[0]));
		return s;
	}
	float arie()
	{
		double s = 0;
		for (int i = 0; i < n; i++)
			s += x[i + 1] * y[i] - x[i] * y[i + 1];
		s += x[0] * y[n - 1] - x[n - 1] * y[0];
		return fabs(s / 2);
	}
};

class cerc : public elipsa
{
protected:
	float x, y, R;
public:
	cerc(float X, float Y, float Rx) :elipsa(X, Y, Rx, Rx)
	{
		x = X;
		y = Y;
		this->Rx = Rx;
		strcpy_s(denumire, "cerc");
	}
	float arie()
	{
		return elipsa::arie();
	}
	float perim()
	{
		return elipsa::perim();
	}
};

class patrulater : public poligon
{
protected:
	float x1, x2, x3, x4, y1, y2, y3, y4;
public:
	patrulater(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4) :poligon(4, x, y)
	{
		x[0] = X1;
		x[1] = X2;
		x[2] = X3;
		x[3] = X4;
		y[0] = Y1;
		y[1] = Y2;
		y[2] = Y3;
		y[4] = Y4;
		strcpy_s(denumire, "patrulater");
	}
	float arie()
	{
		return poligon::arie();
	}
	float perim()
	{
		return poligon::perim();
	}
};

class trapez : public patrulater
{
protected:
	float x1, x2, x3, x4, y1, y2;
public:
	trapez(float X1, float Y1, float X2, float Y2, float X3, float X4) : patrulater(X1, Y1, X2, Y1, X3, Y2, X4, Y2)
	{
		x1 = X1;
		x2 = X2;
		x3 = X3;
		x4 = X4;
		y1 = Y1;
		y2 = Y2;
		strcpy_s(denumire, "trapez");
	}
	float arie()
	{
		return fabs((((x2 - x1) + (x4 - x3))*(y1 - y2)) / 2);
	}
	float perim()
	{
		return patrulater::perim();
	}
};

class trapez_isoscel :public trapez
{
protected:
	float x1, x2, x3, x4, y1, y2;
public:
	trapez_isoscel(float X1, float Y1, float X2, float Y2, float X3, float X4) : trapez(X1, Y1, X2, Y1, X3, Y2)
	{
		x1 = X1;
		x2 = X2;
		x3 = X3;
		x4 = X4;
		y1 = Y1;
		y2 = Y2;
		strcpy_s(denumire, "trapez isoscel");
	}
	float arie()
	{
		return fabs((((x2 - x1) + (x4 - x3))*(y1 - y2)) / 2);
	}
	float perim()
	{
		return fabs((x2 - x1) + (x4 - x3) + 2 * sqrt((x3 - x1)*(x3 - x1) + (y2 - y1)*(y2 - y1)));
	}
};

class trapez_dreptunghic :public trapez
{
protected:
	float x1, x2, x3, y1, y2;
public:
	trapez_dreptunghic(float X1, float Y1, float X2, float Y2, float X3) : trapez(X1, Y1, X2, Y1, X3, Y2)
	{
		x1 = X1;
		x2 = X2;
		x3 = X3;
		y1 = Y1;
		y2 = Y2;
		strcpy_s(denumire, "trapez dreptunghic");
	}
	float arie()
	{
		return fabs((((x2 - x1) + (x3 - x1))*(y1 - y2)) / 2);
	}
	float perim()
	{
		return trapez::perim();
	}
};

class paralelogram :public patrulater
{
protected:
	float x1, x2, y1, y2, l;
public:
	paralelogram(float X1, float Y1, float X2, float Y2, float L) : patrulater(X1, Y1, X2, Y1, X1 + l, Y2, X2 + l, Y2)
	{
		x1 = X1;
		x2 = X2;
		y1 = Y1;
		y2 = Y2;
		l = L;
		strcpy_s(denumire, "paralelogram");
	}
	virtual float arie()
	{
		return fabs((x2 - x1)*(y1 - y2));
	}
	virtual float perim()
	{
		return patrulater::perim();
	}
};

class dreptunghi : virtual public paralelogram
{
protected:
	float x1, x2, y1, y2;
public:
	dreptunghi(float X1, float Y1, float X2, float Y2) : paralelogram(X1, Y1, X2, Y2, 0)
	{
		x1 = X1;
		x2 = X2;
		y1 = Y1;
		y2 = Y2;
		strcpy_s(denumire, "dreptunghi");
	}
	virtual float arie()
	{
		return paralelogram::arie();
	}
	virtual float perim()
	{
		return 2 * fabs((x2 - x1) + (y2 - y1));
	}
};

class romb : virtual public paralelogram
{
protected:
	float x1, x2, y1, y2;
public:
	romb(float X1, float X2, float Y1, float Y2) :paralelogram(X1, Y1, X2, Y2, 0)
	{
		x1 = X1;
		x2 = X2;
		y1 = Y1;
		y2 = Y2;
		strcpy_s(denumire, "romb");
	}
	virtual float arie()
	{
		return fabs(2 * (x2 - x1)*(y2 - y1)) / 2;
	}
	virtual float perim()
	{
		return fabs(((4 * (y2 - y1)*(x2 - x1)))) / 2;
	}
};

class patrat : public dreptunghi, public romb
{
protected:
	float x, y, l;
public:
	patrat(float X, float Y, float L) : dreptunghi(X, Y, X + L, Y + L), romb(X, Y, X + L, Y + L), paralelogram(X, Y, X + L, Y + L, 0)
	{
		x = X;
		y = Y;
		l = L;
		strcpy_s(denumire, "patrat");
	}
	virtual float arie()
	{
		return dreptunghi::arie();
	}
	virtual float perim()
	{
		return 4 * l;
	}
};

class triunghi : public poligon
{
protected:
	float x1, x2, x3, y1, y2, y3;
public:
	triunghi(float X1, float Y1, float X2, float Y2, float X3, float Y3) : poligon(3, x, y)
	{
		x[0] = X1;
		x[1] = X2;
		x[2] = X3;
		y[0] = Y1;
		y[1] = Y2;
		y[2] = Y3;
		strcpy_s(denumire, "triunghi");
	}
	virtual float arie()
	{
		return poligon::arie();
	}
	virtual float perim()
	{
		return poligon::perim();
	}
};

class triunghi_dreptunghic : virtual public triunghi
{
protected:
	float x1, x2, y1, y2;
public:
	triunghi_dreptunghic(float X1, float Y1, float X2, float Y2) : triunghi(X1, Y1, X2, Y2, X1, Y2)
	{
		x1 = X1;
		x2 = X2;
		y1 = Y1;
		y2 = Y2;
		strcpy_s(denumire, "triunghi dreptunghic");
	}
	virtual float arie()
	{
		return fabs((x2 - x1)*(y2 - y1)) / 2;
	}
	virtual float perim()
	{
		return triunghi::perim();
	}
};

class triunghi_isoscel : virtual public triunghi
{
protected:
	float x1, x2, y1, y2;
public:
	triunghi_isoscel(float X1, float Y1, float X2, float Y2) : triunghi(X1, Y1, X2, Y1, (X1 + X2) / 2, Y2)
	{
		x1 = X1;
		x2 = X2;
		y1 = Y1;
		y2 = Y2;
		strcpy_s(denumire, "triunghi isoscel");
	}
	virtual float arie()
	{
		return fabs(2 * (x2 - x1)*(y2 - y1)) / 2;
	}
	virtual float perim()
	{
		return triunghi::perim();
	}
};

class triunghi_echilateral : public triunghi_isoscel
{
protected:
	float x1, x2, y1, y2;
public:
	triunghi_echilateral(float X1, float X2, float Y1, float Y2) : triunghi_isoscel(X1, Y1, X2, Y2), triunghi(X1, Y1, X2, Y2, (X1 + X2) / 2, (sqrt(3) / 2)*(fabs(X2 - X1)))
	{
		x1 = X1;
		x2 = X2;
		y1 = Y1;
		y2 = Y2;
		strcpy_s(denumire, "triunghi echilateral");
	}
	float arie()
	{
		return triunghi_isoscel::arie();
	}
	float perim()
	{
		return 3 * (2 * fabs((x2 - x1)));
	}
};

class triunghi_dreptunghic_isoscel : public triunghi_dreptunghic, public triunghi_isoscel
{
protected:
	float x1, x2, y1;
public:
	triunghi_dreptunghic_isoscel(float X1, float Y1, float X2) :triunghi_dreptunghic(X1, Y1, X2, Y1), triunghi_isoscel(X1, Y1, X2, Y1), triunghi(X1, Y1, X2, Y1, X1, X2)
	{
		x1 = X1;
		y1 = Y1;
		x2 = X2;
		strcpy_s(denumire, "triunghi dreptunghic isoscel");
	}
	virtual float arie()
	{
		return triunghi_dreptunghic::arie();
	}
	virtual float perim()
	{
		return triunghi_isoscel::perim();
	}
};


void main()
{
	vector<figura*> vectorFiguri;

	vectorFiguri.push_back(new cerc(2, 3, 6));
	vectorFiguri.push_back(new dreptunghi(4, 5, 8, 10));
	vectorFiguri.push_back(new patrat(3, 6, 7));
	vectorFiguri.push_back(new trapez_isoscel(-5, 4, 3, -2, 6, 8));
	vectorFiguri.push_back(new triunghi_dreptunghic(-2, 6, 1, 2));
	vectorFiguri.push_back(new patrulater(-6, -8, 4, 6, 2, -2, -1, 3));
	vectorFiguri.push_back(new romb(10, 12, -5, 18));
	vectorFiguri.push_back(new triunghi_echilateral(-8, 10, 6, -12));
	vectorFiguri.push_back(new elipsa(-3, 6, 4, 7));
	float *x = new float[5], *y = new float[5];
	x[0] = 2; x[1] = 6; x[2] = -2; x[3] = 1; x[4] = 8;
	y[0] = -2; y[1] = -3; y[2] = 6; y[3] = 7; y[4] = -5;
	vectorFiguri.push_back(new poligon(5, x, y));
	vectorFiguri.push_back(new paralelogram(2, -7, -2, 7, 3));
	vectorFiguri.push_back(new triunghi_isoscel(2, 3, -1, 2));

	for (int i = 0; i < vectorFiguri.size(); i++) {
		figura* figuraCurenta = vectorFiguri[i];
		if (figuraCurenta->arie() > 40) {
			cout << figuraCurenta->getdenumire() << " cu aria = " << figuraCurenta->arie() << endl << endl;
		}
	}
}






