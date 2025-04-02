//C++ Mini Project 
//TicTaCToe

#include <stdio.h>
#include <stdlib.h> //used for rand() and srand()
#include <time.h>	//used for time()

int board[3][3]; //set board as a global variable

//seting up all the functions needed
void boardReset(); 
void boardSetUp();
int freeSpace();
void moveComputer();
void movePlayer();
char checkWin();
void printWin();

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

				boardSetUp();
				//cpus move
				printf("\nCPUs turn\n");
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

int freeSpace() //this function checks to see if there are any free spaces and when there are no more spaces the game ties or the player/cpu win 
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

void moveComputer() //this function uses random numbers for the cpu to pick a place to place a O,  if the space picked is a ' ' then cpu goes again till it picks a space not clamed 
{
	srand(time(0));
	int move = (rand() % 9);

	switch (move)
	{
		case 0:
			if (board[0][0] == ' ')
			{
				board[0][0] = 'O';
			}
			else
			{
				moveComputer();
			}
			break;

		case 1:
			if (board[0][1] == ' ')
			{
				board[0][1] = 'O';
			}
			else
			{
				moveComputer();
			}
			break;

		case 2:
			if (board[0][2] == ' ')
			{
				board[0][2] = 'O';
			}
			else
			{
				moveComputer();
			}
			break;

		case 3:
			if (board[1][0] == ' ')
			{
				board[1][0] = 'O';
			}
			else
			{
				moveComputer();
			}
			break;

		case 4:
			if (board[1][1] == ' ')
			{
				board[1][1] = 'O';
			}
			else
			{
				moveComputer();
			}
			break;

		case 5:
			if (board[1][2] == ' ')
			{
				board[1][2] = 'O';
			}
			else
			{
				moveComputer();
			}
			break;

		case 6:
			if (board[2][0] == ' ')
			{
				board[2][0] = 'O';
			}
			else
			{
				moveComputer();
			}
			break;

		case 7:
			if (board[2][1] == ' ')
			{
				board[2][1] = 'O';
			}
			else
			{
				moveComputer();
			}
			break;

		case 8:
			if (board[2][2] == ' ')
			{
				board[2][2] = 'O';
			}
			else
			{
				moveComputer();
			}
			break;
	}
}

void movePlayer()
{
	int x = 0, y = 0;

	//player entersa row
	printf("\nEnter Row (0-2): ");
	scanf_s("%d", &x);
	
	//player enters colume
	printf("Enter Colume (0-2): ");
	scanf_s("%d", &y);

	//if the player enters a number to big the player is asked to reenter their move
	if (x > 2 || y > 2)
	{
		printf("\nInvalid entry!!");
		movePlayer();
	}
	//if the player enters a number that has already been picked the player is asked to reenter their move
	else if (board[x][y] != ' ')
	{
		printf("\nInvalid entry!!");
		movePlayer();
	}

	board[x][y] = 'X';
}

char checkWin()
{
	char character;
	//checking for a rown win 
	if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
	{
		character = board[0][0];
	}
	else if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
	{
		character = board[1][0];
	}
	else if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
	{
		character = board[2][0];
	}

	//checking for diagional win
	else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		character = board[0][2];
	}
	else if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		character = board[0][0];
	}

	//checking for columb win
	if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
	{
		character = board[0][0];
	}
	else if (board[0][1] == board[1][1] && board[0][1] == board[2][1])
	{
		character = board[0][1];
	}
	else if (board[0][2] == board[1][2] && board[0][2] == board[2][2])
	{
		character = board[0][2];
	}

	//if non of the if statments are true then its a tie
	else
	{
		character = ' ';
	}

	return character;
}

void printWin()
{
	if (checkWin == 'X')
	{
		printf("You Win!!!");
	}
	else if (checkWin == 'O')
	{
		printf("CPU Win!!!");
	}
	else if (freeSpace == 0)
	{
		printf("Nobody Wins :( ");
	}
}
