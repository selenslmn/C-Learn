/* There is no ready-made standard C function to print a character anywhere on the console screen independent of the cursor. 
Similarly, there are no standard C functions for writing colored text on the console screen. 
There are special functions called "Console APIs" in Windows systems for such operations. 
Similarly, in UNIX/Linux and macOS systems, such operations can be done more easily with libraries such as "curses". 
In the example below, writec, hide_cursor and get_console_size functions are written using the console APIs of Windows. 
Then a '*' is moved using the write function. 
The _getch function here is an additional function in Microsoft compilers that runs as soon as the key is pressed. */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

void get_console_size(int *height, int *width)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;          /* Retrieves information about the specified console screen buffer. */

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	*width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	*height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void hide_cursor(void)
{
	CONSOLE_CURSOR_INFO cinfo;        /* Sets the size and visibility of the cursor for the specified console screen buffer. */

	cinfo.dwSize = 100;
	cinfo.bVisible = FALSE;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cinfo);
}

void writec(int row, int col, char ch)
{
	COORD coord = {col, row};
	DWORD dw;                     /* Copies a number of characters to consecutive cells of a console screen buffer, beginning at a specified location. */

	WriteConsoleOutputCharacterA(GetStdHandle(STD_OUTPUT_HANDLE), &ch, 1, coord, &dw);  
}

int main(void)
{
	int rowsize, colsize;
	int row, col;
	int ch;

	get_console_size(&rowsize, &colsize);
	hide_cursor();

	row = 10, col = 10;

	for (;;) {
		
		writec(row, col, '*');

		ch = _getch();
		
		writec(row, col, ' ');

		switch (ch) {
			case 'w':
				if (row == 0)
					row = rowsize - 1;
				else
					--row;
				break;
			case 's':
				if (col == colsize - 1)
					col= 0;
				else
					++col;
				break;
			case 'z':
				if (row == rowsize - 1)
					row = 0;
				else
					++row;
				break;
			case 'a':
				if (col == 0)
					col = colsize - 1;
				else
					--col;
				break;
		}
	}
	
	return 0;
}
