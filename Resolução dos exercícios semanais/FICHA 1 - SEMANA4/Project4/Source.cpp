#include <iostream>
#include <vector>
#include <time.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

void readArray(int a[], size_t nElem) //4.1
{
	int k;
	//cout << "How many integer you desire to save in the array? "; cin >> nElem;
	for (int i = 0; i < nElem; i++)
	{
		cout << "Give a number. "; cin >> k;
		a[i] = k;
		cout << "The number " << k << " was saved in the position " << i << "." << endl;
		cout << "=================================================" << endl;
	}
}

int findValueInArray(const int a[], size_t nElem, int value, size_t pos1 = 0, size_t pos2 = -1)	//4.1 b) d)
{
	if (pos1 < pos2)
	{
		if (pos2 == -1)
			pos2 = nElem;
		for (int i = pos1; i <= pos2; i++)
		{
			if (i - pos1 >= nElem)
				break;
			cout << i << "-" << a[i] << endl;
			if (a[i] == value)
				return i - pos1;
		}
	}
	return -1;
}

int Program_4_1_c() //4.1 c)
{
	int a[1000], nElem, n, pos1, pos2, value;
	cout << "How many integer you desire to save in the array? "; cin >> nElem;
	readArray(a, nElem);
	cout << "How many numbers do you wanna to search?. "; cin >> n;
	cout << "Please give a number to pos2. "; cin >> pos2;
	cout << "Please give a number to pos1. "; cin >> pos1;
	cout << "Now, give a value. "; cin >> value;
	cout << "=========================================" << endl;
	cout << findValueInArray(a, n, value, pos1, pos2);
	return 0;
}

size_t findMultValuesInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2, size_t index[]) //4.1 e) f)
{
	int k = 0;
	for (int i = pos1; i <= pos2; i++)
	{
		if (i - pos1 == nElem)
			break;
		else if (a[i] == value)
		{
			index[k] == i;
			k++;
		}
	}
	return sizeof(index) / sizeof(int);
	/*	int a[1000], nElem, n, pos1, pos2, value;
	size_t ind[1000];
	cout << "How many integer you desire to save in the array? "; cin >> nElem;
	readArray(a, nElem);
	cout << "How many numbers do you wanna to search?. "; cin >> n;
	cout << "Please give a number to pos2. "; cin >> pos2;
	cout << "Please give a number to pos1. "; cin >> pos1;
	cout << "Now, give a value. "; cin >> value;
	cout << "=========================================" << endl;
	cout << findMultValuesInArray(a, n, value, pos1, pos2, ind);
	return 0;*/
}

void read_Vector(vector<int>& v, size_t nElem) //4.2 a)
{
	int k;
	for (size_t i = 0; i < nElem; i++)
	{
		cout << "Please give a number to save. "; cin >> k;
		v.push_back(k);
		cout << "The value " << k << " in in the position " << i << endl;
	}
	/*	vector<int> v;
	size_t nElem;
	cout << "Please give a number. "; cin >> nElem;
	read_Vector(v, nElem);
	return 0;*/
}

size_t findValueInVector(const vector<int>& v, int value, size_t pos1, size_t pos2) //4.2 a)
{
	for (int i = pos1; i <= pos2; i++)
	{
		if (v.at(i) == value)
			return i;
	}
	return -1;
}

void findMultValuesInVector(const vector<int>& v, int value, size_t pos1, size_t pos2, vector<size_t>& index) //4.2 a)
{
	for (int i = pos1; i <= pos2; i++)
	{
		if (v.at(i) == value)
			index.push_back(i);
	}
	cout << index.size();
}

void readd_Vector(vector<int> v) //4.2 b)
{
	int k;
	int i = 0;
	do
	{
		cout << "Please give a number. If you desire to stop please enter CTRL-Z. " << endl;
		cin >> k;
		if (cin.fail())
		{
			if (cin.eof())
				break;
			else
			{
				cout << "Please try again. " << endl;
			}
			cin.clear();
			cin.ignore(100000, '\n');
		}
		else
		{
			if (v.size() != 0)
				i++;
			v.push_back(k);
			cout << "The number was saved in the position " << i << endl;
		}
	} while (1);
}

void quatro_dois_3() //4.c)
{
	cout << "Não iria ser possivel fazer isso com arrays pois não é possivel retornar arrays, enquanto é possivel retornar vectores. ";
}

void bubbleSort(vector<int>& v) //4.3 a)
{
	int k;
	for (int x = 0; x < v.size(); x++)
	{
		for (int z = 0; z < (v.size() - 1); z++)
		{
			if (v.at(z) > v.at(z + 1))
			{
				k = v.at(z);
				v.at(z) = v.at(z + 1);
				v.at(z + 1) = k;
			}
		}
	}
}

void bubbleSort_c(vector<int>& v) //4.3 c)b)
{
	bool x;
	int k;
	do
	{
		x = true;
		for (int i = 0; i < (v.size() - 1); i++)
		{
			if (v.at(i) > v.at(i + 1))
			{
				x = false;
				k = v.at(i);
				v.at(i) = v.at(i + 1);
				v.at(i + 1) = k;
			}
		}
	} while (!x);
	/*
	vector<int> v = { 1,4,6,2,0 };
	bubbleSort(v);
	------
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << endl;
	}
	*/
}

void bubbleSort_d(vector<int>& v, char x) //4.3 d)
{
	if (x == 'a')
	{
		bool x;
		int k;
		do
		{
			x = true;
			for (int i = 0; i < (v.size() - 1); i++)
			{
				if (v.at(i) > v.at(i + 1))
				{
					x = false;
					k = v.at(i);
					v.at(i) = v.at(i + 1);
					v.at(i + 1) = k;
				}
			}
		} while (!x);
	}
	else
	{
		bool x;
		int k;
		do
		{
			x = true;
			for (int i = 0; i < (v.size() - 1); i++)
			{
				if (v.at(i) < v.at(i + 1))
				{
					x = false;
					k = v.at(i);
					v.at(i) = v.at(i + 1);
					v.at(i + 1) = k;
				}
			}
		} while (!x);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << endl;
	}
}

void bubbleSort(vector<int>& v, bool f(int x, int y)) //4.3 e)
{

}

int binarySearch(const vector<int>& v, int value) //4.4
{
	int first = 0, last = v.size(), middle = 0;
	bool find = false;
	do
	{
		cout << first << ", " << middle << "," << last << endl;
		middle = (first + last) / 2;
		if (first == last)
			find = true;
		else if (v.at(middle) == value)
			return middle;
		else if (v.at(middle) > value)
			last = middle - 1;
		else
			first = middle + 1;
	} while (!find);
	return -1;
}

void removeDuplicates(vector<int>& v) //4.5
{
	int k = v.size(), c, counter, i = 0, ind;
	while (i != (k - 1)) //enquanto que 
	{
		counter = 0;
		ind = i + 1;
		while (ind != (v.size() - 1 - counter)) // -counter porque os elementos iguais vão estar todos no final do vetor
		{
			if (v.at(i) == v.at(ind)) //se tiver o mesmo valor que o inicial
			{
				c = ind; //para não mudificar o valor do ind
				while (c != (v.size() - 1 - counter))
				{
					v.at(c) = v.at(c + 1);
					v.at(c + 1) = v.at(i); // fazer a troca
					c++; //incrementar o c, pois não é ciclo for
				}
				counter++; //incrementar o counter pela quantidade de vezes que se encontrou um n igual (pelo que entrou no if)
			}
			else
				ind++; //como não entrou no if, pode passar ao próximo elemento
		}
		v.resize(v.size() - counter); //eliminar os valores repetido que se encontram n vezes ( valor do counter) no final do vetor
		k = v.size();
		i++;
	}
	//for (int inde = 0; inde < v.size(); inde++)
	//{
	//	cout << v.at(inde) << endl;
	//}
}

void vectorUnion(const vector<int>& v1, const vector<int>& v2, vector<int>& v3) //4.6
{
	for (int i = 0; i < v1.size(); i++)
	{
		v3.push_back(v1.at(i));
	}
	for (int i = 0; i < v2.size(); i++)
	{
		v3.push_back(v2.at(i));
	}
	removeDuplicates(v3);
	bubbleSort(v3);
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3.at(i) << endl;
	}
	//vector<int> v1 = { 1,2,3,4,5 }, v2 = { 2,3,4,5,6,7 }, v3;
	//vectorUnion(v1, v2, v3);
}

void vectorIntersection(const vector<int>& v1, const vector<int>& v2, vector<int>& v3) //4.6
{
	for (int i = 0; i < v1.size(); i++)
	{
		for (int z = 0; z < v2.size(); z++)
		{
			if (v1.at(i) == v2.at(z))
			{
				v3.push_back(v1.at(i));
				break;
			}
		}
	}
	bubbleSort(v3);
	removeDuplicates(v3);
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3.at(i) << endl;
	}
	/*
	vector<int> v1 = { 1,2,3,4,5 }, v2 = { 3,4,5,6,7,8 }, v3;
	vectorIntersection(v1, v2, v3);
	*/
}

const int NE = 5; // para definir a variável global do localMax

void localMax(const int a[NE][NE])//4.7 a)
{
	int min;
	bool x;
	for (int i = 0; i < NE; i++)
	{
		if (i == 0) //pertence à primeira linha
			for (int z = 0; z < NE; z++)
			{
				x = true;
				min = a[i][z];
				if (z == 0) //primeiro elemento da linha
				{
					if (a[i][z + 1] > min)
						x = false;
					else if (a[i + 1][z] > min)
						x = false;
					else if (a[i + 1][z + 1] > min)
						x = false;
					if (x)
						cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
				}
				else if (z == (NE - 1))//ultimo elemento da linha
				{
					if (a[i][z - 1] > min)
						x = false;
					else if (a[i + 1][z] > min)
						x = false;
					else if (a[i + 1][z - 1] > min)
						x = false;
					if (x)
						cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
				}
				else
				{
					if (a[i][z + 1] > min)
						x = false;
					else if (a[i][z - 1] > min)
						x = false;
					else if (a[i + 1][z] > min)
						x = false;
					else if (a[i + 1][z - 1] > min)
						x = false;
					else if (a[i + 1][z - 1] > min)
						x = false;
					if (x)
						cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
				}
			}
		else if (i == (NE - 1)) // pertence à última linha
		{
			for (int z = 0; z < NE; z++)
			{
				x = true;
				min = a[i][z];
				if (z == 0)
				{
					if (a[i][z + 1] > min)
						x = false;
					else if (a[i - 1][z] > min)
						x = false;
					else if (a[i - 1][z + 1] > min)
						x = false;
					if (x)
						cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
				}
				else if (z == (NE - 1))
				{
					if (a[i][z - 1] > min)
						x = false;
					else if (a[i - 1][z] > min)
						x = false;
					else if (a[i - 1][z - 1] > min)
						x = false;
					if (x)
						cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
				}
				else
				{
					if (a[i][z + 1] > min)
						x = false;
					else if (a[i][z - 1] > min)
						x = false;
					else if (a[i - 1][z] > min)
						x = false;
					else if (a[i - 1][z - 1] > min)
						x = false;
					else if (a[i - 1][z + 1] > min)
						x = false;
					if (x)
						cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
				}
			}
		}
		else //está nos valores do meio
		{
			for (int z = 0; z < NE; z++)
			{
				x = true;
				min = a[i][z];
				if (z == 0)
				{
					if (a[i - 1][z] > min)
						x = false;
					else if (a[i + 1][z] > min)
						x = false;
					else if (a[i - 1][z + 1] > min)
						x = false;
					else if (a[i][z + 1] > min)
						x = false;
					else if (a[i + 1][z + 1] > min)
						x = false;
					if (x)
						cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
				}
				else if (z == (NE - 1))
				{
					if (a[i - 1][z] > min)
						x = false;
					else if (a[i + 1][z] > min)
						x = false;
					else if (a[i][z - 1] > min)
						x = false;
					else if (a[i - 1][z - 1] > min)
						x = false;
					else if (a[i + 1][z - 1] > min)
						x = false;
					if (x)
						cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
				}
				else
				{
					if (a[i][z + 1] > min)
						x = false;
					else if (a[i][z - 1] > min)
						x = false;
					else if (a[i - 1][z] > min)
						x = false;
					else if (a[i - 1][z + 1] > min)
						x = false;
					else if (a[i - 1][z - 1] > min)
						x = false;
					else if (a[i + 1][z] > min)
						x = false;
					else if (a[i + 1][z + 1] > min)
						x = false;
					else if (a[i + 1][z - 1] > min)
						x = false;
					if (x)
						cout << "The number " << min << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
				}
			}
		}
	}
	//	int a[5][5] = {{1,2,7,6,8}, {5,4,3,5,4},{6,3,2,1,3},{9,2,1,8,7},{4,3,5,3,4}};
	//	int a[5][5] = {{7,3,4,1,3}, {2,9,6,2,1}, {1,3,5,1,4 }, { 6,5,2,7,5 }, { 4,2,1,3,6 } };
}

void localMavV(vector<vector<int>> a, bool y) //4.7 c)
{
	int min;
	bool x;
	for (int i = 0; i < NE; i++)
	{
		if (i == 0) //pertence à primeira linha
		{
			if (y == 1)
			{
				for (int z = 0; z < NE; z++)
				{
					x = true;
					min = a.at(i).at(z);
					if (z == 0) //primeiro elemento da linha
					{
						if (a[i][z + 1] > min)
							x = false;
						else if (a[i + 1][z] > min)
							x = false;
						else if (a[i + 1][z + 1] > min)
							x = false;
						if (x)
							cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
					}
					else if (z == (NE - 1))//ultimo elemento da linha
					{
						if (a[i][z - 1] > min)
							x = false;
						else if (a[i + 1][z] > min)
							x = false;
						else if (a[i + 1][z - 1] > min)
							x = false;
						if (x)
							cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
					}
					else
					{
						if (a[i][z + 1] > min)
							x = false;
						else if (a[i][z - 1] > min)
							x = false;
						else if (a[i + 1][z] > min)
							x = false;
						else if (a[i + 1][z - 1] > min)
							x = false;
						else if (a[i + 1][z - 1] > min)
							x = false;
						if (x)
							cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
					}
				}
			}
		}
		else if (i == (NE - 1)) // pertence à última linha
		{
			if (y == 1)
			{
				for (int z = 0; z < NE; z++)
				{
					x = true;
					min = a[i][z];
					if (z == 0)
					{
						if (a[i][z + 1] > min)
							x = false;
						else if (a[i - 1][z] > min)
							x = false;
						else if (a[i - 1][z + 1] > min)
							x = false;
						if (x)
							cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
					}
					else if (z == (NE - 1))
					{
						if (a[i][z - 1] > min)
							x = false;
						else if (a[i - 1][z] > min)
							x = false;
						else if (a[i - 1][z - 1] > min)
							x = false;
						if (x)
							cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
					}
					else
					{
						if (a[i][z + 1] > min)
							x = false;
						else if (a[i][z - 1] > min)
							x = false;
						else if (a[i - 1][z] > min)
							x = false;
						else if (a[i - 1][z - 1] > min)
							x = false;
						else if (a[i - 1][z + 1] > min)
							x = false;
						if (x)
							cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
					}
				}
			}
		}
		else //está nos valores do meio
		{
			for (int z = 0; z < NE; z++)
			{
				x = true;
				min = a[i][z];
				if (z == 0)
				{
					if (y == 1)
					{
						if (a[i - 1][z] > min)
							x = false;
						else if (a[i + 1][z] > min)
							x = false;
						else if (a[i - 1][z + 1] > min)
							x = false;
						else if (a[i][z + 1] > min)
							x = false;
						else if (a[i + 1][z + 1] > min)
							x = false;
						if (x)
							cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
					}

				}
				else if (z == (NE - 1))
				{
					if (y == 1)
					{
						if (a[i - 1][z] > min)
							x = false;
						else if (a[i + 1][z] > min)
							x = false;
						else if (a[i][z - 1] > min)
							x = false;
						else if (a[i - 1][z - 1] > min)
							x = false;
						else if (a[i + 1][z - 1] > min)
							x = false;
						if (x)
							cout << "The number " << a[i][z] << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
					}
				}
				else
				{
					if (a[i][z + 1] > min)
						x = false;
					else if (a[i][z - 1] > min)
						x = false;
					else if (a[i - 1][z] > min)
						x = false;
					else if (a[i - 1][z + 1] > min)
						x = false;
					else if (a[i - 1][z - 1] > min)
						x = false;
					else if (a[i + 1][z] > min)
						x = false;
					else if (a[i + 1][z + 1] > min)
						x = false;
					else if (a[i + 1][z - 1] > min)
						x = false;
					if (x)
						cout << "The number " << min << " in the position (" << i << ", " << z << ") is a local maxima." << endl;
				}
			}
		}
	}
	/*
	vector<vector<int>> a = { {7,3,4,1,3}, {2,9,6,2,1}, {1,3,5,1,4 }, { 6,5,2,7,5 }, { 4,2,1,3,6 } };
	localMavV(a, true);
	cout << "--------------------------------------------------" << endl;
	localMavV(a, false);
	*/
}

bool year(int x) //4.8
{
	//cin >> x;
	if ((x % 4 == 0) && (x % 100 != 0))
		return true;
	else if (x % 400 == 0)
		return true;
	else
		return false;
}

int DaysOfMonth(int y, int m) //4.8
{
	/*
	bool ValidOperation = true;
	do
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

void plvs_year(vector<vector<int>> &v, int year)//4.8
{
	vector<int> media_mes;
	vector<vector<int>> max_value;
	double media_diaria = 0, mediaa_mensaal = 0;
	int d, x, total_dias = 0, max = 0;
	unsigned int media_mensal;
	for (int i = 1; i <= 12; i++)
	{
		media_mensal = 0;
		v.push_back({});
		d = DaysOfMonth(year, i);
		total_dias += d;
		for (int k = 0; k < d; k++)
		{
			x = rand() % 100;
			if (x > max)
			{
				max = x;
				max_value.resize(0);
				max_value.push_back({k + 1, i});
			}
			else if (x == max)
			{
				max_value.push_back({k + 1,i});
			}
			media_diaria += x;
			media_mensal += x;
			v.at(i - 1).push_back(x);
		}
		media_mes.push_back(media_mensal / d);
	}
	for (int i = 0; i < 12; i++)
	{
		mediaa_mensaal += media_mes.at(i);
	}
	cout << "---------------------------------------" << endl;
	cout << "Media Mensal: " << mediaa_mensaal / 12 << endl;
	cout << "Janeiro: " << media_mes.at(0) << endl;
	cout << "Fevereiro: " << media_mes.at(1) << endl;
	cout << "Março: " << media_mes.at(2) << endl;
	cout << "Abril: " << media_mes.at(3) << endl;
	cout << "Maio: " << media_mes.at(4) << endl;
	cout << "Junho: " << media_mes.at(5) << endl;
	cout << "Julho: " << media_mes.at(6) << endl;
	cout << "Agosto: " << media_mes.at(7) << endl;
	cout << "Setembro: " << media_mes.at(8) << endl;
	cout << "Outubro: " << media_mes.at(9) << endl;
	cout << "Novembro: " << media_mes.at(10) << endl;
	cout << "Dezembro: " << media_mes.at(11) << endl;
	cout << "---------------------------------------" << endl;
	cout << "Media diaria: " << media_diaria / total_dias << endl;
	cout << "---------------------------------------" << endl;
	cout << "Valores maximos: " << endl;
	for (int i = 0; i < max_value.size(); i++)
	{
		cout << max_value.at(i).at(0) << "/" << max_value.at(i).at(1) << endl;
	}
	cout << "---------------------------------------" << endl;
	cout << "Dias em que e superior a media: " << endl;
	for (int i = 1; i <= v.size(); i++)
	{
		d = DaysOfMonth(year, i);
		for (int k = 0; k < d; k++)
		{
			if (v.at(i - 1).at(k) >= (media_diaria / total_dias))
			{
				cout << k + 1 << "/" << i << endl;
			}
		}
	}
	cout << "---------------------------------------" << endl;
}

void quatro_nove()//4.9
{
	//cout << "First:" << endl;
	//cout << "Os valores de x e y vão ficar iguais, pois ao fazer &ref_x = x estamos a dizer que o endereço de ref_x é o mesmo endereço de x (em y igual). Logo, ao igualarmos os ref, estamos a trocar o valor do registo e dessa forma, vamos alterar o valor de todas as variáveis que estão direcionadas para esse mesmo endereço." << endl;
	//int x = 1, y = 2;
	//int& ref_x = x, & ref_y = y;
	//ref_x = ref_y;
	//cout << "x = " << x << "; y = " << y << endl;
	//cout << "ref_x = " << ref_x << "; ref_y = " << ref_y << endl;
	//cout << "------------------------------------------------" << endl;
	cout << "Second:" << endl;
	cout << "Já neste exemplo estamos a dizer que ptr_x e ptr_x são pointers de x e y, respetivamente. Desse modo, ao igualarmos o ptr_x ao ptr_y, o que vamos alterar é o valor do pointer, ou seja, as variáveis vão manter o mesmo valor que tinham inicialmente. Porém, ao o valor de ptr_x e ptr_y vão ser os mesmos." << endl;
	int x = 1, y = 2;
	int* ptr_x = &x, * ptr_y = &y;
	ptr_x = ptr_y;
	cout << "x = " << x << "; y = " << y << endl;
	cout << "ptr_x = " << ptr_x << "; ptr_y = " << ptr_y << endl;
	cout << "*ptr_x = " << *ptr_x << "; *ptr_y = " << *ptr_y << endl;
}

void quatro_dez()//4.10
{
	int values[] = { 2, 4, 5, 7, 11, 13 };
	int* p = values + 1;
	cout << values[1] << endl;
	cout << values + 1 << endl;
	cout << *p << endl;
	cout << *(values + 3) << endl;
	cout << p + 1 << endl;
	cout << p[1] << endl;
	cout << p - values << endl;
	/*
	values[1] = dá o segundo elemento do array
	values+1 = dá o endereço do segundo elemento do array
	*p - dá o valor do primeiro elemento do array, pois o pointer 
	*(values+3) - dá o vlor do quarto elemento do array
	p+1 = dá o endereço a aseguir ao endereço que p tem guardado
	p[1] = dá o primeiro elemento a seguir ao endereço que p tem guardado, logo como p está guardado em 4, o elemento que vai aparecer é 5
	p-values = dá o valor do endereço de p menos o endereço de q
	*/
}

int comp_asc(const void* x, const void* y) //4.11 a)
{
	return *(int*)x - *(int*)y;
	/*
		int a[] = { 99,23,1,76,23,55 };
	int* p;
	p = a;
	qsort(p, 6, 4 ,comp_desc);
	*/
}

int comp_desc(const void* x, const void* y) //4.11 b)
{
	return *(int*)y - *(int*)x;
	/*
		int a[] = { 99,23,1,76,23,55 };
	int* p;
	p = a;
	qsort(p, 6, 4 ,comp_desc);
	*/
}

void read_Array(int* &a, size_t nElem)//4.11 a)
{
	a = (int*)malloc(nElem * sizeof(int));
	for (int i = 0; i < nElem; i++)
	{
		cout << "Give a number. "; cin >> *(a + i);
	}
	cout << a << endl;
	//for (int i = 0; i < nElem; i++)
	//{
	//	cout << *(a + i) << endl;
	//}
	/*
		int* a, n;
	cout << "n? "; cin >> n;
	a = {};
	read_Array(a, n);
	*/
}

int findValue_InArray(const int* a, size_t nElem, int value, size_t pos1, size_t pos2) //4.11 a)
{
	for (int i = pos1; i <= pos2; i++)
	{
		if (value == *(a + i - 1))
			return (i - 1);
	}
	return -1;
	/*
		int nElem, pos1, pos2, value, *a;
	a = {};
	cout << "nElem = "; cin >> nElem;
	read_Array(a, nElem);
	cout << a << endl;
	for (int i = 0; i < nElem; i++)
	{
		cout << a[i] << endl;
	}
	cout << "nElem? "; cin >> nElem;
	cout << "Value? "; cin >> value;
	cout << "pos1? "; cin >> pos1;
	cout << "pos2? "; cin >> pos2;
	cout << findValue_InArray(a, nElem, value,pos1,pos2) << endl;
	*/
}

size_t findMultValues_InArray(const int* a, size_t nElem, int value, size_t pos1, size_t pos2, size_t* index) //4.11 a)
{
	int k = 0, z=0;
	for (int i = pos1; i <= pos2; i++)
	{
		if (value == *(a + i))
		{
			k++;
		}
	}
	index = (size_t*)malloc(k * sizeof(int));
	for (int i = pos1; i <= pos2; i++)
	{
		if (z != k)
		{
			if (value == *(a + i))
			{
				*(index + z) = i;
				z++;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << *(index + i) << endl;
	}
	return k;
	/*
		int pos1, pos2, value, * a;
	size_t* index;
	size_t k[] = {1};
	index = k;
	a = (int*)malloc(8 * sizeof(int));
	read_Array(a, 8);
	for (int i = 0; i < 8; i++)
	{
		cout << *(a + i) << endl;
	}
	cout << "Value? "; cin >> value;
	cout << findMultValues_InArray(a, 5, value, 0, 7, index) << endl;
	*/
}

int findValueInArray(const int* pos1, const int* pos2, int value)
{
	int k = 0, z = 0;
	for (int* i = (int*)pos1; i < (int*)pos2; i ++)
	{
		if (*i = value)
		{
			cout << i << endl;
			return *i;
		}
		z++;
	}
	return -1;
	/*
		int i[] = { 1,2,3,4,5,6,7,8,9,10 };
	const int* pos1 = i + 2, * pos2 = i + 9;
	int k = 0;
	cout << pos1 << ", " << *pos1 << "----" << pos2 << ", " << *pos2 << endl;
	cout << findValueInArray(pos1, pos2, 4);
	*/
}

size_t findMultValuesInArray(const int* pos1, const int* pos2, int value, size_t * index) //4.12
{
	int k = 0, z = 0;
	index = (size_t*)malloc(0 * sizeof(int)); //abrir espaço para um array
	for (int* i = (int*)pos1; i <= (int*)pos2; i++)
	{
		if (value == *i)
		{
			k++;
			index = (size_t*)realloc(index, k * sizeof(int)); //cada vez que encontra um valor igual, redimensiona para aceitar +1
			index[k - 1] = z; //acrescenta o valor
		}
		z++;
	}
	//for (int i = 0; i < k; i++)
	//{
	//	cout << index[i] << endl;
	//}
	//const int a[] = { 1,2,3,4,4,5,5,5,7,4,4 };
	//const int* pos1 = a;
	//const int* pos2;
	//pos2 = &a[9];
	//size_t* index = {};
	//findMultValuesInArray(pos1, pos2, 4, index);
	return k;
}

void fill_grades(int *grade, int NUMBER_STUDENTS, int NUMBER_QUIZZES) // ..... fill... RANDOMLY ! 4.13
{
	int *pt;
	for (int st_num = 1; st_num <= NUMBER_STUDENTS; st_num++)
	{
		pt = &grade[st_num - 1];
		for (int quiz_num = 1; quiz_num <= NUMBER_QUIZZES; quiz_num++)
		{

			pt[quiz_num - 1] = 10 + rand() % 11;
		}
	}
}

void compute_st_ave(int *grade, double* st_ave, int NUMBER_STUDENTS, int NUMBER_QUIZZES) //calcular a média de cada estudante 4.13
{
	int* pt;
	for (int st_num = 1; st_num <= NUMBER_STUDENTS; st_num++)
	{
		pt = &grade[st_num - 1];
		double sum = 0;
		for (int quiz_num = 1; quiz_num <= NUMBER_QUIZZES; quiz_num++)
		{
			sum = sum + pt[quiz_num - 1];
		}
		st_ave[st_num - 1] = sum / NUMBER_QUIZZES;

	}
}

void compute_quiz_ave(int *grade, double *quiz_ave, int NUMBER_STUDENTS, int NUMBER_QUIZZES) //média de cada quiz 4.13
{
	int* pt;
	for (int quiz_num = 1; quiz_num <= NUMBER_QUIZZES; quiz_num++)
	{
		double sum = 0;
		for (int st_num = 1; st_num <= NUMBER_STUDENTS; st_num++)
		{
			pt = &grade[st_num - 1];
			sum = sum + pt[quiz_num - 1];
		}
		quiz_ave[quiz_num - 1] = sum / NUMBER_STUDENTS;

	}
}

void display(int* grade , const double *st_ave, const double *quiz_ave, int NUMBER_STUDENTS, int NUMBER_QUIZZES) //4.13
{
	int* pt;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);
	cout << setw(10) << "Student"
		<< setw(5) << "Ave"
		<< setw(12) << "Quizzes\n";
	for (int st_num = 1; st_num <= NUMBER_STUDENTS; st_num++)
	{
		pt = &grade[st_num - 1];
		cout << setw(10) << st_num << setw(5) << st_ave[st_num - 1] << " ";
		for (int quiz_num = 1; quiz_num <= NUMBER_QUIZZES; quiz_num++)
			cout << setw(5) << pt[quiz_num - 1];
		cout << endl;
	}
	cout << "Quiz averages = ";
	for (int quiz_num = 1; quiz_num <= NUMBER_QUIZZES; quiz_num++)
		cout << setw(5) << quiz_ave[quiz_num - 1];
	cout << endl;
}

//int main() 4.13
//{
//	int number_students, number_quizzes;
//	cout << "please give the number of students: "; cin >> number_students;
//	cout << "please give the number of quizzes: "; cin >> number_quizzes;
//	int* grade;
//	grade = (int*)malloc(number_students * number_quizzes * sizeof(int));
//	double* st_ave;
//	st_ave = (double*)malloc(number_students * sizeof(double));
//	double* quiz_ave;
//	quiz_ave = (double*)malloc(number_quizzes * sizeof(double));
//	fill_grades(grade, number_students, number_quizzes); // randomly !!!
//	compute_st_ave(grade, st_ave, number_students, number_quizzes);
//	compute_quiz_ave(grade, quiz_ave, number_students, number_quizzes);
//	display(grade, st_ave, quiz_ave, number_students, number_quizzes);
//}

int main()
{
	//vector<vector<int>> v;
	//srand(123123);
	///*srand(time(NULL));*/
	//plvs_year(v, 2020);
	int a[] = { 99,23,1,76,23,55 };
	int* p;
	p = a;
	qsort(p, 6, 4, comp_desc);
	return 0;
}