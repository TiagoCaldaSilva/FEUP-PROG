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

void e()
{
	double a, b, c, d, e, f;
	cout << "a= "; cin >> a;
	cout << "b= "; cin >> b;
	cout << "c= "; cin >> c;
	cout << "d= "; cin >> d;
	cout << "e= "; cin >> e;
	cout << "f= "; cin >> f;
	if (a * e == b * d){
		cout << "Invalid input.";
	}
	else {
		cout << "x = " << (c * e - b * f) / (a * e - b * d) << "\ny = " << (a * f - c * d) / (a * e - b * d);
	}
}

int main()
{
	e();
	return 0;
}