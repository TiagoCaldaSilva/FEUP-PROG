#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>


void toUpperStr(std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}

std::string transformLine(const std::string& str)
{
	std::string result;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))
			result[i] += toupper(str[i]);
		else
			result[i] += ' ';
	}
	return result;
}

void decomposeLine(const std::string& line, std::vector<std::string> words)
{
	std::string str = transformLine(line), word;
	std::stringstream x(str);
	while (x.good())
	{
		x >> word;
		words.push_back(word);
	}
}

void Ex_1d()
{
	std::vector<std::string> words;
	std::string text;
	std::ifstream str_in;
	std::ofstream str_out;
	str_in.open("C:\docs\text.txt");
	while (getline(std::cin, text, '\n'))
	{
		decomposeLine(text, words);
	}
	str_in.close();
	sort(words.begin(), words.end());
	str_out.open("words.txt");
	for (size_t i = 0; i < words.size(); i++)
	{
		str_out << words[i] << std::endl;
	}
}

void ex_1e()
{
	std::cout << "Em vez de colocar as palavras todas num vetor, colocaria as palavras num set, pois este n�o permite elementos repetido e as palavras ficam organiadas por ordem alfab�tica. Deste modo tamb�m n�o seria necess�rio utilizar o sort.";
}

void ex_2a()
{
	std::cout << "N�o � poss�vel fazer a declara��o \"Ship s\" pois na declara��o da classe Ship existe apenas um construtor e este n�o � um construtor sem parametros (logo, como existe um construtor e este � "
		<< "sem parametros perdemos o acesso aquele que era disponibilixado podendo apenas declarar objetos desta classe da seguinte forma \"Ship s(...)\". J� na classe board apesar de n�o existir construtor"
		<< "sem parametros, os parametros do construtor que existe, j� est�o inicializados tomando os valores que l� est�o (10 e 10) se n�o existirem parametros." << std::endl;
}

/*
constructer da classe board
*/

void Board(size_t numLines = 10, size_t numColumns = 10)
{
	std::vector<std::vector<int>> board;
	std::vector<int> mar(numColumns, -1);
	for (int i = 0; i < numLines; i++)
	{
		board.push_back(mar);
	}
}

struct Position
{
	int lin, col;
};
bool canPutShip(Position pos, char dir, size_t size)
{
	std::vector<std::vector<int>> board;
	size_t numLines =0 , numColumns =0;
	switch (dir) // TO DO
	{
	case ('H'): // TO DO: test if ship with length 'size' can be put at 'pos', in horizontal direction         
		for (size_t i = 0; i < size; i++) //supor que posi��es come�am em (1,1) e acabam em (numLines, numcolumns)
		{
			if (pos.lin > numLines || pos.col > numColumns)
			{
				return false;
			}
			else if (board[pos.lin][pos.col] != -1)
			{
				return false;
			}
			else
			{
				pos.col++;
			}
		}

	case ('V'): // TO DO, just this line: test if ship ... can be put in vertical direction
		// DONE. This piece of code was correctly implemented but was carelessly erased �
		for (size_t i = 0; i < size; i++) //supor que posi��es come�am em (1,1) e acabam em (numLines, numcolumns)
		{
			if (pos.lin > numLines || pos.col > numColumns)
			{
				return false;
			}
			else if (board[pos.lin][pos.col] != -1)
			{
				return false;
			}
			else
			{
				pos.lin++;
			}
		}
	}
	return true;
}

/*

PERGUNTA 2.D

bool putShip(const Ship& s)
{
	if (!canPutShip(s.pos(), s.dir(), s.size()))
		return false;
	else
	{
		ships.push_back(s);
		switch (s.dir())
		{
		case('H'):
			for (size_t i = 0; i < s.size(); i++)
			{
				board[s.pos().lin][s.pos().col + i] = s.id();
			}
		case('V'):
		{
			for (size_t i = 0; i < s.size(); i++)
			{
				board[s.pos().lin + i][s.pos().col] = s.id();
			}
		}
	}
	return true;
}


PERGUNTA 2.E

class InvalidInput
{
public:
	InvalidInput(const std::string& message) {this->message = message;};
	std::string what() { return message; };
private:
	std::string message;
};
int main()
{
	Board board(10, 20);
	unsigned int identifier; char symbol; Position position; char direction;  size_t size;
	bool valid;
	std::cout << "Please give an identifier: "; std::cin >> identifier;
	std::cout << "Please give a symbol: "; std::cin >> symbol;
	std::cout << "In which line do you desire to put the ship? "; std::cin >> position.lin;
	std::cout << "In which line do you desire to put the ship? "; std::cin >> position.col;
	std::cout << "What is the size of the ship? "; std::cin >> size;
	Ship s(identifier, symbol, position, direction, size);
	try
	{
		if (!board.putShip(s))
			throw InvalidInput("Can\'t put ship!");
	}
	catch (InvalidInput e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
*/

float average(const int grades[], int numStudents) //3.a1)
{
	float sum = 0;
	for (int i = 0; i < numStudents; i++)
	{
		sum += grades[i];
	}
	return (sum / float(numStudents));
}

//void grades()
//{
//	float ave;
//	int numStudents;
//	int* grades;
//	std::cout << "Please give the number of the students that you want to define: "; std::cin >> numStudents;
//	grades = (int*)malloc(sizeof(int) * numStudents);
//	readGrades(grades, numStudents);
//	ave = average(grades, numStudents);
//	std::cout << "A m�dia �: " << ave << std::endl;
//}

void ex_3b(std::vector<std::string> v)
{
	//sim � poss�vel pois os vetores s�o uns dos containers dos c++ e desta forma � pos�veis correr todos os seus elementos atrav�s dos seu iteradores
	//Deste modo, atrav�s do find podemos correr todos os elementos do vetor, se houver nele algum elemento igual a val, retorna o seu iterador, se n�o retorna 
	//iterador equivalente ao vetor.end() (iterador a seguir ao �ltimo elemento do vetor que marca o fim do mesmo)
	if (find(v.begin(), v.end(), "31") != v.end())
		std::cout << "The vector has the value \"31\"";
	else
		std::cout << "The value \"31\" isn't in the vector.";
}

void ex_3c()
{
	/*
	O container set � um container que guarda os elementos n�o repetidos e de forma ordenada (se n�o for especificada nenhuma ordem, o padr�o � ordem alfab�tica, ordem crescente (dependendo do tipo de dados))
	Como a struct position foi criada pelo useer, n�o existe ordem padr�o pelo que o compilador n�o vai saber qual a forma como deve ordenar os elementos do set, n�o sendo ent�o poss�vel
	Uma forma de resolver este erro era criar uma classe position e implementar os operadores de compara��o (<= ou =>) ou ent�o utilizar um unordered set que n�o vai precisar de colocar os elementos por ordem
	*/
}

void ex_3d()
{
	/*
	a)Primeiro ir� aparecer no ecr� 2 3, depois na linha seguinte, apenas ir� aparecer o n�mero 2 e depois na linha seguinte volta  aaparecer 2 3
	b)Igual � respondida em cima, por�m na �ltima linha teria o mesmo input da segunda: apenas o n�mero 2
	c) A classe Derived n�o iria ter acesso ao objeto _a  da classe Base. Pois quando os objetos est�o como protected significa que no exterior � classe e as duas derivadas
	est�o como private por�m para as suas classes derivadas estes objetos/argumentos podem ser utilizados. Deste modo ao alteramos o argumento de protected para private, as classes privadas
	deixariam de ter acesso n�o sendo poss�vel, por exemplo, executar a fun��o show() da classe derived pois o compilador n�o iria reconhecer _a logo iria dar erro.
	*/
}

class Base {
public:
	Base(int a) { _a = a; }
	virtual void show() const { std::cout << _a; }
protected:
	int _a;
};
//================================================
class Derived : public Base {
public:
	Derived(int a, int b) : Base(a) { _b = b; }
	void show() const { std::cout << _a << ' ' << _b; }
private:
	int _b;
};
//================================================
int main()
{
	Derived d(2, 3);
	d.show(); std::cout << std::endl;
	Base b = d;
	b.show(); std::cout << std::endl;
	Base* pb = &d;
	pb->show(); std::cout << std::endl;
}