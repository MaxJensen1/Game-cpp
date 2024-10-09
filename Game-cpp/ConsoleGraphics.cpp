#pragma once
#include "ConsoleGraphics.h"

/*
** Color codes: **
0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
10 = Light Green
11 = Light Aqua
12 = Light Red
13 = Light Purple
14 = Light Yellow
15 = Bright White
*/

void ConsoleGraphics::SetColor(ConsoleColor textColor, ConsoleColor backgroundColor)
{
	// Avoiding errors in case someone were to input an invalid color code.
	if ((0 <= textColor && textColor <= 15) && (0 <= backgroundColor && backgroundColor <= 15))
	{
		// Moves the bits of bg color 4 steps to the left to combine the colors in a way that the compiler can can read both the bg and text color from the same int. 
		int color = textColor + (backgroundColor << 4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
}

void ConsoleGraphics::SetColor(ConsoleColor textColor)
{
	// 0 is black (default bg color).
	SetColor(textColor, BLACK);
}

void ConsoleGraphics::ResetColor()
{
	SetColor(WHITE, BLACK); // White and black
}

void ConsoleGraphics::SetCursorPosition(uint16_t x, uint16_t y)
{
	// Get the handle to the console window
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Set the cursor position
	COORD position;
	position.X = x;
	position.Y = y;

	SetConsoleCursorPosition(consoleHandle, position);
}

void ConsoleGraphics::HideConsoleCursor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the handle to the console output
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hConsole, &cursorInfo); // Get current cursor info
	cursorInfo.bVisible = FALSE; // Set cursor visibility to false
	SetConsoleCursorInfo(hConsole, &cursorInfo); // Set the modified cursor info
}

void ConsoleGraphics::ShowConsoleCursor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the handle to the console output
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hConsole, &cursorInfo); // Get current cursor info
	cursorInfo.bVisible = TRUE; // Set cursor visibility to true
	SetConsoleCursorInfo(hConsole, &cursorInfo); // Set the modified cursor info
}

void ConsoleGraphics::SetNewConsoleSize(uint16_t width, uint16_t height)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size; // Has an x and y coordinate (width and height)

	size.X = width;
	size.Y = height;

	SetConsoleScreenBufferSize(consoleHandle, size);

	SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };
	SetConsoleWindowInfo(consoleHandle, TRUE, &windowSize);
}

int ConsoleGraphics::GetConsoleWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	return width;
}

int ConsoleGraphics::GetConsoleHeight()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return height;
}