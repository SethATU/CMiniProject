//C++ Mini Project 
//TicTaCToe

#include <stdio.h>
#include <stdlib.h> //used for rand() and srand()
#include <time.h>	//used for time()

int board[3][3]; //set board as a global variable

void boardReset();
void boardSetUp();
int freeSpace();
void moveComputer();
void movePlayer();
char checkWin();
void printWin();

/*
boardSetUp(); //calls the function to setup the board

				movePlayer(); //calls function so the player can make their move
				checkWin(); //calls the function to see if a winning move was done
				moveComputer(); //calls the function so the cpu can take its turn
				checkWin(); //calls the function to see if a winning move was done */

int main()
{
	char play = ' ';
	
	printf("Would you like to play??? (Y = yes : N = no) : ");
	scanf_s(" %c", &play);

	switch (play)
	{
		// a new game starts
		case 'y':
		case 'Y':

			boardReset(); //calls the function to reset the board

			do
			{
				//players move 
				boardSetUp();
				freeSpace();
				movePlayer();
				if (checkWin() != ' ')
				{
					break;
				}

				//cpus move
				boardSetUp();
				freeSpace();
				moveComputer();
				if (checkWin() != ' ')
				{
					break;
				}

			} while (freeSpace() != 0);

			boardSetUp();
			//anounces if the cpu or the player won 
			printWin();
			break;

		// the program ends
		case 'n':
		case 'N':
			break;
	}
	
	return 0;
}

void boardReset() //this function sets every space to ' ' which is a empty space
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void boardSetUp() //this function sets up the board and is what is used to place in the inputs from the user and the cpu 
{
	printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("---|---|--- \n");
	printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("---|---|--- \n");
	printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int freeSpace() //this function checks to see if there are any free spaces so the user and cpu dont place a X or O on a space already picked 
{
	int empty = 9;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != ' ')
			{
				empty--;
			}
			
		}
	}
	return empty;
}

void moveComputer()
{

}

void movePlayer()
{
	int x, y;

	//player entersa row
	printf("\nEnter Row (0-2): ");
	scanf_s("%d", &x);
	
	//player enters colume
	printf("Enter Colume (0-2): ");
	scanf_s("%d", &y);

	//if the player enters a number to big the player is asked to reenter their move
	if (x || y > 2)
	{
		printf("\nInvalid entry!!");
		movePlayer();
	}
	else if (board[x][y] != ' ')
	{
		printf("\nInvalid entry!!");
		movePlayer();
	}

	board[x][y] = 'X';
}

char checkWin()
{
	//checking for a rown win 
	if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
	{
		return board[0][0];
	}
	else if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
	{
		return board[1][0];
	}
	else if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
	{
		return board[2][0];
	}

	//checking for diagional win
	else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		return board[0][2];
	}
	else if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		return board[0][0];
	}

	//checking for columb win
	if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
	{
		return board[0][0];
	}
	else if (board[0][1] == board[1][1] && board[0][1] == board[2][1])
	{
		return board[0][1];
	}
	else if (board[0][2] == board[1][2] && board[0][2] == board[2][2])
	{
		return board[0][2];
	}

	//if non of the if statments are true then its a tie
	else
	{
		return ' ';
	}
}

void printWin()
{

}
