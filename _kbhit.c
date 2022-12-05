// '*' moves in a certain direction and its direction is changed with 'w', 's', 'z', 'a' keys. Stop with p and exit the program with q.
// By using a Windows API function called Sleep in the code, the program waits until the written millisecond.

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define UP			0
#define RIGHT		1
#define DOWN		2
#define LEFT		3

void get_console_size(int *height, int *width)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	*width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	*height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void hide_cursor(void)
{
	CONSOLE_CURSOR_INFO cinfo;

	cinfo.dwSize = 100;
	cinfo.bVisible = FALSE;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cinfo);
}

void writec(int row, int col, char ch)
{
	COORD coord = {col, row};
	DWORD dw;

	WriteConsoleOutputCharacterA(GetStdHandle(STD_OUTPUT_HANDLE), &ch, 1, coord, &dw);
}

int main(void)
{
	int rowsize, colsize;
	int row, col;
	int direction;
	int ch;

	get_console_size(&rowsize, &colsize);
	hide_cursor();

	row = 10, col = 10;
	direction = RIGHT;

	for (;;) {
		writec(row, col, '*');

		Sleep(100);


		if (_kbhit()) {
			ch = _getch();
			switch (ch) {
				case 'w':
					direction = UP;
					break;
				case 's':
					direction = RIGHT;
					break;
				case 'z':
					direction = DOWN;
					break;
				case 'a':
					direction = LEFT;
					break;
				case 'p':
		  		    _getch();
					break;
				case 'q':
					goto EXIT;
			}
		}

		writec(row, col, ' ');

		switch (direction) {
			case UP:
				if (row == 0)
					row = rowsize - 1;
				else
					--row;
				break;
			case RIGHT:
				if (col == colsize - 1)
					col = 0;
				else
					++col;
				break;
			case DOWN:
				if (row == rowsize - 1)
					row = 0;
				else
					++row;
				break;
			case LEFT:
				if (col == 0)
					col = colsize - 1;
				else
					--col;
				break;
		}
	}
EXIT:
	
	return 0;
}
