#pragma once
#include "ColorsAndCursor.h"

/*
Color codes for SetColor()
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

void ColorsAndCursor::SetColor(int textColor, int backgroundColor)
{
	// Avoiding errors in case someone were to input an invalid color code.
	if ((0 <= textColor && textColor <= 15) && (0 <= backgroundColor && backgroundColor <= 15))
	{
		// Moves the bits of bg color 4 steps to the left to combine the colors in a way that the compiler can can read both the bg and text color from the same int. 
		int color = textColor + (backgroundColor << 4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
}

void ColorsAndCursor::SetColor(int textColor)
{
	// 0 is black (default bg color).
	SetColor(textColor, 0);
}

void ColorsAndCursor::ResetColor()
{
	SetColor(7, 0); // White and black
}

void ColorsAndCursor::SetCursorPosition(int x, int y)
{
	// Get the handle to the console window
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Set the cursor position
	COORD position;
	position.X = x;
	position.Y = y;

	SetConsoleCursorPosition(consoleHandle, position);
}

int ColorsAndCursor::ScreenWidth()
{
	// Retrieve console buffer info
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	return width;
}

int ColorsAndCursor::ScreenHeight()
{
	// Retrieve console buffer info
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return height;
}