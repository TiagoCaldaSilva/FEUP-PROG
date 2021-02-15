#include "Board.h"

using namespace std;

Board::Board() {							//Board's constructor
	height = 0;
	width = 0;
	board_letters.clear();
	all_generated_words.clear();
	num_letters_board = 0;
	message.clear();
}



int Board::inputValue()	const			//Returns the integer value of the input (used to set dimensions)
{
	int number = 0;
	bool check;
	string input;
	do {
		check = true;
		getline(cin, input);
		Helpers::clearInput();
		for (size_t i = 0; i < input.size(); i++)							//Verify if all characters are numbers
			if (int(input[i]) < ASCII_0 || int(input[i]) > ASCII_9) {
				check = false;
				break;
			}
		if (check)
			number = stoi(input);
		if (check == false || MIN_BOARD_SIZE > number || number > MAX_SIZE_LIMIT)
			cout << RED << "Invalid input. Input a number between 0 and 20" << NO_COLOR << endl;
	} while (check == false || MIN_BOARD_SIZE > number || number > MAX_SIZE_LIMIT);
	return number;
}



char Board::getWordOrientation() {			//Asks the user for the orientation of the word (horizontal or vertical)
	string str_orientation;
	char orientation;
	cout << "Choose the orientation of the word ('h' -> horizontal ; 'v' -> vertical):" << endl;
	do {
		getline(cin, str_orientation);
		Helpers::clearInput();
		orientation = str_orientation[0];
		if (str_orientation.size() != 1 || (orientation != 'h' && orientation != 'v')) 
			cout << RED << "Input invalid. Choose the orientation of the word ('h' -> horizontal ; 'v' -> vertical):" << NO_COLOR << endl;
	} while (str_orientation.size() != 1 || (orientation != 'h' && orientation != 'v'));
	return orientation;
}

void Board::getDimension() {				//Asks the user for the size of the board
	cout << "Board_letters's width (max = "<< MAX_SIZE_LIMIT << "):" << endl;
	width = inputValue();
	cout << "Board_letters's height (max = "<< MAX_SIZE_LIMIT << "):" << endl;
	height = inputValue();
}

string Board::getWord() {					//Asks the user for a word and verifies if it belongs to the dictionary 
	Words _words;
	string str_word;
	cout << "Input a word according to the dictionary (lowercase words)." << endl
		<< "If you want to end the board builder type 'STOP'. To undo last move type 'UNDO' and if you want to reset all the progress type 'RESET'" << endl;

	do {
		getline(cin, str_word);
		Helpers::clearInput();
		if (str_word != "STOP" && str_word != "UNDO" && str_word != "RESET" && _words.checkWord(str_word) == false) 
			cout << RED << "Input invalid. Please input another word in lowercases or one of 'STOP', 'UNDO' or 'RESET'" << NO_COLOR << endl;
	} while (_words.checkWord(str_word) == false && str_word != "STOP" && str_word != "UNDO" && str_word != "RESET");
	return str_word;
}

string Board::getWordCoordinates() {		//Asks the user for the position of the board to place the word

	bool check = false;
	string s_pos;

	cout << "Choose the position for the word according to the board: (in the format 'Aa', A -> y and a -> x) " << endl;
	do {
		getline(cin, s_pos);
		Helpers::clearInput();
		if (s_pos.size() != 2) 
			cout << RED << "Format invalid. Example 'Xx'" << NO_COLOR << endl;
		else if (int(s_pos[0]) <= (A_UPPERCASE_ASCII_NUM - 1) || int(s_pos[0]) > A_UPPERCASE_ASCII_NUM + height) 
			cout << RED << "Input invalid. The line of the board is invalid" << NO_COLOR << endl;
		else if (int(s_pos[1]) <= (A_LOWERCASE_ASCII_NUM - 1) || int(s_pos[1]) > A_LOWERCASE_ASCII_NUM + width) 
			cout << RED << "Input invalid. The column of the board is invalid" << NO_COLOR << endl;
		else 
			check = true;
	} while (check == false);
	return s_pos;
}

bool Board::getAllGeneratedWords() {		//Returns true if there are no errors with any word and adds to a list all words that are in the board
	int i, j;
		Words _words;
		Word board_word;
		all_generated_words.clear();
		for (i = 1; i <= height; i++) 		//Horizontal
			for (j = 1; j <= width; j++) 

				if (int(board_letters[i][j]) != SPACE_ASCII_NUM && (int(board_letters[i][j - 1]) == SPACE_ASCII_NUM || j == 1) && j<width && int(board_letters[i][j + 1]) != SPACE_ASCII_NUM) {	//First letter of one word

					board_word.setY(i);
					board_word.setX(j);
					board_word.setCoordinates(Helpers::coordinatesToString(j, i));
					board_word.setOrientation('h');
					board_word.appendLetterWord(board_letters[i][j]);
				}
				else if ((int(board_letters[i][j]) == SPACE_ASCII_NUM || j == width) && int(board_letters[i][j - 1]) != SPACE_ASCII_NUM && j > 1 && board_word.getWord() != "") { 	//Last letter of one word, if it is on the board's limit or first space after the word

					if (j == width && board_letters[i][j] != SPACE_ASCII_NUM) 	//If the last letter is on the limit of the board
						board_word.appendLetterWord(board_letters[i][j]);
					if (_words.checkWord(board_word.getWord())) {				//If the word is in the dictionary add to the list of the words
						all_generated_words.push_back(board_word);
						board_word.clearWord();
					}
					else
						return false;
				}
				else if (int(board_letters[i][j]) != SPACE_ASCII_NUM && board_word.getWord() != "")	//Middle letters of one word
					board_word.appendLetterWord(board_letters[i][j]);
		for (j = 1; j <= width; j++) 	//Vertical
			for (i = 1; i <= height; i++) 
				if (int(board_letters[i][j]) != SPACE_ASCII_NUM && (int(board_letters[i - 1][j]) == SPACE_ASCII_NUM || i == 1) && i<height && int(board_letters[i + 1][j]) != SPACE_ASCII_NUM) {	//First letter of one word
					board_word.setY(i);
					board_word.setX(j);
					board_word.setCoordinates(Helpers::coordinatesToString(j, i));
					board_word.setOrientation('v');

					board_word.appendLetterWord(board_letters[i][j]);
				}
				else if ((int(board_letters[i][j]) == SPACE_ASCII_NUM || i == height) && int(board_letters[i - 1][j]) != SPACE_ASCII_NUM && i > 1 && board_word.getWord() != "") {		//Last letter of one word if it is on the board's limit or first space after the word
					
					if (i == height && board_letters[i][j] != SPACE_ASCII_NUM) 	//If the last letter is on the limit of the board
						board_word.appendLetterWord(board_letters[i][j]);
					if (_words.checkWord(board_word.getWord())) {				//If the word is in the dictionary add to the list of the words
						all_generated_words.push_back(board_word);
						board_word.clearWord();
					}
					else {
						return false;
					}
				}
				else if (int(board_letters[i][j]) != SPACE_ASCII_NUM && board_word.getWord() != "") 	//Middle letters of one word
					board_word.appendLetterWord(board_letters[i][j]);
		return true;
}



void Board::initVectors() {					//Initialize the board according to the dimensions given by user with only the letters for the rows and lines of the board
	int i, j;
	board_letters.resize(height + 1);
	for (i = 0; i <= height; i++) 
		board_letters[i].resize(width + 1);
	for (i = 0; i <= height; i++) 
		for (j = 0; j <= width; j++) 
			board_letters[i][j] = ' ';
	for (i = 1; i <= height; i++) 
		board_letters[i][0] = char(A_UPPERCASE_ASCII_NUM - 1 + i);
	for (i = 1; i <= width; i++) 
		board_letters[0][i] = char(A_LOWERCASE_ASCII_NUM - 1 + i);
}



void Board::showBoardLetters() {																					//Clears the terminal and prints the board
	int i, j;
	cout << "\033[2J\033[H";																						//Clears the terminal
	for (i = 0; i <= height; i++) {
		for (j = 0; j <= width; j++) 
			if (j > 0 && i > 0 && int(board_letters[i][j]) != SPACE_ASCII_NUM)										//Print a white letter with grey background
				cout << DARKGRAY << WHITE << char(int(board_letters[i][j]) - SPACE_ASCII_NUM) << ' ' << NO_COLOR; 	//Transform lowercase character into uppercase character
			else if (j > 0 && i > 0)																				//Print grey background without any letter
				cout << DARKGRAY << board_letters[i][j] << ' ' << NO_COLOR;
			else 
				cout << CYAN << board_letters[i][j] << NO_COLOR << ' ';
		cout << endl;
	}
	cout << endl;
}

void Board::showMessage() {					//Prints the message, yellow if it is a warning or red if it is an error
	if (message_type == "warning")
		cout << YELLOW << message << NO_COLOR << endl << endl;
	else if (message_type == "error")
		cout << RED << message << NO_COLOR << endl << endl;
}



bool Board::addNewWord() {					//Function that adds a new word to the board if there aren't errors
	string word, str_answer;
	word = getWord();
	char answer;
	if (word != "STOP" && word != "UNDO" && word != "RESET") {		
		words.addWord(getWordCoordinates(), getWordOrientation(), word);
		if (fillBoardLettersWithWords()) 	
			if (!getAllGeneratedWords()) {
				words.removeLastWord();
				message = "Additional word created invalid.";
				message_type = "error";
				fillBoardLettersWithWords();
			}
			else 
				newWords();
		else {
			words.removeLastWord();
			fillBoardLettersWithWords();
			message = "Invalid word for the position of the board given by the user";
			message_type = "error";
		}
	}
	else if (word == "UNDO") 				//If the user wants to undo last move
		if (words.removeLastWord()) {
			fillBoardLettersWithWords();
			getAllGeneratedWords();
			updateAllGeneratedWordsCopy();
			message = "You undo the last move you made";
			message_type = "warning";
		}
		else {
			message = "You can't undo because there are no words in the board";
			message_type = "error";
		}
	else if (word == "RESET")				//If the user wants to reset the board
		if (words.resetWords()) {
			initVectors();
			getAllGeneratedWords();
			updateAllGeneratedWordsCopy();
			message = "You reset all words.";
			message_type = "warning";
			}
		else {
			message = "You can't reset because there are no words in the board";
			message_type = "error";
		}
	else if (word == "STOP") {				//If the user wants to stop the program (the board must have at least 6 letters to play)
		numberLettersBoard();
		if (num_letters_board < 6) {
			cout << "The board does not have enough letters to play scrabble. Are you sure that you still want to exit? 'y'/'n'" << endl;
			do {
				getline(cin, str_answer);
				Helpers::clearInput();
				answer = str_answer[0];
				if (str_answer.size() != 1 || (answer != 'y' && answer != 'n')) 
					cout << "Input invalid. Aswer with 'y' or 'n' ('y' -> yes; 'n -> no):" << endl;
			} while (str_answer.size() != 1 || (answer != 'y' && answer != 'n'));
			if (answer == 'n')
				return true;
		}
		return false;
	}
	return (word != "STOP");
}

bool Board::fillBoardLettersWithWords() {		//If it's possible, add the letters of the words to the board
	Word word;
	int i, j, lenght;
	initVectors();
	for (i = 0; i < words.getNumWords(); i++) {		
		word = words.getWordFromWords(i);
		lenght = word.getWord().size();
		if (word.getOrientation() == 'h') {			//Horizontal
			for (j = 0; j < lenght; j++) {
				if (lenght - 1 + word.getX() <= width && (int(board_letters[word.getY()][word.getX() + j]) == SPACE_ASCII_NUM || board_letters[word.getY()][word.getX() + j] == word.getWord()[j])) { //If the word fits on the board
					board_letters[word.getY()][word.getX() + j] = word.getWord()[j];
				}
				else
					return false;
			}
		}
		else {										//Vertical
			for (j = 0; j < lenght; j++) {
				if (lenght - 1 + word.getY() <= height && (int(board_letters[word.getY() + j][word.getX()]) == SPACE_ASCII_NUM || board_letters[word.getY() + j][word.getX()] == word.getWord()[j])) { //If the word fits on the board
					board_letters[word.getY() + j][word.getX()] = word.getWord()[j];
				}
				else
					return false;
			}
		}
	}
	return true;
}

void Board::newWords() {						//This function does a warning about the words that were added or modified on the board
	size_t i, j;
	bool check;
	string modified_word;
	vector<string> modified_words;
	modified_words.clear();
	message_type = "warning";
	for (i = 0; i < all_generated_words.size(); i++) {
		check = false;
		for (j = 0; j < all_generated_words_copy.size(); j++) {
			if (all_generated_words[i].getWord() == all_generated_words_copy[j].getWord() && all_generated_words[i].getOrientation() == all_generated_words_copy[j].getOrientation() 
				&& all_generated_words[i].getCoordinates() == all_generated_words_copy[j].getCoordinates()) { 		//If the object word is in the original and in the copy has not been modified
				check = true;
				break;
			}
		}
		if (check == false) 
			modified_words.push_back(all_generated_words[i].getWord());
	}
	if (modified_words.size() == 1) {			//If there is only 1 difference
		modified_word = Helpers::toUpper(modified_words[0]);
		message = "The word " + modified_word + " was added to the board";
	}
	else if (modified_words.size() == 0)
		message = "Nothing was changed";
	else {
		message = "The words "; 				//If there is 2 or more differences
		for (i = 0; i < modified_words.size(); i++) {
			modified_word = Helpers::toUpper(modified_words[i]);
			if (i == modified_words.size() - 1)
				message += modified_word + " ";
			else
				message += modified_word + " && ";
		}
		message += "were added or modified";
	}
	updateAllGeneratedWordsCopy();
}

void Board::numberLettersBoard() {				//Gives the number of the letters in the board
	int i, j;
	for (i = 1; i <= height; i++) 
		for (j = 1; j <= width; j++) 
			if (board_letters[i][j] != SPACE_ASCII_NUM) 
				num_letters_board++;			//Number of letters in the board
}

void Board::updateAllGeneratedWordsCopy() {							//Update the copy according to the original vector
	all_generated_words_copy.clear();
	for (size_t i = 0; i < all_generated_words.size(); i++) 		//Update the copy of the list of words present on the board
		all_generated_words_copy.push_back(all_generated_words[i]);
}

void Board::fileOut() { 											//Returns a file with all words to use in the Scrabble Junior
	size_t i;
	string name_file, word_to_file;
	if (num_letters_board >= 6) {
		cout << "Input the name of the file to save the board. Example: 'board' " << endl;
		cin >> name_file;
		Helpers::clearInput();
		name_file = name_file + ".txt";
		ofstream outfile(name_file);
		outfile << to_string(width) << " x " << to_string(height) << endl;
		for (i = 0; i < all_generated_words.size(); i++) {
			word_to_file = Helpers::toUpper(all_generated_words[i].getWord());
			outfile << all_generated_words[i].getCoordinates() << ' ' << char(int(all_generated_words[i].getOrientation()) - SPACE_ASCII_NUM) << ' ' << word_to_file << endl;
		}
		outfile.close();
	}
}
