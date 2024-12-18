#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <cstdint>

class ConsoleGraphics
{
protected:
	enum ConsoleColor
	{
		BLACK = 0,
		BLUE = 1,
		GREEN = 2,
		AQUA = 3,
		RED = 4,
		PURPLE = 5,
		YELLOW = 6,
		WHITE = 7,
		GRAY = 8,
		LIGHT_BLUE = 9,
		LIGHT_GREEN = 10,
		LIGHT_AQUA = 11,
		LIGHT_RED = 12,
		LIGHT_PURPLE = 13,
		LIGHT_YELLOW = 14,
		BRIGHT_WHITE = 15
	};

	/// <summary>
	/// Input color code 0-15 for text and background.
	/// </summary>
	/// <param name="textColor"></param>
	/// <param name="backgroundColor"></param>
	void SetColor(ConsoleColor textColor, ConsoleColor backgroundColor);

	/// <summary>
	/// Input color code 0-15 for text and background.
	/// </summary>
	/// <param name="textColor"></param>
	/// <param name="backgroundColor"></param>
	void SetColor(ConsoleColor textColor);

	/// <summary>
	/// Sets the color to default (white text, black bg).
	/// </summary>
	void ResetColor();

	/// <summary>
	/// Sets the cursor position to specified coordinate.
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void SetCursorPosition(uint16_t x, uint16_t y);

	/// <summary>
	/// Hides the cursor in the console.
	/// </summary>
	void HideConsoleCursor();

	/// <summary>
	/// Shows the cursor in the console.
	/// </summary>
	void ShowConsoleCursor();

	/// <summary>
	/// Set console size to input.
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height"></param>
	void SetNewConsoleSize(uint16_t width, uint16_t height);

	/// <summary>
	/// Returns the width of the console window.
	/// </summary>
	/// <returns></returns>
	int GetConsoleWidth();

	/// <summary>
	/// Returns the height of the console window.
	/// </summary>
	/// <returns></returns>
	int GetConsoleHeight();
};