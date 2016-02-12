#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void){

	int dice1, dice2, roll, first_roll, roll_total, run = 1;
	char name[50], ans[50];
	srand((unsigned int)time(NULL));

	printf("\nWelcome to CS0449's Casino!\n");
	printf("Please enter your name:  ");

	scanf("%s", name);

	printf("%s, would you like to play? (play/quit).\n", name);
	scanf("%s", ans);

	// QUITS //
	if(ans[0] == 'q'){
		printf("Okay, have a nice day!!\n");
		return 0;
	}else if(ans[0] != 'p' && ans[0] != 'q'){
		printf("Something went wrong! Please try again if you wanted to play!\n");
		return 0;
	// PLAYS //
	}else if(ans[0] == 'p'){

		strcpy(ans, "yes");

		while(ans[0] == 'y'){

			roll = 1;

			while(run){

				dice1 = rand() % (6 - 1 + 1) + 1;
				dice2 = rand() % (6 - 1 + 1) + 1;

				roll_total = dice1 + dice2;
				printf("\nYou rolled: %i + %i = %i", dice1, dice2, roll_total);

					// HANDLE FIRST ROLL CASES //
					if(run == 1){

						// A WINNING FIRST ROLL //
						if(roll_total == 7 || roll_total == 11){
							printf("\nYou Win!\n");
							run = 0;
						// A LOSING FIRST ROLL //
						}else if(roll_total == 2 || roll_total == 3 || roll_total == 12){
							printf("\nYou Lose!\n");
							run = 0;
						}else{
							printf(" (point)");
							first_roll = roll_total;
							run++;
						}

					// ROLLS FOLLOWING FIRST ROLL//
					}else{	
						// WINNING ROLL //		
						if(roll_total == first_roll){
							printf("\nYou Win!\n");
							run = 0;
						// LOSING ROLL //
						}else if(roll_total == 7){
							printf("\nYou Lose!\n");
							run = 0;
						// ANOTHER ROLL //
						}else{
							run++;
						}
					}		
			}

			printf("\nWould you like to play again? (yes/no)     ");
			scanf("%s", ans);

			if(ans[0] == 'y'){
				run = 1;
			}else if(ans[0] == 'n'){
				run = 0;
			}else if(ans[0] != 'y' && ans[0] != 'n'){
				printf("Response was unclear! Restart program to play again!\n");
				return 0;
			}


		}

		printf("Goodbye, %s.\n\n", name);

	}



return 0;
}



