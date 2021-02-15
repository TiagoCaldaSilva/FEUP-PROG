#include "Board.h"

using namespace std;

Board::Board()
{
	setBoard(DEFAULT_FILE);
}

void Board::resizeALL()
{
	wordsH.clear();
	wordsV.clear();
	letters.clear();
	colouredLetters.clear();
	initialLetters.clear();
	lines = 0; columns = 0;
}

void Board::addLetters(pair<int, int> position, const string word, vector<char>& pool, const pair<int, int> sum) //Function used to add letters to the pool and to the map letters
{
	for (size_t i = 0; i < word.length(); i++)
	{
		if (letters.find(position) == letters.end())				//To avoid add letters that are placed in the same position (crossed words)
		{
			letters[position] = word[i];							//If the position isn't in the map of the letters, it's a new letter so it needs to be added to the map and to the pool
			pool.push_back(word[i]);
		}
		position.first += sum.first;								//Sum will be (0, 1) if the direction of the word is H (to add letters in the same line)
		position.second += sum.second;								//Sum will be (1, 0) if the direction of the word is V (to add letters in the same column)
	}
}


/*=================|SET FUNCTIONS|=================*/
//Function used to build the board of the game

void Board::setBoard(const string file)
{
	resizeALL();									//Reset the board (if the player wants to play with his board, the default board should be cleared)
	vector<char> pool;								//The vector of letters that, later, will be assign to the pool
	ifstream str_in;
	pair<int, int> position;
	string line, temp_position, word;
	char direction, x_ignore;						//The char 'x' is the char between the number of the lines and the number of columns (it must be ignored)

	str_in.open(file);

	/*
	*The first line of the file is:
	*	NUMBER_OF_LINES x NUMBER_OF_COLUMNS 
	*So, the first number is the number of lines and the other is the number of columns, the char between this numbers, must be ignored (using x_ignored)
	*/

	getline(str_in, line, '\n');
	istringstream first_line(line);
	first_line >> lines >> x_ignore >> columns;

	/*
	*All of the other lines of the file have the same structure:
	*
	*	LINE COLUMN SPACE DIRECTION SPACE WORD ex: Ab H Banana
	*	The first 2 chars are the position;
	*	The 4th char is the direction;
	*	The word starts in the 6th char
	*/

	while (getline(str_in, line, '\n'))													//While is possible to read the lines of the given file
	{
		istringstream read_file(line);
		read_file >> temp_position >> direction >> word;	
		position = newPair(temp_position[0], temp_position[1]);							//Turns the temp_position to position: from (char, char) to (int, int)
		toUpper(word);

		if (direction == 'H')															//If the direction of the word is H, it should be added to the map of the horizontal word
		{
			wordsH[position] = word;
			addLetters(position, word, pool, pair<int, int>(0, 1));						//All the letters of the word are added in a vector that will be used later to set the pool
		}																				//Pair<int, int>(0, 1) because the direction is H, so we will need to increment the number of the line
		else
		{
			wordsV[position] = word;													//Otherwise, the word is added in the map of the vertical words
			addLetters(position, word, pool, pair<int, int>(1, 0));						//Pair<int, int>(1, 0) because the direction is V, so we will need to increment the number of the column
		}
	}
	str_in.close();
	initialLetters = pool;
}


/*=================|GET FUNCTIONS|=================*/
//The following functions are used to return the class attributes and their properties

int Board::getLines() const					//Returns the number of lines of the board
{
	return lines;
}

int Board::getColumn() const				//Returns the number of columns of the board
{
	return columns;
}

vector<char> Board::getPool() const			//Returns a vector with all the letters used in the board
{
	return initialLetters;
}

int Board::getNumberLetters() const			//Returns the number of  letters of the board
{
	return letters.size();
}


/*=================|VALIDATION FUNCTIONS|=================*/
//The following functions are used to check the moves

bool Board::isValid(const char l)						//Function used to verifiy if the given letter is valid to play
{
	for (auto elem : wordsH)							//Verify if there is any word that the first letter is equal to the chosen letter
	{
		if (elem.second[0] == l)
			return true;
	}
	for (auto elem : wordsV)							//If there aren't letters in the horizontal map, search in the vertical map
	{
		if (elem.second[0] == l)
			return true;
	}
	return false;
}

bool Board::validMove(const pair<int, int> position, const char l)				//Function used to verify if a move is valid
{
	bool valid = false;
	if (wordsH.find(position) != wordsH.end())									//If the given position is associated to some word
		valid = (wordsH[position][0] == l);										//If true, verifies if the first letter of the word is equal to the given letter
	if (!valid && wordsV.find(position) != wordsV.end())						//If the move isn't valid to the horizontal words, verify in the vertical words
		valid = (wordsV[position][0] == l);
	return valid;
}


/*=================|PLAY FUNCTIONS|=================*/
//Functions that are responsible for processing players' moves


/*Function that determines if the player played the last tile of the word and returns the score
*
*@param modify is the map (wordsH, wordsV) that will be changed (because has the word, that the first letter, is in the position given by "position")
*@param position is the position of the letter that has been played, the position of the first letter of the word
*@param sum, if modify == wordsH => (0, 1) because the next letter is in the same line and in the next column
*			else (wordsV) => (1, 0) because the next letter is in the next line and in the same column
*
*/

int Board::modifyHVMap(map<pair<int, int>, string>& modify, pair<int, int> position, const pair<int, int> sum)
{
	string word;
	word = modify[position];								//Word is now the word that is assign to the given position
	word.erase(0, 1);										//Remove the first letter of the word
	modify.erase(position);									//Remove the position because the position that must be assign to the new word is the position of the next letter available in the word
	if (word.length() != 0)									//If there are more letters available in the word, the map must be updated
	{
		do
		{													//In this loop the pair "position" wil be incremented with the pair "sum", in order to find the next letter available of the word
			position.first += sum.first;
			position.second += sum.second;
		} while (letters.find(position) == letters.end());	//The map letters has all the available letters of the board
		modify[position] = word;
		return 0;											//If the position was found, update the map and return 0, because the tile played wasn't the last letter of the word	
	}
	return 1;												//If there are no more letters available in the word the player will score 1
}


/*Function used to verify if the player played a letter in the mid of the word (because of the crossed words)
*
*@param modify is the map (wordsH, wordsV) that will be changed (because the letter played is the first letter of a word of the opposite map)
*@param position is the position of the letter that has been played
*@param sum, if modify == wordsH => (0, 1) because all the letters of the word are in the same line (modify only the column number, pair(line, column))
*			else (wordsV) => (1, 0) because all the letters of the word are in the same column (modify only the line number, pair(line, column))
*
*/

int Board::crossedWords(map<pair<int, int>, string>& modify, pair<int, int> position, const pair<int, int> sum, const int lim)
{
	string word;
	pair<int, int> verification(0, 0), edit_position;					//Edit_position is where will be saved the position that must be changed


	if (sum.first)														//If sum = (1,0), modify = wordsV because all the words are in th same column
	{
		verification.second = position.second;							//In this case it's necessary to find if there is any word in the same column with a letter in the position played
	}
	else																//If sum = (0,1), modify = wordsH because all the words are in the same line
	{
		verification.first = position.first;							//In this case it's necessary to find if there is any word in the same line with a letter in the position played
	}


	for (int i = 0; i < lim; i++)										//Verify if there is a word in the given line/column
	{
		if (modify.find(verification) != modify.end())
		{
			edit_position = verification;
			word = modify[verification];								//'word' is now the word that was found
			for (size_t k = 0; k < word.size(); k++, i++)				
			{
				if (position == verification)							//If there is a letter in the given position it belongs to 2 words (V and H)
				{
					word.erase(k, 1);									//Remove the letter of the word
					modify.erase(edit_position);
					if (word.length() != 0)								//If there are more letters available in the word
					{
						if (edit_position == verification)				//If the tile played is the first letter of the crossed word, the position must be changed
						{
							edit_position.first += sum.first;
							edit_position.second += sum.second;
						}
						modify[edit_position] = word;
					}
					else												//If there are no more letters available in the word, the player scores
					{
						return 1;
					}
				}
				verification.first += sum.first;
				verification.second += sum.second;
			}
		}
		verification.first += sum.first;
		verification.second += sum.second;
	}
	return 0;
}


int Board::update(const pair<int, int> position)		//This function will update the maps and will return the score that must be added to a player with the move chosen
{
	int score = 0;
	if (wordsH.find(position) != wordsH.end())														//If there is a word in wordsH with the first letter in the given position
	{
		score += crossedWords(wordsV, position, pair<int, int>(1, 0), lines);
		score += modifyHVMap(wordsH, position, pair<int, int>(0, 1));
	}
	else if (wordsV.find(position) != wordsV.end())													//If there is a word in wordsV with the first letter in the given position
	{
		score += crossedWords(wordsH, position, pair<int, int>(0, 1), columns);
		score += modifyHVMap(wordsV, position, pair<int, int>(1, 0));
	}
	colouredLetters[position] = letters[position];													//The letter played should now appear on the board with another color
	letters.erase(position);
	return score;
}

/*=================|OTHER FUNCTIONS|=================*/

void Board::showBoard()									//This function shows on the screen the game board
{
	pair<int, int> position;
	for (int i = -1; i < lines; i++)					//This loop updates the number of the line that is going to be shown
	{
		position.first = i;
		for (int j = -1; j < columns; j++)				//This loop updates the number of the column that is going to be shown
		{
			position.second = j;
			if (i == -1 && j == -1)						//(-1,-1) is the top left corner of the table, which has nothing
			{
				setColor(EDGES);
				cout << "\n\t\t\t   ";
			}
			else if (i == -1 && j != -1)				//First line of the table, with the identification of the columns
			{
				setColor(EDGES);
				cout << ' ' << char(j + ASCII_a) << ' ';
			}
			else if (j == -1 && i != -1)				//First column of the table, with the identification of the lines
			{
				setColor(EDGES);
				cout << "\t\t\t " << char(ASCII_A + i) << ' ';
			}
			else
			{
				setColor(GAMEBOARD);
				if (letters.find(position) != letters.end())
				{
					cout << ' ' << letters[position] << ' ';
				}
				else if (colouredLetters.find(position) != colouredLetters.end())
				{
					setColor(LETTERS_PLAYED);
					cout << ' ' << colouredLetters[position] << ' ';
				}
				else
				{
					cout << "   ";
				}
			}
		}
		cout << endl;															//Next line
	}
	cout << endl
		<< endl;
	setColor(TEXT_COLOR);
}

bool Board::endGame() const			//Function that determinates if the game should end
{
	return(letters.size() == 0);	//If there aren't more letters to play, the game should end (returns true)
}
