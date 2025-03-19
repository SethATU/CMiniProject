//C++ Mini Project 
//TicTaCToe

#include <stdio.h>
#include <stdlib.h> //used for rand() and srand()
#include <time.h>	//used for time()

char board[3][3];

void boardReset();
void boardSetUp();
int freeSpace();
void moveComputer();
void movePlayer();
char checkWin();
void printWin();

int main()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%i", board[i][j]);
		}
	}

	

	return 0;
}

void boardReset()
{

}

void boardSetUp()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			do
			{
				printf("|");
			} while (board[0][0] && board[0][1] && board[0][2]);
		}
	}
}

int freeSpace()
{

}

void moveComputer()
{

}

void movePlayer()
{

}

char checkWin()
{

}

void printWin()
{

}
