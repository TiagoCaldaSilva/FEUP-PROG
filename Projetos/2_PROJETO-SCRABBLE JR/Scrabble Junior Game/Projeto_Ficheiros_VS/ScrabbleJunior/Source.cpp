#define MIN_PLAYERS 2			//Minimum number of players
#define MAX_PLAYERS 4			//Maximum number of players
#define TILES_PER_TURN 2		//Maximum number of tiles played per turn
#define MINIM_PER_PLAYER 3		//Minimum number of tiles per player
#define MENUCOLOR 3
#define MENU_BOXES_COLOR 7
#define MENU_TEXT_COLOR 6

#include <ctime>
#include <conio.h>
#include "Scrabble_Junior.h"

using namespace std;


void invalidInput(bool& validInput)
{
	setColor(ERROR_COLOR);
	cout << "Invalid input. Please try again. ";
	setColor(TEXT_COLOR);
	validInput = !validInput;
}



void fileName(string& file)
{
	ifstream str_in;
	bool validInput;

	cout << "\nWhat is the name of the file with the words of the Board? ";
	do
	{
		validInput = true;
		getline(cin, file, '\n');
		if (cin.fail())
		{
			cin.clear();
			validInput = false;
		}
		else if (file.find(".txt") > file.length())						//If the given name doesn't have the extension ".txt", the program adds it at the end of the string
		{
			file += ".txt";
		}
		str_in.open(file);
		if (!str_in.is_open())
		{
			validInput = false;											//If the file name given is invalid, repeat all
		}
		if (!validInput)
		{
			setColor(ERROR_COLOR);
			cout << "Invalid file opening input. Please try again. ";
			setColor(TEXT_COLOR);
		}
	} while (!validInput);
}



string verifyInput(Board& board, Player& player, bool play, const int lines, const int column)
{
	setColor(TEXT_COLOR);
	int score;
	string str;
	char letter;
	bool validInput, again;
	pair<int, int> position;
	do
	{
		again = false;
		if (play)
		{
			cout << "(Press CTRL-Z to get back in your decision)" << endl;
		}
		do
		{
			validInput = true;
			cout << "\tChoose a letter: ";
			getline(cin, str, '\n');
			toUpper(str);
			if (cin.fail())
			{
				cin.clear();
				if (play)
				{
					play = false;										//When the input fails, the program gets back and asks again to the user what to do
					str = " ";
				}
				else
				{
					invalidInput(validInput);							//When the player goes to the pool, it's impossible to get back
					cout << endl;
				}
			}
			else if (str.length() != 1)									//If the input has more than 1 letter, it's an invalid input
			{
				invalidInput(validInput);
				cout << endl;
			}
			else if (!player.isValid(str[0]))
			{
				invalidInput(validInput);
				cout << endl;
			}
		} while (!validInput);
		letter = str[0];
		if (play)														//play = false if the player wants to go to the pool, player = true if the player wants to play a tile
		{
			do
			{
				validInput = true;
				cout << "\tChoose a position: [LineColumn] ";
				getline(cin, str, '\n');
				if (cin.fail())
				{
					cin.clear();
					again = true;
					break;												//To change the letter
				}
				else if (str.length() != 2)								//Position + Collum = 2 letters
				{
					invalidInput(validInput);
					cout << endl;
				}
				else
				{
					if (str[0] < ASCII_A || str[0] > char(ASCII_A + lines))
					{
						invalidInput(validInput);
						cout << endl;
					}
					else if (str[1] < ASCII_a || str[1] > char(ASCII_a + column))
					{
						invalidInput(validInput);
						cout << endl;
					}
					else
					{
						str += letter;
						position = newPair(str[0], str[1]);
						if (board.validMove(position, letter))
						{
							score = board.update(position);
							player.addScore(score);
							str += to_string(score);
							player.tileChoosed(letter);
						}
						else
						{
							invalidInput(validInput);
							cout << endl;
						}
					}
				}
			} while (!validInput);
		}
	} while (again);
	return str;
}



void play()
{
	Board board;
	string str, file;
	Player player;
	Scrabble_Junior game;
	int n, numberTiles = 0, tiles_played, lines, columns;
	bool validInput, ignore_buffer, end_game, verify_hands, validHand, showHand, back, empty_pool, played;
	vector<Player> winners;

	do
	{
		back = false;
		board.showBoard();												//Shows on the screen the default board
		cout << "Do you want to play with the default board or with your board? [default, my board] ";
		do
		{
			validInput = true;
			getline(cin, str, '\n');
			toUpper(str);
			if (cin.fail())												//If the player uses something that makes the input fail, it gets back to the menu
			{
				cin.clear();
				back = true;
			}
			else if (str == "MY BOARD")									//If the player wants to play with another board
			{
				fileName(file);											//Get the name of the file with the board
				board.setBoard(file);									//Build the board
			}
			else if (str == "DEFAULT")
				break;
			else
			{
				validInput = false;
				setColor(ERROR_COLOR);
				cout << "#ERROR# - Invalid input. Please try again. ";
				setColor(TEXT_COLOR);
			}
		} while (!validInput);
		if (back)														//If back == true the program goes to the menu (back to the menu)
		{
			break;
		}



		game.setPool(board);
		clrscr();
		board.showBoard();												//Shows in the screen the board that will be used in the game
		lines = board.getLines();
		columns = board.getColumn();



		cout << "How many players will play this game? ";				//Defines the number of players who will play the game
		do
		{
			validInput = true;
			ignore_buffer = false;
			cin >> n;
			if (cin.fail())
			{
				if (!cin.eof())
				{
					ignore_buffer = true;
				}
				cin.clear();
				invalidInput(validInput);
			}
			else if (cin.peek() != '\n')
			{
				ignore_buffer = true;
				invalidInput(validInput);
			}
			else if (n < MIN_PLAYERS || n > MAX_PLAYERS)
			{
				invalidInput(validInput);
			}
			else
			{
				if (cin.peek() == '\n')
				{
					cin.ignore();										//Used to ignore the '\n' in the buffer
				}
				numberTiles = game.tiles_perPlayer(n);					//Defines the number of tiles per player depending on the chosen board and number of players
			}
			if (ignore_buffer)
			{
				cin.ignore(1000000000, '\n');
			}
			else if (validInput && numberTiles < MINIM_PER_PLAYER)		//If doesn't occured an error during the input phase
			{
				setColor(ERROR_COLOR);
				cout << "Too many players for the number of letters of the board. ";
				validInput = false;
				setColor(TEXT_COLOR);
			}
		} while (!validInput);



		for (int i = 1; i <= n; i++)									//Define the players and distribute the hands
		{
			player.setName(i);
			game.hand(player, numberTiles);
			game.addPlayer(player);
		}
		game.generateOrder();											//Defines the order of playing


		end_game = false;
		do
		{
			clrscr();
			player = game.nextTurn();									//'player' is the player that will play this turn
			game.showScore(player);
			board.showBoard();


			//At the beginning of each turn, some variables are assigned to a fixed value

			empty_pool = game.emptyPool();								//If pool is empty, empty_pool = true
			tiles_played = 0;
			verify_hands = false;										//verify_hands = true if the player went to see the tiles of the other players
			showHand = true;											//showHand = true if it is necessary to show the tiles of the player that will play
			played = false;												//played = true if the player plays some tile

			do
			{
				validHand = game.validHand(player, board);				//validHand = true if the player has some tile to play
				if (validInput)											//The program will decide what output should use
				{
					if (!verify_hands && showHand)						//showHand = false when it is necessary to avoid showing the hand again
					{
						cout << player.getName() << " this is your hand: " << endl;
						cout << "\t\t"; player.showHand();
					}
					if (!verify_hands && validHand)
					{
						cout << "What do you want to do? [Play, Hands] ";
					}
					else if (validHand)
					{
						cout << "What do you want to do? [Play] ";
					}
					else if (empty_pool || played)
					{
						if (!verify_hands)
						{
							cout << "What do you want to do? [Hands, Pass] ";
						}
						else
						{
							cout << "What do you want to do? [Pass] ";
						}
					}
					else
					{
						if (!verify_hands)
						{
							cout << "What do you want to do? [Hands, Pool] ";
						}
						else
						{
							cout << "What do you want to do? [Pool] ";
						}
					}
				}

				else
				{
					validInput = true;									//An error message already has been sent
				}
				getline(cin, str, '\n');
				toUpper(str);
				if (cin.fail())
				{
					cin.clear();
					invalidInput(validInput);
				}
				else if (str == "PLAY")
				{
					setColor(ERROR_COLOR);
					if (!validHand && played)							//If the player hasn't more tiles to play, but had already played 1 tile 
					{
						showHand = false;
						cout << "You have already played 1 tile and there is no more to play... You should pass. " << endl;
					}
					else if (!validHand && !empty_pool)					//Else if the player hasn't any available tile to play, hasn't played yet and the pool isn't empty
					{
						showHand = false;
						cout << "You don't have any tile to play... You should use the pool. " << endl;
					}
					else if (!validHand)								//Else if the player hasn't any available tile to play, hasn't played yet and the pool is empty
					{
						showHand = false;
						cout << "You don't have any tile to play and the pool is empty... You should pass. " << endl;
					}
					else
					{
						str = verifyInput(board, player, true, lines, columns);
						showHand = true;								//It is possible to see his tiles again
						verify_hands = false;							//The player can see the others players' hands again
						if (str != " ")									//If str == " ", the player wants to go back in the decision
						{
							played = true;
							tiles_played++;
							clrscr();
							game.showScore(player);
							board.showBoard();							//Shows in the board, the letter played in another color

							cout << player.getName() << " played " << str[2]
								<< " in the position " << str.substr(0, 2) << '.' << endl;

							cout << "\n\n\tPress any key to continue..." << endl;
							(void)_getch();
						}
						clrscr();
						game.showScore(player);
						board.showBoard();
					}
					setColor(TEXT_COLOR);								//If an error has occurred, put the right color back
				}
				else if (str == "HANDS")
				{
					if (verify_hands)									//The hands of the others players' are already on the screen
					{
						setColor(ERROR_COLOR);
						showHand = false;
						cout << "You already saw the hands in this round..." << endl;
						setColor(TEXT_COLOR);
					}
					else
					{
						showHand = false;
						clrscr();
						game.showScore(player);
						board.showBoard();
						verify_hands = true;
						game.showPlayersHand(player);
					}
				}
				else if (str == "POOL")
				{
					setColor(ERROR_COLOR);
					if (validHand)										//If the player has a tile available to play
					{
						showHand = false;
						cout << "You can play at least 1 tile, so you should do it. " << endl;
					}
					else if (empty_pool)
					{
						showHand = false;
						cout << "The pool is empty and you don't have any tile to play... You should pass. " << endl;
					}
					else if (played)
					{
						showHand = false;
						cout << "You have already played 1 tile and there's no more to play, so you can't go to the pool... " << endl;
					}
					else
					{
						showHand = true;
						for (tiles_played; tiles_played < TILES_PER_TURN; tiles_played++)	//The player changes 2 tiles with the pool
						{
							str = verifyInput(board, player, false, lines, columns);
							game.changeTile(player, str[0]);
							cout << " Tile Changed... " << endl;
						}
						cout << endl << TILES_PER_TURN << " tiles have been changed." << endl;
						cout << endl << "Press any key to continue..."; (void)_getch();
					}
					setColor(TEXT_COLOR);									//If an error has occurred, put the right color back
				}
				else  if (str == "PASS")
				{
					setColor(ERROR_COLOR);
					if (validHand)
					{
						cout << "You can play at least 1 tile, so you should do it. " << endl;
					}
					else if (!empty_pool && !played)
					{
						cout << "The pool is not empty... You should use it. " << endl;
					}
					else
					{
						setColor(TEXT_COLOR);
						clrscr();
						game.showScore(player);
						board.showBoard();
						cout << player.getName() << " passed the turn. " << endl;
						cout << "\n\n\tPress any key to continue..." << endl;
						(void)_getch();
						break;
					}
					setColor(TEXT_COLOR);									//If an error has occurred, put the right color back
				}
				else
				{
					invalidInput(validInput);
				}
				end_game = board.endGame();									//end_game = true if the game is over
			} while (tiles_played != TILES_PER_TURN && !end_game);
			if (played)														//If any tile has been played in this turn, it will be replaced if possible
			{
				while (!game.emptyPool() && (tiles_played != 0))			//While is possible to use the pool to replace the tiles played
				{															//Or the number of tiles replaced is equal to the number of tiles played
					game.refreshHand(player);
					tiles_played--;
				}
			}
			game.updatePlayer(player);										//Update the data of the list of players in the class game after each turn
		} while (!end_game);
		clrscr();
		game.showScore(player);
		board.showBoard();
		winners = game.endGame();											//winners has the players with the highest scores in the end of the game
		if (winners.size() != 1)											//If there is more than 1 winner
		{
			cout << "The following players: " << endl;
			for (size_t i = 0; i < winners.size(); i++)
			{
				cout << '\t' << winners[i].getName() << endl;
			}
			cout << "finished the game with the same score... So it is a DRAW!!!" << endl;
		}
		else
		{
			player = winners[0];
			cout << player.getName() << " wins with " << player.getScore() << " points!!!" << endl;
		}
		cout << "\n\nPress any key to continue..."; (void)_getch();
		cout << " Do you want to play again? [Y/N] ";
		do
		{
			validInput = true;
			getline(cin, str, '\n');
			toUpper(str);
			if (str == "Y")													//If the player wants to play again, the game restarts
			{
				player.resetPlayer();										//The variables player and board will be used again in the new game
				game.reset(board);
				back = false;
			}
			else if (str == "N")											//Else the game ends and returns to the menu
			{
				back = true;
			}
			else
			{
				if (cin.fail())
				{
					cin.clear();
				}
				invalidInput(validInput);
			}
		} while (!validInput);
		clrscr();
	} while (!back);
}



void rules()
{
	setColor(MENUCOLOR);
	cout << endl
		<< endl
		<< "=============================================================| RULES |=============================================================" << endl;
	setColor(TEXT_COLOR);
	cout << endl
		<< endl
		<< " In this menu, will be explained the game rules.\n" << endl
		<< " HOW TO PLAY: " << endl
		<< "   -Playing your tiles: on your turn play two of your tiles by covering letters on the gameboard squares with matching tiles." << endl
		<< "	  Then draw as many tiles from the pool as you played, so that you have the same tiles that you have in the beginning of the turn." << endl
		<< " Play your tiles as explained below:" << endl
		<< "   -First Turn: If you're the first player, play any two of your tiles as follows:" << endl
		<< "	 -EITHER on the first letter of two different words" << endl
		<< "	 -OR on the first and second letters of the same word." << endl
		<< "   -All Other Turns: Each player in turn now plays any two of his or her tiles. Play each tile as follows:" << endl
		<< "	 -EITHER on an open first letter of any word;" << endl
		<< "	 -OR on the next open letter of any word already started." << endl
		<< " If you can play, you must play!" <<endl
		<< "	 -Always play two tiles if you can." << endl
		<< "	 -If you can play only one tile, draw one tile from the pool afterwards." << endl
		<< "	 -If you can't play any tiles, you must use your turn to exchange any two of your tiles with two tiles from the pool." << endl
		<< "	 -If there are no tiles left in the pool, you must pass." << endl
		<< " Play letters in order! Always cover the letters of a word in correct spelling order. Because some words share letters, you may sometimes " << endl
		<< "  have to \"back up\" to cover letters in order." << endl
		<< " Collecting Scoring Chips:" << endl
		<< "	 -Try to complete a word by covering the last letter." << endl
		<< "	 -For each word you complete, take one scoring chip from the kitty. If you complete two words with one tile, collect two scoring chips." << endl
		<< " Note: Because some words share letters, the tile that completes a word may not be covering the last letter of the word." << endl
		<< " Blocking: " << endl
		<< "   -It's good strategy to check other players' tiles to see if a tile you're playing would let an opponent complete a word." << endl
		<< "   -As long as you play two tiles on your turn, you can hold back a certain tile to block an opponent from completing a word!" << endl
		<< " Ending the Game: " << endl
		<< "   -When there are no more tiles left in the pool, keep playing with the tiles you have until all 101 tiles have been placed on the board.This ends the game." << endl
		<< " End of the Game: " << endl
		<< "   -After the game ends, the player with the most scoring chips is the winner!" << endl
		<< endl
		<< endl
		<< endl
		<< " SOURCE: \"https://www.ultraboardgames.com/scrabble/junior-game-rules.php\"." << endl
		<< "\n(Press any key to continue...)" << endl; (void)_getch(); //Leave this menu only when the user presses a key
	clrscr();
}



void menu()			//The function that shows the menu on the screen and decides what to do depending on the input of the user
{
	bool validMenuInput, loop = true;
	string menu;
	do
	{
		cout << "\t\t\t\t\t------------------Welcome to my game------------------\t\t\t\t" << endl;
		setColor(MENUCOLOR);
		cout << '\n' << endl;
		cout << "\t\t\t\t\t __        __     _______    __        _   _        _ \t\t\t\t" << endl;
		cout << "\t\t\t\t\t|   \\    /   |   | ______|  |   \\     | | | |      | |\t\t\t\t" << endl;
		cout << "\t\t\t\t\t| |\\ \\  / /| |   | |        | |\\ \\    | | | |      | |\t\t\t\t" << endl;
		cout << "\t\t\t\t\t| | \\ \\/ / | |   | |___     | | \\ \\   | | | |      | |\t\t\t\t" << endl;
		cout << "\t\t\t\t\t| |  \\  /  | |   | ____|    | |  \\ \\  | | | |      | |\t\t\t\t" << endl;
		cout << "\t\t\t\t\t| |   \\/   | |   | |        | |   \\ \\ | | | |      | |\t\t\t\t" << endl;
		cout << "\t\t\t\t\t| |        | |   | |_____   | |    \\ \\| | | |______| |\t\t\t\t" << endl;
		cout << "\t\t\t\t\t|_|        |_|   |_______|  |_|     \\___| |__________|\t\t\t\t" << endl;
		cout << "\n\n";
		setColor(MENU_BOXES_COLOR);
		cout << "\t\t\t\t\t\t     ____________________________" << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; setColor(MENU_TEXT_COLOR); cout << "            PLAY"; setColor(MENU_BOXES_COLOR); cout << "            | " << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\t\t\t\t\t\t     ____________________________ " << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; setColor(MENU_TEXT_COLOR); cout << "            RULES"; setColor(MENU_BOXES_COLOR); cout << "           |" << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\t\t\t\t\t\t     ____________________________ " << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; setColor(MENU_TEXT_COLOR); cout << "            QUIT"; setColor(MENU_BOXES_COLOR); cout << "            |" << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\n\n" << endl; setColor(TEXT_COLOR);
		cout << " What do you want to do? ";
		do
		{
			validMenuInput = true;
			getline(cin, menu, '\n');
			toUpper(menu);						//Easiest comparation
			if (cin.fail())
			{
				cin.clear();
				validMenuInput = false;
			}
			else if (menu == "QUIT")			 //End program
			{
				loop = false;
			}
			else if (menu == "RULES")
			{
				clrscr();
				rules();						//Rules menu
			}
			else if (menu == "PLAY")
			{
				clrscr();
				play();							//Play the game
			}
			else
			{
				validMenuInput = false;
			}
			if (!validMenuInput)
			{
				setColor(ERROR_COLOR);
				cout << "I think you didn't want to write that. Please try again: ";
				setColor(TEXT_COLOR);
			}
		} while (!validMenuInput);
		if (loop)
			clrscr();
	} while (loop);
}



int main()
{
	srand((unsigned int)time(NULL));
	menu();
	return 0;
}