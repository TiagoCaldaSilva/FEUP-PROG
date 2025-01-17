#define STD_OUTPUT_HANDLE ((DWORD)-11)
#include <iostream>
#include <iomanip>
#include <string>		//para utilizar strings
#include <cstddef>		//toupper()
#include <windows.h>	//alterar a cor
#include <vector>
#include <time.h>		//usado para o cronómetro do jogo
#include <conio.h>		//_getch()


using namespace std;


typedef struct
{
	string name;
	vector <int> vec;
	int score;
}Info;

typedef struct
{
	string name;
	int nc;
}Colour;


void INICIO();
void Colour1();
void Commands();
void Options();
void Multiplayer();
void Game_Board(Info *player1, Info *player2, int round);
void Bot();
void update_vector(Info *player1, Info *player2, int otherside, int jogada, bool more, int score, bool player_1, int round);
void score_number(int& seeds, Info *player1, Info *player2, bool& valid, bool& more, int& score);
void update_score(int n, int ind, vector<int>& vec, Info* player1);
bool valid_move(bool player_1, int jogada, Info* player1, Info* player2, int round);
void music();
void name(Info* player, int n);
bool pause_game();
bool End_game(Info* player1, Info* player2, bool player_1);
bool play_again(Info* player1, Info* player2, int time);
int jogadas_do_bot(Info* player1, Info* player2, bool easy);
void Bot_(bool easy);

//vector SC has the strings to draw the score board
vector<vector<string>> SC = { {"  _______  ", " |  ___  | ", " | |   | | ", " | |   | | ", " | |   | | ", " | |   | | ", " | |___| | ", " |_______| "}, {"       __  ", "      |  | ", "      |  | ", "      |  | ", "      |  | ", "      |  | ", "      |  | ", "      |__| "}, {"  _______  ", " |_____  | ", "       | | ", "  _____| | ", " |  _____| ", " | |       ", " | |_____  ", " |_______| "}, {"  _______  ", " |_____  | ", "       | | ", "   ____| | ", "  |____  | ", "       | | ", "  _____| | ", " |_______| "}, {"  _     _  ", " | |   | | ", " | |   | | ", " | |___| | ", " |_____  | ", "       | | ", "       | | ", "       |_| "},{"  _______  ", " |  _____| ", " | |       ", " | |_____  ", " |_____  | ", "       | | ", "  _____| | ", " |_______| "}, {"  _______  ", " |  _____| ", " | |       ", " | |_____  ", " |   __  | ", " |  |  | | ", " |  |__| | ", " |_______| "}, {"  _______  ", " |____   | ", "      |  | ", "      |  | ", "      |  | ", "      |  | ", "      |  | ", "      |__| "}, {"  _______  ", " |  ___  | ", " | |   | | ", " | |___| | ", " | |___| | ", " | |   | | ", " | |___| | ", " |_______| "}, {"  _______  ", " |  ___  | ", " | |   | | ", " | |___| | ", " |_____  | ", "       | | ", "       | | ", "       |_| "} };
vector<Colour> VC = { {"NCM", 4}, {"NCMB", 4}, {"NCTM", 14}, {"GB", 3}, {"P1", 6}, {"P2", 10}, {"SB", 4}, {"LT", 15 } };
const vector<Colour> Vc_default = { {"NCM", 4}, {"NCMB", 4}, {"NCTM", 14}, {"GB", 3}, {"P1", 6}, {"P2", 10}, {"SB", 4}, {"LT", 15} };


void ToUpper(string& s) //uppercase strings
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
}


void SetColor(int value) //Different colours
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, value);
	/*
	0   BLACK
	1   BLUE
	2   GREEN
	3   CYAN
	4   RED
	5   MAGENTA
	6   BROWN
	7   LIGHTGRAY
	8   DARKGRAY
	9   LIGHTBLUE
	10  LIGHTGREEN
	11  LIGHTCYAN
	12  LIGHTRED
	13  LIGHTMAGENTA
	14  YELLOW
	15  WHITE
	*/
}


void clrscr(void)	//clear screen
{
	COORD coordScreen = { 0, 0 }; // upper left corner
	DWORD cCharsWritten;
	DWORD dwConSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hCon, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// fill with spaces
	FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hCon, &csbi);
	FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	// cursor to upper left corner
	SetConsoleCursorPosition(hCon, coordScreen);
}


void Colour1() //change colour of the program
{
	bool InvalidColour_Input = false, kp, vp, change, again = false, leave = false, needtoignore;
	string color_input;
	int number, player;
	do
	{
		SetColor(VC[0].nc);
		cout << '\n' << endl;
		cout << "\t\t\t\t\t _____   _____   _       _____   _    _   _____ \t\t\t" << endl;
		cout << "\t\t\t\t\t|  ___| |  _  | | |     |  _  | | |  | | |  _  |\t\t\t" << endl;
		cout << "\t\t\t\t\t| |     | | | | | |     | | | | | |  | | | |_| |\t\t\t" << endl;
		cout << "\t\t\t\t\t| |     | | | | | |     | | | | | |  | | |    _|\t\t\t" << endl;
		cout << "\t\t\t\t\t| |___  | |_| | | |___  | |_| | | |__| | | |\\ \\\t\t\t" << endl;
		cout << "\t\t\t\t\t|_____| |_____| |_____| |_____| |______| |_| \\_\\\t\t\t" << endl;
		cout << "\n\n";
		SetColor(VC[7].nc);
		cout << " Welcome to the color menu:" << endl; SetColor(VC[1].nc);
		cout << "\t\t\t --------------------------------------------------------------------------------------\t\t" << endl;
		cout << "\t\t\t|  "; SetColor(VC[7].nc); cout << "BLUE  "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << " GREEN  "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << " CYAN  "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << " RED  "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << " MAGENTA "; SetColor(VC[1].nc); cout << " | "; SetColor(VC[7].nc); cout << " YELLOW  "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << " LIGHTGRAY  "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << " DARK GRAY "; SetColor(VC[1].nc); cout << " | \t" << endl;
		cout << "\t\t\t|  "; SetColor(VC[7].nc); cout << " 1    "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << "   2    "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << "  3    "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << "  4   "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << "    5    "; SetColor(VC[1].nc); cout << " | "; SetColor(VC[7].nc); cout << "   6     "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << "     7      "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << "     8     "; SetColor(VC[1].nc); cout << " | \t" << endl;
		cout << "\t\t\t|--------------------------------------------------------------------------------------|\t" << endl;
		cout << "\t\t\t| "; SetColor(VC[7].nc); cout << "L.BLUE "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << "L.GREEN "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << "L.CYAN "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << "L.RED "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << " PURPLE   "; SetColor(VC[1].nc); cout << "|"; SetColor(VC[7].nc); cout << " L.YELLOW "; SetColor(VC[1].nc); cout << "|    "; SetColor(VC[7].nc); cout << "WHITE    "; SetColor(VC[1].nc); cout << "|   "; SetColor(VC[7].nc); cout << "DEFAULT   "; SetColor(VC[1].nc); cout << "| \t" << endl;
		cout << "\t\t\t| "; SetColor(VC[7].nc); cout << "  9    "; SetColor(VC[1].nc); cout << "| "; SetColor(VC[7].nc); cout << "   10   "; SetColor(VC[1].nc); cout << "|   "; SetColor(VC[7].nc); cout << "11   "; SetColor(VC[1].nc); cout << "|   "; SetColor(VC[7].nc); cout << "12  "; SetColor(VC[1].nc); cout << "|    "; SetColor(VC[7].nc); cout << "13     "; SetColor(VC[1].nc); cout << "|   "; SetColor(VC[7].nc); cout << " 14    "; SetColor(VC[1].nc); cout << "|      "; SetColor(VC[7].nc); cout << "15     "; SetColor(VC[1].nc); cout << "|     "; SetColor(VC[7].nc); cout << "16      "; SetColor(VC[1].nc); cout << "| \t" << endl;
		cout << "\t\t\t -------------------------------------------------------------------------------------- \t\t" << endl;
		cout << '\n' << endl;
		SetColor(VC[7].nc);
		cout << " In this table, you have all the colours that you can use in this game." << endl;
		cout << " If you want to go back to the options menu, write -> BACK. " << endl;
		cout << " You can change: " << endl;
		cout << "\t-Colour of the Menu letters (NCM); " << endl << "\t-Colour of the Menu boxes (NCMB); " << endl << "\t-Colour of the letters that are inside of the boxes (NCTM); " << endl << "\t-Colour of the game board (GB); " << endl << "\t-Color of the players (P1/P2). " << endl << "\t-Color of the ScoreBoard (SB);" << endl << "\t-Color of the text (LT)" << endl;
		do
		{
			needtoignore = false;
			again = false;
			kp = false; //kp ("keep going")	false if invalid input
			if (!InvalidColour_Input) //avoid 2 messages to ask for the input
				cout << " What do you want to change? [NCM, NCMB, NCTM, GB, P1, P2, SB, LT] ";
			else //not necessary to ask for the input because that message is already sent
				InvalidColour_Input = false;
			getline(cin, color_input, '\n');
			ToUpper(color_input);
			if (color_input == "BACK") //back to menu
			{
				leave = true;
				break;
			}
			for (int i = 0; i < size(VC); i++) //to classify the input as valid or invalid
			{
				if (color_input == VC[i].name)
				{
					kp = true;
					break;
				}
			}
			if (kp) //if was valid
			{


				cout << " Good choice. And what is the number of the color that you choose? "; cin >> number;

				if (cin.fail()) //classify the input as valid or invalid
				{
					cin.clear();
					needtoignore = true;
					kp = false;
				}
				else if (1 > number || number > 16)
				{
					kp = false;
				}
				if (cin.peek() != '\n') //to verify if the buffer is "clean"
				{
					needtoignore = true;
					kp = false;
				}
				cin.ignore(); //clear the '\n' in the buffer because later will be used getline
				if (kp) //valid input
				{
					for (int i = 0; i < VC.size(); i++)
					{
						if (color_input == VC[i].name) //modify the value of the color that the user chose
						{
							if (i == 0 || i == 1 || i == 7) //verify if the choice will change anything in the menu
								again = true;
							if (number == 16)
								VC[i].nc = Vc_default[i].nc;
							else
								VC[i].nc = number;
						}
					}
				}
			}
			if (!kp)//invalid input
			{
				if (needtoignore) //clear the buffer if necessary
				{
					cin.ignore(1000000, '\n');
				}
				cout << " Uuupsss. Invalid input, I think you should try again. ";
				InvalidColour_Input = true; //avoid sending 2 messages asking for input
			}
		} while (!again); //while the change isn't in this menu or input != back
		clrscr();
	} while (!leave);
}


void Commands()
{
	SetColor(VC[0].nc);
	cout << '\n';
	cout << "\t\t\t\t\t ____   _____   ___    ___   ___    ___   _____   ___     _   __      ____ \t" << endl;
	cout << "\t\t\t\t\t|  __| |  _  | |   \\  /   | |   \\  /   | |  _  | |   \\   | | |   \\   |  __|\t" << endl;
	cout << "\t\t\t\t\t| |    | | | | | |\\ \\/ /| | | |\\ \\/ /| | | |_| | | |\\ \\  | | | |\\ \\  | |__ \t" << endl;
	cout << "\t\t\t\t\t| |    | | | | | | \\__/ | | | | \\__/ | | |  _  | | | \\ \\ | | | | | | |__  |\t" << endl;
	cout << "\t\t\t\t\t| |__  | |_| | | |      | | | |      | | | | | | | |  \\ \\| | | |/ /   __| |\t" << endl;
	cout << "\t\t\t\t\t|____| |_____| |_|      |_| |_|      |_| |_| |_| |_|   \\___| |___/   |____|\t" << endl;
	cout << "\n\n";
	SetColor(VC[7].nc);
	cout << " In this menu, will be explained the game rules.\n" << endl;
	cout << " - Oware is a strategy game for two players. It belongs to the wider family of mancala games, also known as count-and-capture games due to the peculiarity" << endl;
	cout << "    of their gameplay, consisting in the distribution of game pieces around the board and its removal from the board when certain conditions are met." << endl;
	cout << " - To play oware abapa you will need a game board and forty-eight game pieces, which are so-called seeds.  Usually the board consists of two rows of six holes located" << endl;
	cout << "    at opposite sides. Two larger holes on the sides of the board are used to store the seeds players capture during the match. " << endl;
	cout << " - In the starting position, each hole contains exactly the same number of seeds. In this position the north player will make his first move, followed by a move of" << endl;
	cout << "    the south player and so on until the game ends." << endl;
	cout << " - The goal of oware is to capture the greatest amount of seeds as possible. To do so, players make moves in alternate turns until one of them has captured more" << endl;
	cout << "    than 24 seeds. The player who captured more seeds than his opponent when the game ends wins the match. It may also happen that both players have captured the" << endl;
	cout << "    same amount of seeds at the end. In this case, neither player wins the game and the match is said to have ended in a draw." << endl;
	cout << " - Each move of the game is done in three phases: collecting, sowing and capturing. During the sowing a player distributes the collected seeds along the board, and" << endl;
	cout << "    during the capture phase the player takes, if possible, the seeds found in the pits of the opponent.\n" << endl;
	cout << " - Collecting Seeds:" << endl;
	cout << "    -In the first phase of a movement, the player chooses one of the holes on his own side of the board and collects all the seeds on it, leaving the hole empty." << endl;
	cout << "      Subsequently, these seeds will be distributed on the board during the sowing phase." << endl;
	cout << "    -A player may collect the seeds from any of the holes that belong to him if it contains one or more seeds, only with the exception that after making the move his" << endl;
	cout << "      opponent must be able to play. Therefore, a move that would leave all the holes empty on the opponent's side is not legal.\n" << endl;
	cout << " - Sowing Seeds:" << endl;
	cout << "    -During sowing, the player distributes the seeds collected in the first phase along the board in a counterclockwise direction; dropping one seed in each of the" << endl;
	cout << "      playing holes until all the seeds are distributed." << endl;
	cout << "    -After sowing the seeds, the hole from which the player has collected seeds will be empty. It may well be the case that the player sows twelve or more seeds, in which case" << endl;
	cout << "      the player will sow them going round around the board, dropping one seed in each hole in every round, but never dropping a seed in the hole from which the seeds were collected.\n" << endl;
	cout << " - Capturing Seeds:" << endl;
	cout << "    -When the last sown seed is dropped in one of the holes belonging to the opponent, and after dropping the seed, if the hole contains exactly two or three seeds, the player will" << endl;
	cout << "      capture them, taking all the seeds from the hole and saving them in his own store." << endl;
	cout << "    -When the hole immediately to the right of the last pit from which seeds were captured contains also two or three seeds, the player will capture them too. And so on until the" << endl;
	cout << "      player cannot capture more seeds, always taking into account that players can only capture seeds from their opponents holes and never from their own holes." << endl;
	cout << "    -Note that a player can never capture all the seeds of the adversary. If a player makes a move that would capture all the seeds on the opponent's side, that player will sow " << endl;
	cout << "      normally but will not capture any seeds.\n" << endl;
	cout << "================================================================================================================================================================================================\n" << endl;
	cout << " - End of the Game:" << endl;
	cout << "    -Typically, the game is over when one of the players has captured more than 24 seeds or when both of the players have captured 24 seeds.It may also happen that a player cannot" << endl;
	cout << "      make any legal move on his turn, in such a case, each player captures the remaining seeds on their side of the boardand the match ends." << endl;
	cout << "    -A special situation is when the game enters a cycle, so that the same positions and movements would repeat indefinitely. If this happens, players may agree to end the game and" << endl;
	cout << "      each player will capture the remaining seeds on their side of the board." << endl;
	cout << "    -If 50 or 80 rounds have been played, it is suggested to end the game. However when 100 rounds have been played, the game automatically ends." << endl;
	cout << "\n\n\n  SOURCE: http://www.joansala.com/auale/rules/en/" << endl;
	SetColor(8); cout << "\n(Press any key to continue...)" << endl; _getch(); //leave this menu only when the user press a key
	clrscr();
}


void Options()
{
	bool ValidOptionsInput, Loop = true;
	string options;
	do
	{
		SetColor(VC[0].nc);
		cout << '\n' << endl;
		cout << "\t\t\t\t\t _____   _____   _______   _   _____   ___     _   _____ \t\t\t" << endl;
		cout << "\t\t\t\t\t|  _  | |  _  | |__   __| | | |  _  | |   \\   | | |   __|\t\t\t" << endl;
		cout << "\t\t\t\t\t| | | | | |_| |    | |    | | | | | | | |\\ \\  | | |  |__ \t\t\t" << endl;
		cout << "\t\t\t\t\t| | | | |  ___|    | |    | | | | | | | | \\ \\ | | |__   |\t\t\t" << endl;
		cout << "\t\t\t\t\t| |_| | | |        | |    | | | |_| | | |  \\ \\| |  __|  |\t\t\t" << endl;
		cout << "\t\t\t\t\t|_____| |_|        |_|    |_| |_____| |_|   \\___| |_____|\t\t\t" << endl;
		cout << "\n\n";
		SetColor(VC[1].nc);
		cout << "\t\t\t\t\t\t     ____________________________" << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; SetColor(VC[2].nc); cout << "           COLOUR"; SetColor(VC[1].nc); cout << "           | " << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\t\t\t\t\t\t     ____________________________ " << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; SetColor(VC[2].nc); cout << "          COMMANDS"; SetColor(VC[1].nc); cout << "          |" << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\t\t\t\t\t\t     ____________________________ " << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; SetColor(VC[2].nc); cout << "            BACK"; SetColor(VC[1].nc); cout << "            |" << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\n\n" << endl; SetColor(VC[7].nc);
		cout << " What do you want to do? ";
		do
		{
			ValidOptionsInput = true;
			getline(cin, options, '\n');
			ToUpper(options);
			if (cin.fail()) //invalid input
			{
				cout << " Uuupsss. Invalid input, I think you should try again. ";
				cin.clear();
			}
			else if (options == "BACK") //return to main menu
			{
				Loop = false;
				ValidOptionsInput = false;
			}
			else if (options == "COLOUR")
			{
				ValidOptionsInput = false;
				clrscr();
				Colour1(); //colour menu
			}
			else if (options == "COMMANDS")
			{
				ValidOptionsInput = false;
				clrscr();
				Commands(); //commands menu
			}
			else //invalid input
				cout << " Uuupsss. Invalid input, I think you should try again. ";
		} while (ValidOptionsInput);
		clrscr();
	} while (Loop);
}


void INICIO()
{
	bool ValidMenuInput, Loop = true;
	int result;
	string menu;
	do
	{
		cout << "\t\t\t\t\t------------------Welcome to my game------------------\t\t\t\t" << endl;
		SetColor(VC[0].nc);
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
		SetColor(VC[1].nc);
		cout << "\t\t\t\t\t\t     ____________________________" << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; SetColor(VC[2].nc); cout << "           1 vs 1"; SetColor(VC[1].nc); cout << "           | " << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\t\t\t\t\t\t     ____________________________ " << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; SetColor(VC[2].nc); cout << "           vs BOT"; SetColor(VC[1].nc); cout << "           |" << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\t\t\t\t\t\t     ____________________________ " << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; SetColor(VC[2].nc); cout << "           OPTIONS"; SetColor(VC[1].nc); cout << "          |" << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\t\t\t\t\t\t     ____________________________ " << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; SetColor(VC[2].nc); cout << "            QUIT"; SetColor(VC[1].nc); cout << "            |" << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\n\n" << endl; SetColor(VC[7].nc);
		cout << " What do you want to do? ";
		do
		{
			ValidMenuInput = true;
			getline(cin, menu, '\n');
			ToUpper(menu); //easiest comparation
			if (cin.fail())
			{
				cout << " Uuupsss. Invalid input, I think you should try again. ";
				cin.clear();
			}
			else if (menu == "QUIT") //end program
			{
				ValidMenuInput = false;
				Loop = false;
			}
			else if (menu == "OPTIONS")
			{
				clrscr();
				ValidMenuInput = false;
				Options(); //options menu
			}
			else if (menu == "1 VS 1")
			{
				clrscr();
				ValidMenuInput = false;
				Multiplayer(); //1 vs 1 mode
			}
			else if (menu == "VS BOT")
			{
				clrscr();
				ValidMenuInput = false;
				Bot(); //player vs computer mode
			}
			else
			{
				cout << " Uuupsss. Invalid input, I think you should try again. ";
			}
		} while (ValidMenuInput);
		if (Loop)
			clrscr();
	} while (Loop);
}


void update_score(int n, int ind, vector<int>& vec, Info *player1)
{
	for (int i = 0; i < n; i++) //knowing how many holes are going to be "eaten"
	{
		(*player1).score += vec[ind - i]; //update variable score with the number of beans on it
		vec[ind - i] = 0; //turn the bean number of the hole to 0
	}
}


void Game_Board(Info *player1, Info *player2, int round)
{
	int x1, x2, y1, y2;
	x1 = (*player1).score / 10; //second digit of the player 1 score
	x2 = (*player1).score % 10; //first digit of the player 1 score
	y1 = (*player2).score / 10; //second digit of the player 2 score
	y2 = (*player2).score % 10; //first digit of the player 2 score
	if (round % 2) //1 round = player 1 move + player 2 move
		round++; //if round is an odd number, the round isn't terminated yet, so the number should be the next iven number to represent the round as a whole
	cout << '\n' << endl;
	SetColor(VC[6].nc);
	cout << "\t\t\t\t ________________________________________________________" << endl;
	SetColor(8); cout << "\tP = Pause"; SetColor(VC[6].nc);
	cout << "\t\t|                                                        |" << endl;
	for (int i = 0; i < 8; i++) //print the score board depending on the digits of the score
	{
		cout << "\t\t\t\t| "; SetColor(15); cout << SC[x1][i] << SC[x2][i]; //SC vector has the number n in the n position divided by lines
		if (i == 3)
			cout << "  _____  ";
		else if (i == 4)
			cout << " |_____| ";
		else
			cout << "         ";
		cout << SC[y1][i] << SC[y2][i]; SetColor(VC[6].nc); cout << "  |" << endl;
	}
	/*
		Vector VC has the number of the color that should be used to print something
		player#.vec is the vector that save the number and the postion of beans by user
		the order is: player1 : 5-4-3-2-1-0, player2 : 0-1-2-3-4-5
	*/
	cout << "\t\t\t\t|                                                        |" << endl;
	cout << "\t\t\t\t|________________________________________________________|\n" << endl;
	cout << "\n\n\n";
	SetColor(VC[4].nc); cout << "\t\t\t      A           B           C           D           E           F       " << endl;
	SetColor(VC[3].nc);
	cout << "\t\t\t ________________________________________________________________________ " << endl;
	cout << "\t\t\t|  ________    ________    ________    ________    ________    ________  |" << endl;
	cout << "\t\t\t| |        |  |        |  |        |  |        |  |        |  |        | |" << endl;
	cout << "\t\t\t| |        |__|        |__|        |__|        |__|        |__|        | |" << endl;
	for (int i = 6; i >= 0; i--) //Draw the top of the board
	{
		SetColor(VC[4].nc);
		if (i == 6)
		{
			cout << setfill(' ') << setw(21) << (*player1).name << setfill('0');
			SetColor(VC[3].nc); cout << "   | |   ";
		}
		else if (i == 0)
		{
			cout << setw(2) << (*player1).vec[i];
			SetColor(VC[3].nc);
			cout << "   | |" << endl;
		}
		else
		{
			cout << setw(2) << (*player1).vec[i];
			SetColor(VC[3].nc);
			cout << "    __    ";
		}
	}
	cout << "\t\t\t| |        |  |        |  |        |  |        |  |        |  |        | |" << endl;
	cout << "\t\t\t| |__    __|  |________|  |________|  |________|  |________|  |__    __| |" << endl;
	cout << "\t\t\t|    |  |                                                        |  |    |" << endl;
	cout << "\t\t\t|    |  |                        Round:" << setfill('0') << setw(2) << round / 2 <<  "                        |  |    |" << endl;
	cout << "\t\t\t|  __|  |__    ________    ________    ________    ________    __|  |__  |" << endl;
	cout << "\t\t\t| |        |  |        |  |        |  |        |  |        |  |        | |" << endl;
	cout << "\t\t\t| |        |__|        |__|        |__|        |__|        |__|        | |" << endl;
	for (int i = -1; i < 6; i++) //Draw the bottom of the board
	{
		SetColor(VC[5].nc);
		if (i == -1)
		{
			cout << setfill(' ') << setw(21) << (*player2).name << setfill('0');
			SetColor(VC[3].nc); cout << "   | |   ";
		}
		else if (i == 5)
		{
			cout << setw(2) << (*player2).vec[i];
			SetColor(VC[3].nc);
			cout << "   | |" << endl;
		}
		else
		{
			cout << setw(2) << (*player2).vec[i];
			SetColor(VC[3].nc);
			cout << "    __    ";
		}
	}
	cout << "\t\t\t| |        |  |        |  |        |  |        |  |        |  |        | |" << endl;
	cout << "\t\t\t| |________|  |________|  |________|  |________|  |________|  |________| |" << endl;
	cout << "\t\t\t|________________________________________________________________________|\n" << endl;
	SetColor(VC[5].nc); cout << "\t\t\t      a           b           c           d           e           f       \n\n" << endl;
	SetColor(VC[7].nc);
}


bool valid_move(bool player_1, int jogada, Info *player1, Info *player2, int round) //function used to classify the move as valid or invalid
{
	int seeds, otherside, score = 0, ind = 0, k = 0;
	bool valid = false, more = false, start = false, clz = true;
	seeds = (*player1).vec[jogada];
	if (seeds != 0) //if the position has some beans on it, start = true
		start = true; //this variable will be used next to see if the number of beans was non-zero in the beggining of the move
	otherside = 5 - jogada; //number of places that separate the chosen position from the other side of the board
	for (int i = 0; i <= 5; i++)
	{
		if ((*player2).vec[i] != 0) //verify if the other player has some hole with beans
		{
			clz = false; //if clz is false, player1 can play in a not restricted way
			break;
		}
	}
	if (clz && seeds <= otherside) //if there isn't any hole with beans in the other side of the board and the number of seeds of the chosen position isn't enough to change that
	{
		return true; //the move is invalid
	}
	else
	{
		for (int i = 1; (i <= otherside && seeds > 0); i++, seeds--) {} //remove the required number of beans to go to the other side of the board, if seeds < otherside, remove all the seeds from the counter
		if (seeds == 0) //if the move doesn't reach the other side
		{
			if (start == true)//and if the inicial number of the seeds is non-zero
				valid = true; //will be returned !valid, so the move is valid
		}
		else if ((seeds % 11) > 6 || (seeds % 11) == 0) //if the number of seeds is enough to return to the inicial side of the board
		{
			valid = true;	//move is valid
			more = true;	//will be used next; to sinalize that the move has beans to return to the inicial side of the board
		}
		else //if the final position is in the other side of the board
		{
			score_number(seeds, player1, player2, valid, more, score); //function that "return" how many holes will be "eaten"
		}
	}
	if (valid) //if the move is valid, the function below will update the values of the vector depending on the chosen move
		update_vector(player1, player2, otherside, jogada, more, score, player_1, round);
	return !valid;
}


void score_number(int& seeds, Info *player1, Info *player2, bool& valid, bool& more, int &score)
{
	int ind, k = 0;
	ind = (seeds % 11) - 1; //index of the final postion after distributing all beans for the holes
	for (int i = ind; i >= 0; i--)
	{
		if (((*player2).vec[i] + (seeds / 11)) != 1 && ((*player2).vec[i] + (seeds / 11)) != 2) //if the final number of beans != 2 or != 1, the hole isn't "eaten" and stops the sequence
		{
			valid = true;
			break;
		}
		score += 1; //counter that saves the number of holes "eaten"
	}
	if (score != 6) //if it appears to not be a grand slam
	{
		for (int i = 0; i < (6 - score); i++) //verify all the holes that wont be "eaten"
		{
			if (k > ind || k <= (ind - score)) //if the index of the hole is bigger than the last hole of the move or this isn't caught by the "hunting" sequence
			{
				if ((*player2).vec[k] != 0)
					valid = true;
			}
			else
				i--; //if k is an index of an "eaten" hole, it doesn't count to the counter
			k++; //this is the index of the vector (0-5)
		}
		if (!valid)//if all non-zero holes are "eaten", score = 0 and the move is valid
		{
			valid = true;
			score = 0;
		}
	}
	else //if it is a grand slam, the move is valid but the score = 0
	{
		score = 0;
		valid = true;
	}
}


void update_vector(Info *player1, Info *player2, int otherside, int jogada, bool more, int score, bool player_1, int round)
{
	int seeds = (*player1).vec[jogada];
	for (int i = 1; (i <= otherside && seeds > 0); i++)
	{
		(*player1).vec[jogada + i] += 1; //update the player1 board side
		seeds--; //remove 1 bean for each hole that has been updated
	}
	int ind = (seeds % 11) - 1; //ind is the index of the final position
	(*player1).vec[jogada] = 0; //the hole of the chosen move must be turned to 0
	while (seeds != 0)
	{
		for (int i = 0; (i < 6 && seeds != 0); i++)
		{
			(*player2).vec[i] += 1; //update the other side of the board
			seeds--; //remove 1 bean for each hole that as been updated
		}
		if (more || seeds > 0) //if there are a number of beans that the move returns to the player side
		{
			for (int i = 0; i < 6 && seeds != 0; i++)
			{
				if (i != jogada) //the chosen position must be 0
				{
					(*player1).vec[i] += 1; //update the holes behind the chosen postion
					seeds -= 1;
				}
			}
			if (seeds <= 6) //if the number of beans are less than 7, the move won't return to the player side again
				more = false;
		}
		update_score(score, ind, (*player2).vec, player1);
	}
	clrscr();
	if (player_1)
		Game_Board(player1, player2, round);
	else
		Game_Board(player2, player1, round);
}


void music() //winning song
{
	Beep(330, 150); Sleep(120);
	Beep(330, 150); Sleep(120);
	Beep(330, 150); Sleep(120);
	Beep(262, 75); Sleep(120);
	Beep(330, 100); Sleep(120);
	Beep(392, 150); Sleep(350);
	Beep(196, 150); Sleep(350);
	Beep(196, 150); Sleep(75);
	Beep(262, 100); Sleep(75);
	Beep(330, 100); Sleep(75);
	Beep(392, 100); Sleep(75);
	Beep(523, 100); Sleep(75);
	Beep(660, 100); Sleep(75);
	Beep(784, 100); Sleep(275);
	Beep(660, 100); Sleep(275);
	Beep(207, 100); Sleep(75);
	Beep(262, 100); Sleep(75);
	Beep(311, 100); Sleep(75);
	Beep(415, 100); Sleep(75);
	Beep(523, 100); Sleep(75);
	Beep(622, 100); Sleep(75);
	Beep(830, 100); Sleep(275);
	Beep(622, 100); Sleep(275);
	Beep(233, 100); Sleep(75);
	Beep(294, 100); Sleep(75);
	Beep(349, 100); Sleep(75);
	Beep(466, 100); Sleep(75);
	Beep(587, 100); Sleep(75);
	Beep(698, 100); Sleep(75);
	Beep(932, 100); Sleep(275);
	Beep(932, 100); Sleep(75);
	Beep(932, 100); Sleep(75);
	Beep(932, 100); Sleep(75);
	Beep(1046, 675);
}


void name(Info *player, int n) //name of the players
{
	bool name;
	cout << " Welcome, what is the name of the player " << n << "? ";
	do
	{
		name = true;
		getline(cin, (*player).name, '\n');
		if (cin.fail())
		{
			cout << " Uuupsss. Invalid input, I think you should try again. ";
			cin.clear();
			name = false;
		}
		else if ((*player).name.length() > 21)
		{
			cout << " Uuupsss. Invalid input, try a name with 20 digits or less. ";
			name = false;
		}
	} while (!name);
}


bool pause_game()
{
	bool error;
	string x;
	SetColor(VC[7].nc); //use the respective color
	cout << "\t\tYou put your game in pause... What do you want do do? [1/2]" << endl;
	cout << "\t\t\t1. Continue" << endl;
	cout << "\t\t\t2. Return to menu" << endl;
	cout << "\t\t-";
	cin.ignore(); //ignore the '\n' in the buffer to use getline
	do
	{
		error = false;
		getline(cin, x, '\n');
		if (x == "1")
			return 0; //continue with the game
		else if (x == "2")
		{
			cout << "\t\tAre you sure? [Y/N] ";
			getline(cin, x, '\n');
			ToUpper(x);
			if (x == "Y")
				return 1; //back to main menu
			else if (x == "N")
			{
				cout << "\t\tSo, what do you want to do? ";
				error = true;
			}
			else
			{
				if (cin.fail())
					cin.clear();
				cout << "\t\tUuupsss. Invalid input, I think you should try again. ";
				error = true;
			}
		}
		else
		{
			if (cin.fail())
				cin.clear();
			cout << "\t\tUuupsss. Invalid input, I think you should try again. ";
			error = true;
		}
	} while (error);
}


bool End_game(Info *player1, Info *player2, bool player_1) //functions that determinates if the game should end
{
	bool crz1 = true, crz2 = true, otherside1 = false, otherside2 = false;
	if ((*player1).score > 24 || (*player2).score > 24) //There are 48 beans in the board, if some player has more than 24 points, there is a winner
	{
		return true;
	}
	for (int i = 0; i < (*player1).vec.size(); i++)
	{
		if ((*player1).vec[i] != 0 && crz1) //if there is an hole with beans, the board side of the player 1 isn't zeroed
			crz1 = false;
		if ((*player1).vec[i] - (6 - i) >= 0 && !otherside1) //if there are beans enough to put on the holes of the other side of the board, there are valid moves
			otherside1 = true;
		if ((*player2).vec[i] != 0 && crz2) //if there is an hole with beans, the board side of the player 2 isn't zeroed
			crz2 = false;
		if ((*player2).vec[i] - (6 - i) >= 0 && !otherside2) //if there are beans enough to put on the holes of the other side of the board, there are valid moves
			otherside2 = true;
		if (otherside1 && otherside2) //if after a move, both players can play, the game should continue
			break;
	}
	if (crz1 && !otherside2 && !player_1) //if there are no beans in the board side of the player 1 and any of the moves of the player 2 can counteract the game is over
	{
		for (int i = 0; i <= 5; i++)
		{
			(*player2).score += (*player2).vec[i]; //player 2 collects all of his beans
		}
		return true;
	}
	else if (crz2 && !otherside1 && player_1) //if there are no beans in the board side of the player 2 and any of the moves of the player 1 can counteract that the game is over
	{
		for (int i = 0; i <= 5; i++)
		{
			(*player1).score += (*player1).vec[i]; //player 2 collects all of his beans
		}
		return true;
	}
	return false;

}


bool play_again(Info *player1, Info *player2, int time)
{
	string x;
	int n1 = 25, n2 = 27;
	int s, m, h;
	s = time % 60; //number of seconds
	m = (time / 60) % 60; //number of minutes
	h = time / 3600; //number of hours
	bool back = true, again;

	if ((*player2).name.length() % 2)
		n2++;
	if ((*player1).name.length() % 2)
		n1++;


	SetColor(15);
	cout << "\n\n\n\n\t\t\t\t\t      ___________________________      " << endl;
	cout << "\t\t\t\t\t     /  "; SetColor(4); cout << "_______________________"; SetColor(15); cout << "  \\      " << endl;
	cout << "\t\t\t\t\t    /  "; SetColor(4); cout << "/                       \\"; SetColor(15); cout << "  \\    " << endl;
	cout << "\t\t\t\t\t   /  "; SetColor(4); cout << "/" << string((n1 - ((*player1).name.length() + 4)) / 2, ' '); SetColor(VC[4].nc); cout << (*player1).name; SetColor(15); cout << ": " << setfill('0') << setw(2) << (*player1).score; SetColor(4); cout << string((n1 - ((*player1).name.length() + 4)) / 2, ' ');
	if (!((*player1).name.length() % 2))
		cout << " ";
	cout << "\\"; SetColor(15); cout << "  \\   " << endl;
	cout << "\t\t\t\t\t  /  "; SetColor(4); cout << "/" << string((n2 - ((*player2).name.length() + 4)) / 2, ' '); SetColor(VC[5].nc); cout << (*player2).name; SetColor(15); cout << ": " << setfill('0') << setw(2) << (*player2).score; SetColor(4); cout << string((n2 - ((*player2).name.length() + 4)) / 2, ' ');
	if (!((*player2).name.length() % 2))
		cout << " "; 
	cout << "\\"; SetColor(15); cout << "  \\  " << endl;
	cout << "\t\t\t\t\t /  "; SetColor(4); cout << "/" << string(8, ' '); SetColor(3); cout << "Time:" << setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s << string(8, ' '); SetColor(4); cout << "\\"; SetColor(15); cout << "  \\ " << endl;
	cout << "\t\t\t\t\t |  "; SetColor(4); cout << "|     "; SetColor(VC[7].nc); cout << "Do you want to play"; SetColor(4); cout << "     |"; SetColor(15); cout << "  |" << endl;
	cout << "\t\t\t\t\t |  "; SetColor(4); cout << "|            "; SetColor(VC[7].nc); cout << "again?"; SetColor(4); cout << "           |"; SetColor(15); cout << "  |" << endl;
	cout << "\t\t\t\t\t |  "; SetColor(4); cout << "|                             |"; SetColor(VC[7].nc); cout << "  |" << endl;
	cout << "\t\t\t\t\t \\  "; SetColor(4); cout << "\\           "; SetColor(VC[7].nc); cout << "[Y / N]"; SetColor(4); cout << "           /"; SetColor(15); cout << "  / " << endl;
	cout << "\t\t\t\t\t  \\  "; SetColor(4); cout << "\\                           /"; SetColor(15); cout << "  /  " << endl;
	cout << "\t\t\t\t\t   \\  "; SetColor(4); cout << "\\                         /"; SetColor(15); cout << "  /   " << endl;
	cout << "\t\t\t\t\t    \\  "; SetColor(4); cout << "\\_______________________/"; SetColor(15); cout << "  /    " << endl;
	cout << "\t\t\t\t\t     \\___________________________/     " << endl;
	cout << "\n\n" << endl; SetColor(VC[7].nc);
	cout << " ";
	do
	{
		again = false;
		getline(cin, x, '\n');
		ToUpper(x);
		if (x == "Y")
		{
			back = false;
			clrscr();
		}
		else if (x == "N")
			back = true;
		else
		{		
			if (cin.fail())
				cin.clear();
			cout << " Uuupsss. Invalid input, I think you should try again. ";
			again = true;
		}
	} while (again);
	return back;
}


void Multiplayer()
{
	bool back = false;
	do
	{
		Info p1, p2, *player1, *player2;
		player1 = &p1;
		player2 = &p2;
		char jogada;
		time_t start;
		string draw;
		int round = 1, tp, timeinpause = 0, ntime = 0;
		bool player_1 = true, error = false, ignore = false, end_game = false, dtrue = false, draws = false, pause = false;// Player1 = true, if it is the turn of the player1
		p1.score = 0; p2.score = 0;
		p1.vec = { 4,4,4,4,4,4 }, p2.vec = { 4,4,4,4,4,4 };
		p1.name = "Player 1"; p2.name = "Player 2";
		Game_Board(player1, player2, round); //Drawing of Score Board and Game Board
		SetColor(VC[7].nc);
		name(player1, 1); //ask for the name of the player1
		name(player2, 2); //ask for the name of the player2
		clrscr();
		Game_Board(player1, player2, round);
		do
		{
			do
			{
				ignore = false; //reset the variable ignore
				if (!error)
				{
					if (player_1) //in the round of the player 1, it will be sent a message with his name
					{
						SetColor(VC[4].nc); cout << " " << (*player1).name; SetColor(VC[7].nc); cout << " it's your turn... Please choose an hole. ";
					}
					else //in the round of the player 2, it will be sent a message with his name
					{
						cout << " Let's go "; SetColor(VC[5].nc); cout << (*player2).name; SetColor(VC[7].nc); cout << "... Please choose an hole. ";
					}
				}
				cin >> jogada;
				if (cin.fail()) //if input is invalid, error = true
				{
					cin.clear();
					error = true;
				}
				else if (cin.peek() != '\n') //the buffer should be clean (just with '\n')
				{
					error = true;
					ignore = true;
				}
				else if (int(jogada) == int('P') || (int(jogada) - 32) == int('P')) //open the pause menu
				{
					tp = time(NULL); //used next, time doesn't count when paused
					pause = true; //the menu pause has been activated
					clrscr();
					Game_Board(player1, player2, round);
					end_game = pause_game(); //pause_game will return a bool, if end_game = 1 the game is over
					timeinpause += (time(NULL) - tp); //time is counting again
					clrscr();
					if(!end_game) //if end_game is true, it isn't necessary to draw the game board
						Game_Board(player1, player2, round);
				}
				else if (player_1 && (int(jogada) < 65 || int(jogada) > 70)) //it's the turn of player 1 and the input is invalid
				{
					error = true;
					ignore = true;
				}
				else if (!player_1 && (int(jogada) < 97 || int(jogada) > 102)) //it's the turn of the player 2 and the input is invalid
				{
					error = true;
					ignore = true;
				}
				else //valid input
				{
					if (ntime == 0) //if it was the first time that the program get an input
					{
						start = time(NULL); //time starts counting
						ntime = 1; //to ensure that time doesn't start to count again
					}
					if (player_1)
						error = valid_move(player_1, 5 - int(jogada) % 65, player1, player2, round); //verify if the move is valid, if error = true - invalid move
					else
						error = valid_move(player_1, int(jogada) % 97, player2, player1, round); //verify if the move is valid, if error = true - invalid move
				}
				if (error)
					cout << " You can't choose that... Please try again! "; //if error = true - invalid move
				if (ignore)
					cin.ignore(1000000000, '\n');
			} while (error); //while input is invalid
			if (!pause)//if the game wasn't paused
			{
				player_1 = !player_1; //time to another player choose a move
				end_game = End_game(player1, player2, player_1); //verify if the other player has any valid move
				round++; //increment the counter
				if ((round == 50 || round == 80) && !end_game) //propose end of the game
				{
					cout << "\tDo you want to end the game? [Y/N] ";
					do
					{
						if (!dtrue) //if it is the first input after the propose, it's necessary to use cin.ignore due to getline
							cin.ignore();
						dtrue = false;
						getline(cin, draw, '\n');
						ToUpper(draw);
						if (draw == "Y")
						{
							end_game = true; //the game is over
							draws = true; //the game is over because the user said yes
						}
						else if (draw == "N") //the game shoul continue
						{
							cout << " \n\tAll right, keep it going!!\n\n"; SetColor(8); cout << "(Press a key to continue...)"; SetColor(VC[7].nc); _getch();
							clrscr();
							Game_Board(player1, player2, round);
						}
						else if (cin.fail()) //invalid input
						{
							cin.clear();
							dtrue = true;
							cout << "\tInvalid Input ";
						}
						else //invalid input
						{
							dtrue = true;
							cout << "\tInvalid Input. ";
						}
					} while (dtrue); //while the input is invalid
				}
				else if (round == 100 && !end_game) //The game is over when both users have played 50 times
				{
					cout << "\tThe game is too long... It is the end!" << endl;
					end_game = true;
					draws = true;
					SetColor(8); cout << "\n\n\t(Press any key to continue...)" << endl;
					_getch();
					cin.ignore();
				}
			}
			else //if the game was paused
			{
				if (!end_game) //and the game is not over
					pause = false;
			}
		} while (!end_game); //while the game is not over
		if (!pause) //if the game is not over because the pause menu
		{
			ntime = (time(NULL) - start) - timeinpause; //stop counting time
			if (draws)
			{
				for (int i = 0; i < 6; i++) //update scores
				{
					(*player1).score += (*player1).vec[i];
					(*player2).score += (*player2).vec[i];
					(*player1).vec[i] = 0;
					(*player2).vec[i] = 0;
				}
			}
			clrscr();
			Game_Board(player1, player2, round);
			ToUpper((*player1).name);
			ToUpper((*player2).name);
			if ((*player1).score > (*player2).score) //who wins
			{
				SetColor(VC[4].nc); cout << "\t\t" << (*player1).name; SetColor(VC[7].nc); cout << " WINS!!!!!!!" << endl;
				music();
			}
			else if((*player1).score < (*player2).score) //who wins
			{
				SetColor(VC[5].nc); cout << "\t\t" << (*player2).name; SetColor(VC[7].nc); cout << " WINS!!!!!!!" << endl;
				music();
			}
			else //in this case, it's a draw
			{
				SetColor(VC[7].nc); cout << "\t\tIt's a DRAW, no one wins....." << endl;
				SetColor(8); cout << "\n\n\t(Press any key to continue...)" << endl;
				_getch();
			}
			clrscr();
			if (!draws)//if draws = false, there is a '\n' in the buffer
				cin.ignore();
			back = play_again(player1, player2, ntime); //back = false if the players wants to play again
		}
		else
			back = true;
	}while (!back); //while player doesn't want to play again
}


int jogadas_do_bot(Info *player1, Info *player2, bool easy)
{
	srand(time(NULL));
	int x, seeds, score, maxs, counter = 0;
	bool clz = true, valid, more;
	vector<int> op, maxind, noturn, protect; //op is the vector with the valid moves, maxind has the moves that "eat" more beans, protect has the moves that avoid the other player to "eat"
	for (int i = 0; i <= 5; i++) 
	{
		if ((*player2).vec[i] != 0) //verify if the other player has some hole with beans
		{
			clz = false;
			break;
		}
	}

	for (int i = 0; i <= 5; i++)
	{
		seeds = (*player1).vec[i]; //number of beans of the hole i
		if (seeds != 0)
		{
			if (clz) //if the other player doesn't has beans in his side of the board
			{
				if (seeds > (5 - i)) //a move will be valid just if it can put some beans in the other side
				{
					op.push_back(i);
				}
			}
			else
			{
				op.push_back(i); //how the other player has beans in his side, a move is valid when the chosen hole has beans
			}
		}
	}
	if (easy) //if the bot is easy
	{
		x = rand() % op.size();
	}
	else //is the bot is expert
	{
		for (int i = 0; i < op.size(); i++) //save in maxind the moves that score more points
		{
			valid = false;
			seeds = (*player1).vec[op[i]];
			for (int t = 1; (t <= (5 - op[i]) && seeds > 0); t++, seeds--) {} //remove the necessary beans to pass to the other side
			if (seeds != 0 && ((seeds % 11) <= 6)) //if the final position of the move is in the opponent side
			{
				score = 0;
				score_number(seeds, player1, player2, valid, more, score);
				if (counter == 0)
				{
					counter = 1;
					maxs = score;
					maxind.push_back(op[i]);
				}
				else
				{
					if (score == maxs)
					{
						maxind.push_back(op[i]);
					}
					else if (score > maxs)
					{
						maxind.resize(0); //the max value will be changed, so the vector should be resized
						maxind.push_back(op[i]); //add the postion that score more points
						maxs = score;
					}
				}
			}
			else //if the final position is in the player side of the board
			{
				if (((*player2).vec[op[i]] + (seeds / 11)) == 2) //if it isn't possible to "eat", the bot tries to defend
					protect.push_back(op[i]);
				else
					noturn.push_back(op[i]); //if it isn't possible to attack or defend, the position is add to this vector
			}
		}
		if (maxind.size() != 0) //if is possible to choose a move that attack, the bot attack
			x = maxind[rand() % maxind.size()];
		else if (protect.size() != 0) //else if is possible to choose a move that defend, the bot defend
			x = protect[rand() % protect.size()];
		else //else, the chosen move is a random valid move
			x = noturn[rand() % noturn.size()];
	}
	return x;
}


void Bot_(bool easy)
{
	bool back = false;
	do
	{
		Info p1, p2, *player1, *player2;
		player1 = &p1;
		player2 = &p2;
		char jogada;
		int ntime = 0, round = 1, timeinpause = 0, tp, x;
		string draw;
		time_t start;
		bool player_1 = false, error = false, ignore = false, end_game = false, dtrue = false, draws = false, pause = false;// Player1 = true, if it is the turn of the player1
		p1.name = "Bot Frank"; p2.name = "Player 2";
		p1.score = 0; p2.score = 0;
		p1.vec = { 4,4,4,4,4,4 }, p2.vec = { 4,4,4,4,4,4 };
		Game_Board(player1, player2, round); //Drawing of Score Board and Game Board
		SetColor(VC[7].nc);
		name(player2, 2); //ask for the name of the player2
		clrscr();
		Game_Board(player1, player2, round);
		do
		{
			if (!player_1)
			{
				do
				{
					ignore = false; //reset the variable ignore
					if (!error) //in the round of the player 2, it will be sent a message with his name
					{
						SetColor(VC[5].nc); cout << " " << (*player2).name; SetColor(VC[7].nc); cout << " it's your turn... Please choose an hole. ";
					}
					cin >> jogada;
					if (cin.fail()) //if input is invalid, error = true
					{
						cin.clear();
						error = true;
					}
					else if (cin.peek() != '\n') //the buffer should be clean (just with '\n')
					{
						error = true;
						ignore = true;
					}
					else if (int(jogada) == int('P') || (int(jogada) - 32) == int('P')) //open the pause menu
					{
						tp = time(NULL); //used next, time doesn't count when paused
						pause = true; //the menu pause has been activated
						clrscr();
						Game_Board(player1, player2, round);
						end_game = pause_game(); //pause_game will return a bool, if end_game = 1 the game is over
						timeinpause += (time(NULL) - tp); //time is counting again
						clrscr();
						if(!end_game) //if end_game is true, it isn't necessary to draw the game board
							Game_Board(player1, player2, round);
					}
					else if (int(jogada) < 97 || int(jogada) > 102) //it's the turn of player 2 and the input is invalid
					{
						error = true;
						ignore = true;
					}
					else //valid input
					{
						if (ntime == 0) //if it was the first time that the program get an input
						{
							start = time(NULL); //time starts counting
							ntime = 1; //to ensure that time doesn't start to count again
						}
						error = valid_move(player_1, int(jogada) % 97, player2, player1, round); //verify if the move is valid, if error = true - invalid move
					}
					if (error)
						cout << " You can't choose that... Please try again! "; //if error = true - invalid move
					if (ignore)
						cin.ignore(1000000000, '\n');
				} while (error); //while input is invalid
			}
			else
			{
				clrscr();
				Game_Board(player1, player2, round);
				cout << "\t\t\t\t\t" << (*player1).name << " is thinking...\n\n" << endl;
				SetColor(8); cout << "\t(Press any key to continue...)" << endl; SetColor(VC[7].nc);
				_getch();
				x = jogadas_do_bot(player1, player2, easy);
				cout << "\n\t\t Bot Frank played " << char(70 - x) << "!!\n\n" << endl;
				SetColor(8); cout << "\t(Press any key to continue...)" << endl; SetColor(VC[7].nc);
				_getch();
				valid_move(true, x, player1, player2, round);
			}
			if (!pause) //if the game wasn't paused
			{
				player_1 = !player_1; //time to another player choose a move
				end_game = End_game(player1, player2, player_1); //verify if the other player as any valid move
				round++; //increment the counter
				if ((round == 50 || round == 80) && !end_game) //propose end of the game
				{
					cout << "\tDo you want to end the game? [Y/N] ";
					do
					{
						if (!dtrue) //if it is the first input after the propose, it's necessary to use cin.ignore due to getline
							cin.ignore();
						dtrue = false;
						getline(cin, draw, '\n');
						ToUpper(draw);
						if (draw == "Y")
						{
							end_game = true; //the game is over
							draws = true; //the game is over because the user said yes
						}
						else if (draw == "N") //the game should continue
						{
							cout << " \n\tAll right, keep it going!!\n\n"; SetColor(8); cout << "(Press a key to continue...)"; SetColor(VC[7].nc); _getch();
							clrscr();
							Game_Board(player1, player2, round);
						}
						else if (cin.fail()) //invalid input
						{
							cin.clear();
							dtrue = true;
							cout << "\tInvalid Input ";
						}
						else //invalid input
						{
							dtrue = true;
							cout << "\tInvalid Input. ";
						}
					} while (dtrue); //while the input is invalid
				}
				else if (round == 100) //The game is over when both users have played 50 times
				{
					cout << "\tThe game is too long... It is the end!" << endl;
					end_game = true;
					draws = true;
					SetColor(8); cout << "\n\n\t(Press any key to continue...)" << endl;
					_getch();
					cin.ignore();
				}
			}
			else //if the game was paused
				if (!end_game) //and the game is not over
					pause = false;
		} while (!end_game); //while the game is not over
		if (!pause) //if the game is not over because the pause menu
		{
			ntime = (time(NULL) - start) - timeinpause; //stop counting time
			if (draws)
			{
				for (int i = 0; i < 6; i++) //update scores
				{
					(*player1).score += (*player1).vec[i];
					(*player2).score += (*player2).vec[i];
					(*player1).vec[i] = 0;
					(*player2).vec[i] = 0;
				}
			}
			clrscr();
			Game_Board(player1, player2, round);
			ToUpper((*player1).name);
			ToUpper((*player2).name);
			if ((*player1).score > (*player2).score) //who wins
			{
				cout << "\t\t" << (*player1).name << " WINS!!!!!!!" << endl;
				cout << "\t\tKeep trying, maybe in the next game you win...";
				SetColor(8); cout << "\n\n\t(Press any key to continue...)" << endl;
				_getch();
			}
			else if((*player1).score < (*player2).score) //who wins
			{
				SetColor(VC[5].nc); cout << "\t\t" << (*player2).name; SetColor(VC[7].nc); cout << " WINS!!!!!!!" << endl;
				music();
			}
			else //in this case, it's a draw
			{
				SetColor(VC[7].nc); cout << "\t\tIt's a DRAW, no one wins....." << endl;
				SetColor(8); cout << "\n\n\t(Press any key to continue...)" << endl;
				_getch();
			}
			clrscr();
			if (!draws)//if draws = false, there is a '\n' in the buffer
				cin.ignore();
			back = play_again(player1, player2, ntime); //back = false if the players wants to play again
		}
		else
			back = true;
	} while (!back);
}


void Bot()
{
	bool ValidOptionsInput, Loop = true;
	string options;
	do
	{
		SetColor(VC[0].nc);
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t        _____            _________ \t\t\t" << endl;
		cout << "\t\t\t\t\t\t       |  _  |   _____  |___   ___|\t\t\t" << endl;
		cout << "\t\t\t\t\t\t       | |_| |  |  _  |     | |    \t\t\t" << endl;
		cout << "\t\t\t\t\t\t       |    /   | | | |     | |    \t\t\t" << endl;
		cout << "\t\t\t\t\t\t       |  _ \\   | | | |     | |    \t\t\t" << endl;
		cout << "\t\t\t\t\t\t       | |_| |  | |_| |     | |    \t\t\t" << endl;
		cout << "\t\t\t\t\t\t       |_____|  |_____|     |_|    \t\t\t" << endl;
		cout << "\n\n";
		SetColor(VC[1].nc);
		cout << "\t\t\t\t\t\t     ____________________________" << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; SetColor(VC[2].nc); cout << "            EASY"; SetColor(VC[1].nc); cout << "            | " << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\t\t\t\t\t\t     ____________________________ " << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; SetColor(VC[2].nc); cout << "           EXPERT"; SetColor(VC[1].nc); cout << "           |" << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\t\t\t\t\t\t     ____________________________ " << endl;
		cout << "\t\t\t\t\t\t    |                            |" << endl;
		cout << "\t\t\t\t\t\t    |"; SetColor(VC[2].nc); cout << "            BACK"; SetColor(VC[1].nc); cout << "            |" << endl;
		cout << "\t\t\t\t\t\t    |____________________________|" << endl;
		cout << "\n\n" << endl; SetColor(VC[7].nc);
		cout << " What do you want to do? ";
		do
		{
			ValidOptionsInput = true;
			getline(cin, options, '\n');
			ToUpper(options);
			if (cin.fail())
			{
				cout << " Uuupsss. Invalid input, I think you should try again. ";
				cin.clear();
			}
			else if (options == "BACK")
			{
				Loop = false;
				ValidOptionsInput = false;
			}
			else if (options == "EASY")
			{
				ValidOptionsInput = false;
				clrscr();
				Bot_(true); //run the bot as easy mode
			}
			else if (options == "EXPERT")
			{
				ValidOptionsInput = false;
				clrscr();
				Bot_(false); //run the bot as expert mode
			}
			else
				cout << " Uuupsss. Invalid input, I think you should try again. ";
		} while (ValidOptionsInput);
		clrscr();
	} while (Loop);
}


int main()
{	
	INICIO();
	return 0;
}