// Ray Mannion Bingo Project
// g00340315
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void makeCard();
void loadGame();
void drawNum();
void saveGame();
main(void)
{
	//FILE* filep;// creates file to write too
	srand(time(NULL));
	int option;
	int playOpt=0;
	int bingo[3][9];// creates an array
	int row =0;
	int col=0;
	int number;
	int numPlayers=0;
	//filep = fopen("bingo.txt", "r");// opens text  file 
	printf("=================================\n");
	printf("           BINGO\n");
	printf("=================================\n");
	printf("Please enter 1 to start a new game\n");
	printf("Please enter 2 to load a game\n");
	printf("Option : ");
	scanf("%d", &option);
	switch(option)
	{
	case 1:
		makeCard();// calls makeCard function
	case 2:
		loadGame(row, col, bingo[3][9], numPlayers);// not working
	}

	printf("Press 3 to draw a number \n");
	printf("Press 4 to save game & exit \n");
	printf("Option : ");
	scanf("%d", &playOpt);
	switch(playOpt)
	{
	case 3:
		drawNum(playOpt);// calls drawNum function
	case 4:
		saveGame(row, col, bingo[3][9], numPlayers);// not working
	}
	
	getch();
			
}// main

void makeCard()
{
	FILE* filep;// creates file to write too
	int bingo[3][9];// creates an array
	int row;
	int col;
	int count = 0;
	int number;
	int numPlayers;
	filep = fopen("bingo.txt", "a");// allows user to amend the text file
	printf("\nEnter Number of players ( 2-6 ): ");
	scanf("%d", &numPlayers);
	
	for (int i = 1; i <= numPlayers; i++)
	{
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 9; col++)
			{
				bingo[row][col] = rand() * 9 / RAND_MAX + 1 + col * 10;// generates a 3x9 matrix
			}// for
		}// for

		for (row = 0; row < 3; row++)
		{
			count = 0;	// counter  blanks
			do
			{
				number = (((rand() * 9) / RAND_MAX));// generates a num between 1-9
				if (bingo[row][number] != 0)
				{
					bingo[row][number] = 0;	//forces num at each position to be 0
					count++;	//increment
				}//if
			}//do
			while (count < 4);	//do a 0 on each row while it is <4.
		}//for
		
		printf("Player %d Card \n", i);// print card number
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 9; col++)
			{
				if (bingo[row][col] == 0)
				{
					printf("X");
				}
				printf("%d\t", bingo[row][col]);// prints card 
			}// for
			
			printf("\n");
		
		}// for
		printf("\n");
		
		
	}// outer for
	if (filep != NULL)
	{
		// prints data to text file, but will only print last card for the number of players
		for (int i = 1; i <= numPlayers; i++)
		{
			fprintf(filep, "Player %d Card \n", i);// print card number
			for (row = 0; row < 3; row++)
			{
				for (col = 0; col < 9; col++)
				{
					if (bingo[row][col] == 0)
					{
						fprintf(filep, "X");
					}
					fprintf(filep, "%d\t", bingo[row][col]);
				}// for
				fprintf(filep, "\n");
			}// for
			fprintf(filep, "\n");
		}
	}// if
	if (filep != NULL)
	{
		fclose(filep);// closes text file

	}// if


}// makeCard
void loadGame(int row,int col,int bingo[3][9],int numPlayers)// load file didn't work 
{
	/*FILE* filep;// creates file to write too  
	filep = fopen("bingo.txt", "r");// opens text  file 
	int load;
	int empty = 0;
	if (filep == NULL)
	{
		printf("The file cannot be opened to read\n");
		empty = 1;// checks if file contains data

	}
	else
	{
		while (!feof(filep))
		{
			load = fscanf(filep, "%d\t", bingo[row][col]);
			// reads in the data in the text file
			if (load > 0)
			{
				// prints data to screen
				for (int i = 1; i <= numPlayers; i++)
				{
					printf("Player %d Card \n", i);// print card number
					for (row = 0; row < 3; row++)
					{
						for (col = 0; col < 9; col++)
						{
							printf("%d\t", bingo[row][col]);// prints card 
						}// for
						printf("\n");
					}// for
					fprintf(filep, "\n");
				}
			}
		}

		fclose(filep);// closes text file 
	}*/

}// loadGame
void saveGame(int row, int col, int bingo[3][9], int numPlayers)// i tried to get this function to save the bingo cards to file
{                                                               // it didn't work for me so i tried to save them to file as they 
	/*FILE* filep;// creates file to write too                    generated in the makeCard function
	filep = fopen("bingo.txt", "a");// allows user to amend the text file
	if (filep != NULL)
	{
		// prints data to text file
		for (int i = 1; i <= numPlayers; i++)
		{
			fprintf(filep, "Player %d Card \n", i);// print card number
			for (row = 0; row < 3; row++)
			{
				for (col = 0; col < 9; col++)
				{
					fprintf(filep, "%d\t", bingo[row][col]);
				}// for
				fprintf(filep, "\n");
			}// for
			fprintf(filep, "\n");
		}
	}// if
	if (filep != NULL)
	{
		fclose(filep);// closes text file

	}// if*/
}// saveGame
void drawNum(int playOpt)
{
	while (playOpt == 3)
	{
		int numDrawn = rand() % 90 + 1;// generates a number between 1-90
		printf("Number drawn is : %d", numDrawn);
		printf("\nPress 3 to draw another number \n");
		printf("Press 4 to save game & exit \n");
		printf("Option : ");
		scanf("%d", &playOpt);
	}
}// drawNum
