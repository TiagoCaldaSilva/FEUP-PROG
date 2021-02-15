#define _USE_MATH_DEFINES
#include <iostream> //para cout, cin...
#include <math.h>	//para ~expressões matemáticas como M_PI
#include <iomanip>	//para setprecision()
#include <time.h>	//para funções do tempo
#include <typeinfo>	//para ver o type
#include <stdlib.h>	//para limppar ecrã

using namespace std;

void system() // 2.1
{
	double a, b, c, d, e, f, x, y, q;
	cout << "Please enter the 'a' value. "; cin >> a;
	cout << "b? "; cin >> b;
	cout << "c? "; cin >> c;
	cout << "d? "; cin >> d;
	cout << "e? "; cin >> e;
	cout << "f? "; cin >> f;
	q = d / a;
	if (b * q == e)
	{
		cout << "inconsistent system";
	}
	else if (a * e == b * d)
	{
		cout << "impossible system";
	}
	else
	{
		x = (c * e - b * f) / (a * e - b * d);
		y = (a * f - c * d) / (a * e - b * d);
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
	// quando é que o sistema tem infinitas soluções??
}

void largest_smallest() // 2.2 a)
{
	int x1, x2, x3;
	cout << "Give 3 numbers. "; cin >> x1 >> x2 >> x3;
	if (x1 >= x2 & x1 >= x3)
	{
		if (x2 >= x3)
			cout << "The largest number is " << x1 << " and the smallest one is " << x3 << ".";
		else
			cout << "The largest number is " << x1 << " and the smallest one is " << x2 << ".";
	}
	else if (x2 >= x1 & x2 >= x3)
	{
		if (x1 >= x3)
			cout << "The largest number is " << x2 << " and the smallest one is " << x3 << ".";
		else
			cout << "The largest number is " << x2 << " and the smallest one is " << x1 << ".";
	}
	else
	{
		if (x2 >= x1)
			cout << "The largest number is " << x3 << " and the smallest one is " << x1 << ".";
		else
			cout << "The largest number is " << x3 << " and the smallest one is " << x2 << ".";
	}
}

void descending_order() //2.2 b)
{
	int x1, x2, x3, r1, r2, r3;
	cout << "Give 3 numbers."; cin >> x1 >> x2 >> x3;
	if (x1 >= x2 & x1 >= x3)
	{
		if (x2 >= x3)
			cout << x1 << "-" << x2 << "-" << x3;
		else
			cout << x1 << "-" << x3 << "-" << x2;
	}
	else if (x2 >= x1 & x2 >= x3)
	{
		if (x1 >= x3)
			cout << x2 << "-" << x1 << "-" << x3;
		else
			cout << x2 << "-" << x3 << "-" << x1;
	}
	else
	{
		if (x1 >= x3)
			cout << x3 << "-" << x1 << "-" << x2;
		else
			cout << x3 << "-" << x2 << "-" << x1;
	}
}

void triangle() // 2.2 c)
{
	double x1, x2, x3;
	cout << "Give 3 positive numbers. " << endl; cin >> x1 >> x2 >> x3;
	if (x1 < 0 | x2 < 0 | x3 < 0)
		cout << "you must give 3 positive numbers.";
	else
	{
		if (x1 >= x2 & x1 >= x3)
		{
			if (x1 > x2 + x3)
				cout << "It isn't possible to create a triangle with that 3 numbers.";
			else
				cout << "It is possivle to create a triangle with that 3 numbers.";
		}
		else if (x2 >= x1 & x2 >= x3)
		{
			if (x2 > x1 + x3)
				cout << "It isn't possible to create a triangle with that 3 numbers.";
			else
				cout << "It is possivle to create a triangle with that 3 numbers.";
		}
		else
		{
			if (x3 > x2 + x1)
				cout << "It isn't possible to create a triangle with that 3 numbers.";
			else
				cout << "It is possivle to create a triangle with that 3 numbers.";
		}
	}
}

void over_or_underflow() // 2.3
{
	int x1, x2, sum;
	cout << "Please, give 2 integers. " << endl; cin >> x1 >> x2;
	sum = x1 + x2;
	if (sum > INT_MAX)
		cout << "sum overflow";
	else if (sum < INT_MIN)
		cout << "sum underflow";
	else
		cout << sum;
}

void weight() // 2.4
{
	double w, extra = 0;
	cout << "What is the weight of the merchandise? " << endl; cin >> w;
	if (w <= 500)
		cout << "The transportation will cost 5 euros.";
	else if ((w >= 501) & (w <= 1000))
	{
		w -= 500;
		if (w > 0 && w < 100)
			extra += 1.5;
		while (w > 100)
		{
			w -= 100;
			extra += 1.5;
		}
		cout << "The transportation will cost " << 5 + extra << " euros.";
	}
	else
	{
		w -= 1000;
		if ((w > 0) && (w < 250))
			extra += 5;
		while (w > 0)
		{
			w -= 250;
			extra += 5;
		}
		cout << "The transportation will cost " << 12.5 + extra << " euros.";
	}
}

void roots() //2.5
{
	double a, b, c, r1, r2, cmplx;
	cout << "Solution of Ax^2 + Bx + C = 0" << endl;
	cout << "Insert the cooefficients (A B C) : "; cin >> a >> b >> c;
	if (pow(b, 2) < 4 * a * c)
	{
		cmplx = pow(pow(b, 2) - 4 * a * c, (1 / 2)) / (2 * a);
		cout << "The equation has 2 complex roots: " << (-b / (2 * a)) << "+" << cmplx << "i  and  " << (-b / (2 * a)) << "-" << cmplx << "i";
	}
	else
	{
		r1 = (-b + pow((pow(b, 2) - 4 * a * c), (1 / 2))) / (2 * a);
		r2 = (-b - pow((pow(b, 2) - 4 * a * c), (1 / 2))) / (2 * a);
		if (r1 == r2)
			cout << " The equation has 2 equal real roots: " << r1 << "  and  " << r1;
	}
}

void bank() // 2.6
{
	double j, co, c, n;
	cout << "Please give the amount deposited. "; cin >> co;
	cout << "Please give the number of years that the amount is in the bank. "; cin >> n;
	cout << "Please give the anual interest rate. "; cin >> j;
	c = co + pow(1 + j / 100, n);
	cout << "After " << n << " years, the depositor can withdraw " << c << " euros.";
}

void prime_or_not() // 2.7 a)
{
	int n, i = 2;
	double s;
	bool t = true;
	cout << "What is the number that you wuant to verify that is prime? "; cin >> n;
	s = pow(n, 0.5);
	for (i; i <= s; i++)
	{
		if (n % i == 0)
		{
			t = false;
			break;
		}
	}
	if (t)
	{
		cout << "The number " << n << " is prime." << endl;
	}
	else
	{
		cout << "The number " << n << " is not prime." << endl;
	}
}

void primes_to_k() //2.7 b)
{
	int i = 1, k;
	double s;
	bool t, r;
	for (i; i < 1000; i++)
	{
		t = true;
		s = pow(i, 0.5);
		for (k = 2; k <= s; k++)
			if (i % k == 0)
			{
				t = false;
				break;
			}
		if (t)
		{
			cout << i << endl;
		}
	}
}

void first_hundred_primes() // 2.7 c)
{
	int i, k, c = 0;
	double s;
	bool t, r;
	for (i = 1; c <= 100; i++)
	{
		t = true;
		s = pow(i, 0.5);
		for (k = 2; k <= s; k++)
		{
			if (i % k == 0)
			{
				t = false;
				break;
			}
		}
		if (t)
		{
			cout << i << endl;
			c++;
		}
	}
}

void largest_prime()//2.7 c)
{
	unsigned long i = (pow(2, 32) - 1), k;
	bool var = true;

	while (var)
	{
		for (i; i >= 1; i -= 1)
		{
			for (k = 2; k <= pow(i, (1 / 2)); k++)
			{
				if ((i % k) == 0)
				{
					var = false;
					break;
				}
			}
			if (var)
			{
				cout << i << endl;
				var = false;
				break;
			}
			else
				var = true;
		}
	}
}

void angle() //2.8 a)
{
	int a;
	cout << "ang \t\t sin \t\t cos \t\t tan " << endl;
	for (a = 0; a <= 90; a += 15)
	{
		cout << fixed << setprecision(6) << a << "\t" << sin((a * M_PI) / 180) << "\t" << cos((a * M_PI) / 180) << "\t";
		if (a == 90)
			cout << "infinite";
		else
			cout << tan((a * M_PI) / 180) << endl;
	}
}

void angle_() //2.8 b)
{
	double m, M, a, d;
	cout << "What is the range that you desire? ([minimum,Maximum]) "; cin.ignore(1, ' '); cin >> m; cin.ignore(1000, ','); cin >> M; cin.ignore(10000, '\n');
	cout << "And what is the interval of the value of the angles in the table? "; cin >> d;
	cout << "ang \t\t sin \t\t cos \t\t tan " << endl;
	for (a = m; a <= M; a += d)
	{
		cout << fixed << setprecision(6) << a << "\t" << sin((a * M_PI) / 180) << '\t' << cos((a * M_PI) / 180) << "\t";
		if (a == 90)
			cout << "infinite";
		else
			cout << tan((a * M_PI) / 180) << endl;
	}
}

void palindrome_1() //2.9 a)
{
	int i;
	cout << "Please give a 3-digit integer. "; cin >> i;
	if ((i % 10) == (i / 100))
		cout << "The number is a palindrome.";
	else
		cout << "The number isn't a palindrome. ";
}

void palindrome_2() //2.9 b)
{
	unsigned long i, k;
	int a = 0;
	bool var = true;
	cout << "Please give a number. "; cin >> i;
	k = int(i);
	while (k >= 1)
	{
		k /= 10;
		a++;
	}
	while (a > 1 && var)
	{
		if ((i % 10) != int(i / pow(10, (a - 1))))
		{
			var = false;
			break;
		}
		i = (i - int((i / pow(10, (a - 1)))) * pow(10, (a - 1))) / 10;
		a -= 2;
	}
	if (var)
		cout << "The number is a palindrome.";
	else
		cout << "The number isn't a palindrome.";
}

void factors() //2.10
{
	int n, i, a[200], k, d = 0, e = 0, t = 0;
	bool var;
	cout << "Please give a number. "; cin >> n;
	cout << n << "=";
	for (i = 2; i < n; i++)
	{
		var = true;
		for (k = 2; k <= pow(i, 0.5); k++)
		{
			if ((i % k) == 0)
			{
				var = false;
				break;
			}
		}
		if (var)
		{
			a[d] = i;
			d++;
		}
	}
	while ((n != 1) || (t == d))
	{
		while ((n % (a[t])) == 0)
		{
			if (e == 0)
			{
				n /= a[t];
				cout << a[t];
				e++;
			}
			else
			{
				n /= a[t];
				cout << "x" << a[t];
			}
		}
		t++;
	}
}

void series_a() //2.11 a)
{
	int n, i;
	double sum = 0;
	cout << "Please give a number. "; cin >> n;
	for (i = 1; i <= n; i++)
	{
		sum += pow((-1), i + 1) * 4 / ((i * 2) - 1);
	}
	cout << "The final value is: " << sum;
}

int factorial(int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
	{
		return n * factorial(n - 1);
	}
}

void series_b() //2.11 b)
{
	int n, i;
	double sum = 0, fact;
	cout << "Please give a number. "; cin >> n;
	for (i = 0; i <= n; i++)
	{
		fact = factorial(i);
		sum += (1 / fact);
	}
	cout << "The result is: " << sum;
}

void series_c() //2.11 c)
{
	int n, i;
	double x, sum = 0, fact;
	cout << "Please give a number. "; cin >> n;
	cout << "Please give a number for the x. "; cin >> x;
	for (i = 0; i <= n; i++)
	{
		fact = factorial(n);
		sum += pow(x, i) / fact;
	}
	cout << "The result is: " << sum;
}

void series_aa() //2.12 a)
{
	float prec;
	double sum = 0, v, i;
	cout << "Set the precision. "; cin >> prec;
	for (i = 1; i <= 1000000000000; i++)
	{
		v = pow((-1), i + 1) * 4 / ((i * 2) - 1);
		if (abs(v) < prec)
			break;
		else
			sum += v;
	}
	cout << "The final value is: " << sum;
}

void intg_a() //2.13 a)
{
	int len, min = 0, max = 0, i, v;
	double sum = 0, mean, sd, sdsum = 0;
	cout << "What is the length of the sequence? "; cin >> len;
	for (i = 0; i < len; i++)
	{
		cout << "Please give a number. "; cin >> v;
		if (i == 0)
		{
			min = v;
			max = min;
		}
		else
			if (v < min)
				min = v;
			else if (v > max)
				max = v;
		sum += v;
		sdsum += pow(v, 2);
	}
	mean = sum / len;
	sd = pow((sdsum / len) - pow((sum / len), 2), 0.5);
	cout << "Sum: " << sum << endl << "Mean: " << mean << endl << "Standard deviation: " << sd << endl << "Smallest number: " << min << endl << "Largest number: " << max << endl;
}

void intg_b() //2.13 b)
{
	int len = 0, v, min, max, counter = 0;
	double sd, sum = 0, mean, sdsum = 0;
	cout << "Please give a sequence of integer numbers. When you want to end, enter a 0." << endl;
	while (true)
	{
		cout << "Give a number. "; cin >> v;
		if (v == 0)
			break;
		if (counter == 0)
		{
			min = v;
			max = v;
			counter++;
		}
		else
		{
			if (v < min)
				min = v;
			else if (max < v)
				max = v;
		}
		sum += v;
		sdsum += pow(v, 2);
		len++;
	}
	sd = pow((sdsum / len) - pow(sum / len, 2), 0.5);
	mean = sum / len;
	cout << "Sum: " << sum << endl << "Mean: " << mean << endl << "Standard deviation: " << sd << endl << "Smallest number: " << min << endl << "Largest number: " << max << endl;
}

void intg_c() //2.13 c)
{
	int len = 0, v, min, max, counter = 0;
	double sd, mean, sum = 0, sdsum = 0;
	bool continuar = true;
	cout << "When you desire to end the sequence, please enter CTRL-Z." << endl;
	while (true)
	{
		cout << "Give a number. "; cin >> v;
		if (cin.fail())
			if (cin.eof())
				break;
			else
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
		else
		{
			if (counter == 0)
			{
				min = v;
				max = v;
				counter++;
			}
			else
			{
				if (v < min)
					min = v;
				else if (v > max)
					max = v;
			}
			sum += v;
			sdsum += pow(v, 2);
			len++;
		}
	}
	mean = sum / len;
	sd = pow((sdsum / len) - pow(sum / len, 2), 0.5);
	cout << "Sum: " << sum << endl << "Mean: " << mean << endl << "Standard deviation: " << sd << endl << "Smallest number: " << min << endl << "Largest number: " << max << endl;
}

void sqrt_a() //2.14 a)
{
	int nMaxIter, i;
	double rq = 1, rqn = 1, dif = 1000000, delta, n;
	cout << "Please, enter the maxium number of iterations. "; cin >> nMaxIter;
	cout << "Please, enter the delta tthat yo desire. "; cin >> delta;
	cout << "Now, enter the number that you desire to calculate the square root. "; cin >> n;
	for (i = 0; i <= nMaxIter; i++)
	{
		if (abs(dif) < delta)
			break;
		else
		{
			rqn = (rq + n / rq) / 2.0;
			dif = n - pow(rqn, 2);
			rq = rqn;
		}
	}
	cout << rqn;
}

void sqrt_b() //2.14 b)
{
	int nMaxIter, i;
	double rq = 1, rqn = 1, dif = 1000000, delta, n, zp, z;
	cout << "Please, enter the maxium number of iterations. "; cin >> nMaxIter;
	cout << "Please, enter the delta tthat yo desire. "; cin >> delta;
	cout << "Now, enter the number that you desire to calculate the square root. "; cin >> n;
	zp = delta;
	for (z = 0; zp < 1; z++)
	{
		zp *= 10;
	}
	for (i = 0; i <= nMaxIter; i++)
	{
		if (abs(dif) < delta)
			break;
		else
		{
			rqn = (rq + n / rq) / 2.0;
			dif = n - pow(rqn, 2);
			rq = rqn;
		}
	}
	cout << "The result of the Heron's algorithm is: " << fixed << setprecision(z) << rqn << endl;
	cout << "The value of the sqrt() is: " << sqrt(n);
}

void tabuada() //2.15
{
	int r, a, b;
	cout << "Hello, do you wanna play a game? " << endl;
	cout << "--------------------------------------------------------------" << endl;
	srand(time(NULL));
	a = 2 + (rand() % 8);
	b = 2 + (rand() % 8);
	cout << "(" << a << " * " << b << ")^2" << " = ";
	time_t start = time(NULL);
	cin >> r;
	cout << "--------------------------------------------------------------" << endl;
	time_t diff = time(NULL) - start;
	if (r != pow((a * b), 2))
		cout << "Very bad bro. Keep trying... :(" << endl;
	else
		if (diff < 5)
			cout << "Good!!! :D" << endl;
		else if (diff >= 5 && diff <= 10)
			cout << "Satisfactory! :)" << endl;
		else
			cout << "Insufficient... :( " << endl;
}

void calculator() //2.16
{
	double mem = 0, op1, op2, r=0;
	char op, x;
	bool ValidOperation = true;
	cout << "Welcome to my calculator. What do you desire to calculate?" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "|                          RULES                          |" << endl;
	cout << "|  Use CTRL-Z if you want to leave.                       |" << endl;
	cout << "|  Use M to save the result in the memory.                |" << endl;
	cout << "|  Use M+ to sum the result to the memory value.          |" << endl;
	cout << "|  Use M- to subtract the result to the memory value.     |" << endl;
	cout << "|  Use MR to see the value in th memory.                  |" << endl;
	cout << "|  Use MC to clear the memory value.                      |" << endl;
	cout << "|  Use C to clear the display.                            |" << endl;
	cout << "-----------------------------------------------------------" << endl;
	do
	{
		x = cin.peek();
		cin >> op1 >> op >> op2;
		if (cin.fail())
		{
			if (cin.eof())
			{
				ValidOperation = false;
			}
			else
			{
				if (char(x) == 'M')
				{
					cin.clear();
					cin.ignore(1, '\n'); x = cin.peek();
					switch (char(x))
					{
					case '+':
						cin.ignore(1, '\n');
						x = cin.peek();
						if (char(x) != '\n')
						{
							cin.ignore(1000000, '\n');
							cout << "OOoopss. Ivalid operation. Please try again. " << endl;
						}
						else
						{
							mem += r;
							cout << mem << endl;
						}
						break;
					case '-':
						cin.ignore(1, '\n');
						x = cin.peek();
						if (char(x) != '\n')
						{
							cin.ignore(1000000, '\n');
							cout << "OOoopss. Ivalid operation. Please try again. " << endl;
						}
						else
						{
							mem -= r;
							cout << mem << endl;
						}
						break;
					case '\n':
						mem = r;
						cout << "Result saved." << endl;
						break;
					case 'R':
						cin.ignore(1, '\n');
						x = cin.peek();
						if (char(x) != '\n')
						{
							cin.ignore(1000000, '\n');
							cout << "OOoopss. Ivalid operation. Please try again. " << endl;
						}
						else
							cout << mem << endl;
						break;
					case 'C':
						cin.ignore(1, '\n');
						x = cin.peek();
						if (char(x) != '\n')
						{
							cin.ignore(1000000, '\n');
							cout << "OOoopss. Ivalid operation. Please try again. " << endl;
						}
						else
						{
							mem = 0;
							cout << "Memory value = 0" << endl;
						}
						break;
					default:
						cin.ignore(1000000, '\n');
						cout << "OOoopss. Ivalid operation. Please try again. " << endl;
					}
					cin.ignore(1, ' ');
				}
				else if (char(x) == 'C')
				{
					cin.clear();
					system("cls");
					cin.ignore(1, ' ');
				}
				else
				{
					cin.clear();
					cin.ignore(1000000, '\n');
					cout << "OOoopss. Ivalid operation. Please try again. " << endl;
				}
			}
		}
		else
		{
			if (cin.peek() != '\n')
			{
				cout << "OOoopss. Ivalid operation. Please try again. " << endl;
				cin.ignore(10000000, '\n');
			}
			else
			{
				cin.ignore(1, ' ');
				switch (op)
				{
				case '+':
					r = op1 + op2;
					break;
				case '-':
					r = op1 - op2;
					break;
				case '*':
					r = op1 * op2;
					break;
				case '/':
					r = op1 / op2;
					break;
				}
				cout << "Result = " << r << endl << "Please give another operation." << endl;
			}
		}
	} while (ValidOperation);
}

int main()
{

	return 0;
}