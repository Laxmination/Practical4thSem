#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void PrintState(char [3][3]);
char CheckState(char [3][3],char,int,int);
void PlayerMove(char [3][3], char, int, int);
bool checkThree(char [3][3],char, int, int);

int main(void)
{
	char tictac[3][3];
	char player,choice;
	int i, j, x, y;


    do
    {
     printf("\n Welcome to Tic-Tac-Toe game!\n");

	 for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		  tictac[i][j] = '\0';

     PrintState(tictac);

	 printf("\n Symbol for player A : X");
	 printf("\n Symbol for player B : O");

	 printf("\n\n Each player makes a move by entering position as \"x y\" where 0<=x,y<=2");

	 printf("\nPlayer A enter the position for your move(x y):  ");
	 scanf("%d%d", &x, &y);

	 player = 'A';
	 PlayerMove(tictac, player, x, y);

	 printf("\n\nGame Over!");
	 printf("\n\nThanks for Playing\n\n");

     fflush(stdin);

     printf("Do you want to play again (Y/N)");
     scanf("%c",&choice);
    }
    while(choice=='y'||choice=='Y');

	return 0;
}

void PlayerMove(char T[3][3], char player, int x, int y)
{
	int a, b;
	system("CLS");
	if(T[x][y] != '\0'||x<0||x>2||y<0||y>2)
	{
		PrintState(T);
		printf("Wrong position player %c! you cannot move to position (%d,  %d)\n",player, x, y);
		printf("\nPlease enter a valid position of empty location: ");

		scanf("%d%d", &x, &y);
		PlayerMove(T, player, x, y);
	}

    else
    {

		if (player == 'A')
			T[x][y] = 'x';
		else
			T[x][y] = 'o';

		PrintState(T);
		if (CheckState(T,player,x,y) == 'D')
		{
			printf("\nGame Draw!");
			return;
		}
		else if (CheckState(T,player,x,y) == 'X')
		{
			printf("\nHurrey! Player A wins!");
			return;
		}
		else if (CheckState(T,player,x,y) == 'O')
		{
			printf("\nHurrey! Player B wins!");
			return;
		}
		else
		{
			if (player == 'A')
				player = 'B';
			else
				player = 'A';

			printf("\nPlayer %c Please make your move: ",player);
			scanf("%d%d", &a, &b);
			PlayerMove(T, player, a, b);
		}
    }
}
char CheckState(char T[3][3],char p,int x, int y)
{
	int i, j;

	//check for win by A
	if (p == 'A')
	{
		if(checkThree(T,'x', x, y))
			return 'X';
	}

	//check for win by B
	if (p == 'B')
	{
		if (checkThree(T,'o', x, y))
			return 'O';
	}

	//check for draw
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (T[i][j] == '\0')
				break;

		}
		if (j < 3)
			break;
	}
	if (j == 3 && i == 3)
		return 'D';
    else
        return 'G';
}

bool checkThree(char T[3][3],char c,int x,int y)
{
	if (x == 0 && y == 0)
		{
			if ((T[x + 1][y] == c && T[x + 2][y] == c)||(T[x][y+1]==c&&T[x][y+2]==c)||(T[x+1][y+1]==c&&T[x+2][y+2]==c))
				return true;

		}

	if (x == 0 && y == 1)
		{
			if ((T[x][y - 1] == c && T[x][y + 1] == c) || (T[x + 1][y] == c && T[x + 2][y] == c))
			return true;
		}

	if (x == 0 && y == 2)
		{
		if ((T[x][y - 1] == c && T[x][y - 2] == c) || (T[x + 1][y] == c && T[x + 2][y] == c) || T[x + 1][y - 1] == c && (T[x + 2][y - 2] == c))
			return true;
		}

	if (x == 1 && y == 0)
	{
		if ((T[x - 1][y] == c && T[x + 1][y] == c) || (T[x][y + 1] == c && T[x][y + 2] == c))
			return true;
	}

	if (x == 1 && y == 1)
	{
		if ((T[x - 1][y - 1] == c && T[x + 1][y + 1] == c) || (T[x + 1][y - 1] == c && T[x - 1][y + 1] == c) ||
			(T[x - 1][y] == c && T[x + 1][y] == c)||(T[x][y-1]==c&&T[x][y+1]==c))
			return true;
	}

	if (x == 1 && y == 2)
	{
		if ((T[x][y - 1] == c && T[x][y - 2] == c) || (T[x - 1][y] == c && T[x + 1][y] == c))
			return true;
	}

	if (x == 2 && y == 0)
	{
		if ((T[x - 1][y] == c && T[x - 2][y] == c) || (T[x][y + 1] == c && T[x][y + 2] == c) || (T[x - 1][y + 1] == c && T[x - 2][y + 2] == c))
			return true;
	}

	if (x == 2 && y == 1)
	{
		if ((T[x][y - 1] == c && T[x][y + 1] == c) || (T[x - 1][y] == c && T[x - 2][y] == c))
			return true;
	}

	if (x == 2 && y == 2)
	{
		if((T[x-1][y]==c&&T[x-2][y]==c)||(T[x][y-1]==c&&T[x][y-2]==c)||(T[x-1][y-1]==c&&T[x-2][y-2]==c))
			return true;
	}
    return false;
}
void PrintState(char T[3][3])
{
	int i, j, k;
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		for (k = 0; k < 3; k++)
			printf("--");
		printf("-");
		printf("\n");
		printf("|");

		for (j = 0; j < 3; j++)
		{

			if (T[i][j] != '\0')
				printf("%c", T[i][j]);
			else
				printf(" ");


			printf("|");
		}

		printf("\n");
	}

	for (i = 0; i < 3; i++)
		printf("--");
	printf("-");

	printf("\n");

}