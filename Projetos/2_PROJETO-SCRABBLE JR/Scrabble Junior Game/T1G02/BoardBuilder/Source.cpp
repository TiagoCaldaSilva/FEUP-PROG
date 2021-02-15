#include "Board.h"
#include <windows.h>
#include <wincon.h>

using namespace std;

#ifdef _WIN32
#ifndef UNICODE
#define UNICODE
#endif


// Fix compilatin on MinGW
#ifndef DISABLE_NEWLINE_AUTO_RETURN
#define DISABLE_NEWLINE_AUTO_RETURN 0x0008
#endif

#ifndef ENABLE_VIRTUAL_TERMINAL_INPUT
#define ENABLE_VIRTUAL_TERMINAL_INPUT 0x0200
#endif

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

bool SetupConsole() {
	//configures the console in Windows so that ASCII codes are accepted. Code taken from Microsoft Docs:
	//https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences#example-of-enabling-virtual-terminal-processing
	//Set output mode to handle virtual terminal sequences
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hIn == INVALID_HANDLE_VALUE || hOut == INVALID_HANDLE_VALUE) {
		return false;
	}
	DWORD dwOriginalInMode = 0;
	DWORD dwOriginalOutMode = 0;
	if (!GetConsoleMode(hIn, &dwOriginalInMode)) 
		return false;
	if (!GetConsoleMode(hOut, &dwOriginalOutMode)) 
		return false;
	DWORD dwInMode = dwOriginalInMode | ENABLE_VIRTUAL_TERMINAL_INPUT;
	if (!SetConsoleMode(hIn, dwInMode))
		// Failed to set VT input mode, can't do anything here.
		return false;
	DWORD dwOutMode = dwOriginalOutMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING | DISABLE_NEWLINE_AUTO_RETURN;
	if (!SetConsoleMode(hOut, dwOutMode)) {
		// we failed to set both modes, try to step down mode gracefully.
		dwOutMode = dwOriginalOutMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		if (!SetConsoleMode(hOut, dwOutMode))
			// Failed to set any VT mode, can't do anything here.
			return false;
	}
	return true;
}
#endif //_WIN32

int main() {

	Board board;
	cout << "\033[2J\033[H" << "=========BOARD BUILDER=========" << endl << endl;
	board.getDimension();
	board.initVectors();
	board.showBoardLetters();

	while (board.addNewWord()) {
		board.showBoardLetters();
		board.showMessage();
	}

	board.fileOut();

	return 0;
}