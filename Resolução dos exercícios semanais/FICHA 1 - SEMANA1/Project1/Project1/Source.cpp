#define _USE_MATH_DEFINES
#include<cmath>
#include <iostream>

using namespace std;


void Asci_Value() // 1.1
{
	char a_;
	cout << "Enter a character: " << endl;
	cin >> a_;
	cout << int(a_) << endl;
}

void Integer() // 1.2
{
	double a, b, c, m;
	cout << "Please, input 3 integer numbers: " << endl;
	cout << "A? "; cin >> a;
	cout << "B? "; cin >> b;
	cout << "C? "; cin >> c;
	m = double((a + b + c) / 3);
	cout << "mean = " << m << endl;
	cout << "A-mean = " << a - m << endl;
	cout << "B-mean = " << b - m << endl;
	cout << "C-mean = " << c - m << endl;
}

void mass_sphere() // 1.3
{
	double p, r, M;
	cout << "Please introduce the specific mass of the material from which it is made in Kg/m^3: "; cin >> p;
	cout << "Please introduce the value of the radius of the sphere in meters: "; cin >> r;
	M = (4.0 / 3.0) * (p * M_PI * pow(r, 3));
	cout << "M = " << M;
}

void equation() // 1.4
{
	double a, b, c, d, e, f;
	cout << "a= "; cin >> a;
	cout << "b= "; cin >> b;
	cout << "c= "; cin >> c;
	cout << "d= "; cin >> d;
	cout << "e= "; cin >> e;
	cout << "f= "; cin >> f;
	if (a * e == b * d) {
		cout << "Invalid input.";
	}
	else {
		cout << "x = " << (c * e - b * f) / (a * e - b * d) << "\ny = " << (a * f - c * d) / (a * e - b * d);
	}
}

void time() // 1.5 a)
{
	int h, m, s, hh, mm, ss, d, sf, hf, mf;
	cout << "Time1 (hours minutes seconds) ? "; cin >> h >> m >> s;
	cout << "Time2 (hours minutes seconds) ? "; cin >> hh >> mm >> ss;
	sf = s + ss;
	mf = m + mm;
	hf = h + hh;
	if ((s + ss) >= 60) {
		mf += (s + ss) / 60;
	}
	sf = sf % 60;
	if (mf >= 60){
		hf += mf / 60;
	}
	mf = mf % 60;
	if (hf >= 24){
		d = hf / 24;
	}
	hf = hf % 24;
	cout << "Time1 + Time2 = " << d << " day, " << hf << " hours, " << mf << " minutes and " << sf << " seconds";
}

void time2() // 1.5 b)
{
	int h, m, s, hh, mm, ss, d, sf, hf, mf;
	cout << "Time1 (hours minutes seconds) ? "; cin >> h; cin.ignore(1, ' '); cin >> m; cin.ignore(1, ' '); cin >> s;
	cout << "Time2 (hours minutes seconds) ? "; cin >> hh; cin.ignore(1, ' '); cin >> mm; cin.ignore(1, ' '); cin >> ss;
	sf = s + ss;
	mf = m + mm;
	hf = h + hh;
	if ((s + ss) >= 60) {
		mf += (s + ss) / 60;
	}
	sf = sf % 60;
	if (mf >= 60) {
		hf += mf / 60;
	}
	mf = mf % 60;
	if (hf >= 24) {
		d = hf / 24;
	}
	hf = hf % 24;
	cout << "Time1 + Time2 = " << d << " day, " << hf << " hours, " << mf << " minutes and " << sf << " seconds";
}

void Herons_formula() // 1.6
{
	double x1, x2, x3, y1, y2, y3, d1_2, d2_3, d3_1, p, a;
	cout << "Please enter the coordenates os the 3 vertices of a triange.\nGive the coordenates in that way: (x1,y1), (x2,y2), (x3,y2). "; cin.ignore(1, ' '); cin >> x1; cin.ignore(1, ' '); cin >> y1; cin.ignore(4, '_'); cin >> x2; cin.ignore(1, '_'); cin >> y2; cin.ignore(4, '_'); cin >> x3; cin.ignore(1, '_'); cin >> y3; cin.ignore(1, ' ');
	d1_2 = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), (1. / 2));
	d2_3 = pow(pow(x3 - x2, 2) + pow(y3 - y2, 2), (1. / 2));
	d3_1 = pow(pow(x1 - x3, 2) + pow(y1 - y3, 2), (1. / 2));
	p = (d1_2 + d2_3 + d3_1) / 2.0;
	a = pow(p * (p - d1_2) * (p - d2_3) * (p - d3_1), (1. / 2));
	cout << "Area = " << a;
}

int main()
{
	Herons_formula();
	return 0;
}