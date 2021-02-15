#define _USE_MATH_DEFINES
#include <iostream>	// o normal
#include <climits>	//limite de unsigned long
#include <time.h>	//para ver o tempo
#include <stdlib.h>	//system(pause)
#include <math.h>	//pi
#include <assert.h> 
using namespace std;
//#include <stdlib.h>


double distance(double x1, double y1, double x2, double y2) //3.1
{
	return pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) //3.1
{
	double d1, d2, d3, s, a;
	d1 = distance(x1, y1, x2, y2);
	d2 = distance(x2, y2, x3, y3);
	d3 = distance(x1, y1, x3, y3);
	s = (d1 + d2 + d3) / 2;
	a = pow(s * (s - d1) * (s - d2) * (s - d3), 0.5);
	cout << a << endl;
	return a;
}

bool isPrime(unsigned long x) //3.2 a)
{
	unsigned long i;
	bool prime = true;
	if (x < 2)
		prime = false;
	else
	{
		for (i = 2; i <= pow(x, 0.5); i++)
			if (x % i == 0)
			{
				prime = false;
				break;
			}
	}
	//if (prime)
	//	cout << "The number " << x << " is prime." << endl;
	//else
	//	cout << "The number " << x << " isn't prime." << endl;
	return prime;
}

void Primex() //3.2 b)
{
	int i;
	for (i = 0; i < 1000; i++)
	{
		if (isPrime(i))
			cout << i << endl;
	}
}

void Primec() //3.2 c)
{
	double i, k = 0;
	for (i = 0; i <= 100; i++)
	{
		while (isPrime(k) != 1)
		{
			k++;
		}
		cout << k << endl;
		k++;
	}
}

unsigned long MPrime() //3.2 d)
{
	unsigned long x = ULONG_MAX;
	for (x; x >= 0; x--)
	{
		if (isPrime(x) == 1)
			return x;
	}
}

double square_root(double x, double prec, int max)
{
	int m = 0;
	double rq = 1, rqn = 0, diff = 10000000000000;
	while ((m <= max) && (prec < abs(diff)))
	{
		rqn = (rq + x / rq) / 2;
		diff = x - pow(rqn, 2);
		m++;
		rq = rqn;
	}
	return rqn;
}

double sq() //3.3
{
	int nMaxIter;
	double delta, n;
	cout << "Please, enter the maxium number of iterations. "; cin >> nMaxIter;
	cout << "Please, enter the delta that you desire. "; cin >> delta;
	cout << "Now, enter the number that you desire to calculate the square root. "; cin >> n;
	return square_root(n, delta, nMaxIter);

}

double round(double x, unsigned n)
{
	return (int(x * pow(10, n) + 0.5) / pow(10, n));
}

void roundd() //3.4
{
	double x;
	unsigned n;
	cout << "Please give a number that you want to round. "; cin >> x;
	cout << "Please give a number of decimal places that you want to round your numeber. "; cin >> n;
	cout << round(x, n) << endl;
}

unsigned int GDC_R(unsigned int x, unsigned int y) //3.5
{
	unsigned int min, max, a;
	if (x == y)
		return x;
	else if (x == 0)
		return y;
	else if (y == 0)
		return x;
	if (x < y)
	{
		min = x;
		max = y;
	}
	else
	{
		min = y;
		max = x;
	}
	while (max != min)
	{
		max -= min;
		if (max < min)
		{
			a = max;
			max = min;
			min = a;
		}
	}
	return max;
}

void GDC_N(unsigned int x, unsigned int y, unsigned int& gdc)
{
	unsigned int min, max, a;
	if (x == y)
	{
		gdc = x;
	}
	else if (x == 0)
	{
		gdc = y;
	}
	else if (y == 0)
	{
		gdc = x;
	}
	else
	{
		if (x < y)
		{
			min = x;
			max = y;
		}
		else
		{
			min = y;
			max = x;
		}
		while (max != min)
		{
			max -= min;
			if (max < min)
			{
				a = max;
				max = min;
				min = a;
			}
		}
		gdc = max;
	}
}

unsigned int GDC()
{
	unsigned int n1, n2, gdc = 0;
	cout << "Please give a number. "; cin >> n1;
	cout << "Please give another number. "; cin >> n2;
	return GDC_R(n1, n2);
	//GDC_N(n1, n2, gdc);
	//return gdc;
}

time_t timeElapsed()
{
	int n, i;
	cout << "How mny times you desire to call your function? "; cin >> n;
	time_t start = time(NULL);
	for (i = 0; i < n; i++)
	{
		cout << time(NULL) - start << endl;
		system("pause");
	}
	return 0;
}

bool readInt(int& x) //3.7
{
	bool ValidInput = true;
	cout << "Please give a number. "; cin >> x;
	if (cin.fail())
	{
		ValidInput = false;
	}
	else if (cin.peek() != '\n')
	{
		ValidInput = false;
	}
	cin.ignore(1000000000000000, '\n');
	return ValidInput;
}

bool readFraction(int& numerator, int& denominator) //3.7 a)
{
	char barra;
	bool ValidInput = true;
	cin >> numerator >> barra >> denominator;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(100000000000, '\n');
		ValidInput = false;
	}
	else if (cin.peek() != '\n')
	{
		cin.ignore(10000000, '\n');
		ValidInput = false;
	}
	else if ((barra != '/') || (denominator == 0))
		ValidInput = false;
	if (ValidInput)
	{
		return ValidInput;
	}
	numerator = 0;
	denominator = 0;
	return ValidInput;
}

void reduceFraction(int& numerator, int& denominator) //3.7 b)
{
	char barra;
	unsigned int gdc;
	bool ValidInput;
	do
	{
		ValidInput = true;
		cin >> numerator >> barra >> denominator;
		if (cin.fail())
		{
			cout << "Error. Try again. ";
			cin.clear();
			cin.ignore(100000000000, '\n');
			ValidInput = false;
		}
		else if (cin.peek() != '\n')
		{
			cout << "Error. Try again. ";
			cin.ignore(10000000, '\n');
			ValidInput = false;
		}
		else if ((barra != '/') || (denominator == 0))
		{
			cout << "Error. Try again. ";
			ValidInput = false;
		}
	} while (!ValidInput);
	gdc = GDC_R(numerator, denominator);
	numerator /= gdc;
	denominator /= gdc;
	if (denominator != 1)
		cout << '\t' << numerator << '/' << denominator << endl;
	else
		cout << '\t' << numerator << endl;

}

void FractionsOperations() //3.7 c)
{
	int n1, n2, d1, d2, r, d11;
	char b1, b2, op;
	bool ValidOperation;
	unsigned int gdc;
	cout << "what do you want do do? " << endl;
	do
	{
		cin >> n1 >> b1 >> d1; cin.ignore(1, ' '); cin >> op; cin.ignore(1, ' '); cin >> n2 >> b2 >> d2;
		ValidOperation = true;
		if (cin.fail())
		{
			cin.clear();
			cout << "Error. Try again. ";
			ValidOperation = false;
		}
		else if (b1 != '/' || b2 != '/')
		{
			cout << "Error. Try again. ";
			ValidOperation = false;
		}
		else if (cin.peek() != '\n')
		{
			cout << "Error. Try again. ";
			ValidOperation = false;
		}
		else
		{
			switch (op)
			{
			case ('+'):
				d11 = d1 * d2;
				r = (n1 * d2) + (n2 * d1);
				break;
			case ('-'):
				d11 = d1 * d2;
				r = (n1 * d2) - (n2 * d1);
				break;
			case ('*'):
				d11 = d1 * d2;
				r = n1 * n2;
				break;
			case ('/'):
				d11 = d1 * n2;
				r = n1 * d2;
				break;
			default:
				cout << "Error. Try again. ";
				ValidOperation = false;
			}
		}
		cin.ignore(10000000000000, '\n');
	} while (!ValidOperation);
	gdc = GDC_R(r, d11);
	r /= gdc;
	d11 /= gdc;
	if (d11 != 1)
		cout << "The result is: " << r << '/' << d11 << endl;
	else
		cout << "The result is: " << r << endl;
}

bool year(int x) //3.8 a)
{
	//cin >> x;
	if ((x % 4 == 0) && (x % 100 != 0))
		return true;
	else if (x % 400 == 0)
		return true;
	else
		return false;
}

int DaysOfMonth(int y, int m) //3.8 b)
{
	bool ValidOperation = true;
	/*do
	{
		cin >> y; cin.ignore(1, ' '); cin >> m;
		if (cin.fail())
		{
			cin.clear();
			ValidOperation = false;
			cin.ignore(10000000000, '\n');
		}
		else if (cin.peek() != '\n')
		{
			ValidOperation = false;
			cin.ignore(10000000000, '\n');
		}
		else if (m <= 0 || m > 12)
		{
			ValidOperation = false;
			cin.ignore(10000000000, '\n');
		}
	} while (!ValidOperation);*/
	switch (m)
	{
	case (1):
		return 31;
	case (3):
		return 31;
	case (4):
		return 30;
	case (5):
		return 31;
	case (6):
		return 30;
	case (7):
		return 31;
	case (8):
		return 31;
	case (9):
		return 30;
	case (10):
		return 31;
	case (11):
		return 30;
	case (12):
		return 31;
	}
	if (m == 2)
	{
		if (year(y))
			return 29;
		else
			return 28;
	}
}

string DayOfWeek(int y, int m, int d) //3.9 c)
{
	bool ValidOperation = true;
	int c, z = year(y);
	//do
	//{
	//	cin >> d;  cin.ignore(1, '\n'); cin >> m; cin.ignore(1, '\n'); cin >> y;
	//	if (cin.fail())
	//	{
	//		cin.clear();
	//		ValidOperation = false;
	//		cin.ignore(10000000000, '\n');
	//		cout << "Error. Try again. " << endl;

	//	}
	//	else if (m <= 0 || y < 0 || d <= 0)
	//	{
	//		ValidOperation = false;
	//		cin.ignore(10000000000, '\n');
	//		cout << "Error. Try again. " << endl;

	//	}
	//	else if (cin.peek() != '\n')
	//	{
	//		ValidOperation = false;
	//		cin.ignore(10000000000, '\n');
	//		cout << "Error. Try again. " << endl;

	//	}
	//	else if (m > 12)
	//	{
	//		ValidOperation = false;
	//		cin.ignore(10000000000, '\n');
	//		cout << "Error. Try again. " << endl;

	//	}
	//	else if (m == 2 && z && d > 29)
	//	{
	//		ValidOperation = false;
	//		cin.ignore(10000000000, '\n');
	//		cout << "Error. Try again. " << endl;

	//	}
	//	else if (m == 2 && !z && d >= 29)
	//	{
	//		ValidOperation = false;
	//		cin.ignore(10000000000, '\n');
	//		cout << "Error. Try again. " << endl;
	//	}
	//} while (!ValidOperation);
	if (z)
	{
		switch (m)
		{
		case(1):
			c = 6;
			break;
		case(2):
			c = 2;
			break;
		case(3):
			c = 3;
			break;
		case(4):
			c = 6;
			break;
		case(5):
			c = 1;
			break;
		case(6):
			c = 4;
			break;
		case(7):
			c = 6;
			break;
		case(8):
			c = 2;
			break;
		case(9):
			c = 5;
			break;
		case(10):
			c = 0;
			break;
		case(11):
			c = 3;
			break;
		case(12):
			c = 5;
			break;
		}
	}
	else
	{
		switch (m)
		{
		case(1):
			c = 0;
			break;
		case(2):
			c = 3;
			break;
		case(3):
			c = 3;
			break;
		case(4):
			c = 6;
			break;
		case(5):
			c = 1;
			break;
		case(6):
			c = 4;
			break;
		case(7):
			c = 6;
			break;
		case(8):
			c = 2;
			break;
		case(9):
			c = 5;
			break;
		case(10):
			c = 0;
			break;
		case(11):
			c = 3;
			break;
		case(12):
			c = 5;
			break;
		}
	}
	int ds = (int((5 * (y % 100)) / 4) + c + d - 2 * ((y / 100) % 4) + 7) % 7;
	switch (ds)
	{
	case(0):
		return "Saturday";
	case(1):
		return "Sunday";
	case(2):
		return "Monday";
	case(3):
		return "Tuesday";
	case(4):
		return "Wednesday";
	case(5):
		return "Thursday";
	case(6):
		return "Friday";
	default:
		cout << "nop" << endl;
	}
}

int DayOfWeekk(int y, int m, int d) //3.9 d)
{
	string dw = DayOfWeek(y, m, d);
	if (dw == "Sunday")
		return 7;
	else if (dw == "Saturday")
		return 6;
	else if (dw == "Monday")
		return 1;
	else if (dw == "Tuesday")
		return 2;
	else if (dw == "Wednesday")
		return 3;
	else if (dw == "Thursday")
		return 4;
	else if (dw == "Friday")
		return 5;
}

void calendario(int y, int m) //3.8 d)
{
	int dm, dw, k = 0;
	string mes;
	//cout << "Please give month/year. ";
	//cin >> m; cin.ignore(1, '/'); cin >> y;
	switch (m)
	{
	case(1):
		mes = "Janeiro";
		break;
	case(2):
		mes = "Fevereiro";
		break;
	case(3):
		mes = "Marco";
		break;
	case(4):
		mes = "Abril";
		break;
	case(5):
		mes = "Maio";
		break;
	case(6):
		mes = "Junho";
		break;
	case(7):
		mes = "Julho";
		break;
	case(8):
		mes = "Agosto";
		break;
	case(9):
		mes = "Stembro";
		break;
	case(10):
		mes = "Outubro";
		break;
	case(11):
		mes = "Novembro";
		break;
	case(12):
		mes = "Dezembro";
		break;
	}
	dm = DaysOfMonth(y, m);
	dw = DayOfWeekk(y, m, 1) + 1;
	cout << "===================================================" << endl;
	cout << "		   " << mes << " de " << y << "		" << endl;
	cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << endl;
	for (int i = 1; i <= dm; i++)
	{
		if (i == 1)
		{
			if (dw != 7)
			{
				while (k != (dw % 7))
				{
					if (k == 0)
						cout << "  ";
					else
						cout << " \t  ";
					k++;
				}
			}
			else
			{
				while (k != dw)
				{
					if (k == 0)
						cout << "  ";
					else
						cout << " \t  ";
					k++;
				}
			}
			cout << i;
			if ((dw % 7) == 0)
				cout << "\n  ";
			else
				cout << "\t  ";
			dw++;
		}
		else if (i < 9)
		{
			cout << i;
			if ((dw % 7) == 0)
				cout << "\n  ";
			else
				cout << "\t  ";
			dw++;
		}
		else
		{
			cout << i;
			if ((dw % 7) == 0)
				cout << "\n ";
			else
				cout << "\t ";
			dw++;
		}
	}
	cout << '\n';
}

void final_calendar() //3.9 e)
{
	int y;
	cout << "Please give a year. " << endl;
	cin >> y;
	for (int i = 1; i <= 12; i++)
	{
		calendario(y, i);
	}
}

unsigned long long factorial_ite(unsigned int n) //3.10 a)
{
	unsigned long long result = 1, r = 0, r_limit = ULLONG_MAX;
	unsigned int n_limit = UINT_MAX, i, k, z, a= 1;
	for (k = 1; k <= n_limit; k++)
	{
		result = 1;
		for (z = 1; z <= k; z++)
		{
			result *= z;
		}
		if (result < r)
		{
			a = 0;
			k--;
		}
		if (a == 0)
			break;
		r = result;
	}
	result = 1;	
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
		for (i = 1; i <= n; i++)
		{
			result *= i;
		}
	cout << "The limit is: " << k << endl;
	return result;
}

unsigned long long factorial_rec(unsigned int n) //3.10 b)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return n * factorial_rec(n - 1);
}

unsigned int GCD_rec(unsigned int m, unsigned int n)
{
	unsigned int max = n, min = m;
	if (m > n)
	{
		max = m;
		min = n;
	}
	if ((m % n) == 0)
		return n;
	else
		return GCD_rec(n, m % n);
}

double area_(double r) //3.12
{
	return 2 * M_PI * r;
}

double area_(double x1, double y1, double x2, double y2) //3.12
{
	return (abs(x2 - x1) * abs(y1 - y2));
}

double area_(double x1, double y1, double x2, double y2, double x3, double y3) //3.12
{
	double s, d1, d2, d3;
	d1 = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
	d2 = pow(pow(x3 - x2, 2) + pow(y3 - y2, 2), 0.5);
	d3 = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);
	s = d1 + d2 + d3;
	return pow(s * (s - d1) * (s - d2) * (s - d3), 0.5);
}

void tres_treze() //3.13
{
	cout << "3.13" << endl;
	cout << "a) A função verifica se o valor da variável high é maior ou igual ao valor da variável low. Se não for, o programa termina e é dado como output uma mensagem de erro. Caso contrário o programa retorna um valor entre o valor de low e o valor de high." << endl;
	cout << "b) A função tem 3 signatures, pois é possível chamar a função com 0 parametros, com 1 e com 2 pois já foram definidos quando foi definida a função." << endl;
	cout << "c) Não pois a função está definida para ser utilizada mesmo que não tenha parametros quando se dá a call da mesma visto que na definição dos mesmos, estabelizou-se valores para o caso disso acontecer." << endl;
}

double integrateTR(double f(double), double a, double b, int n) //3.14 a)
{
	double h, area = 0;
	h = (b - a) / n;
	for (int i = 1; i <= n; i++)
	{
		area += (h / 2) * (f(a + (i - 1) * h) + f(a + i * h));
	}
	return area;
}

double g(double x)
{
	return pow(x, 2);
}

double h(double x)
{
	return pow(4 - pow(x, 2), 0.5);
}

int main()
{
	cout << integrateTR(g, 0, 10, 3) << endl;
	cout << integrateTR(h, -2, 2, 100000) << endl;
	return 0;
}