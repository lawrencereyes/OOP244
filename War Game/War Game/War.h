#include <iostream>
#include <stdio.h>   
#include <stdlib.h>    
#include <time.h>       


	int iSecret, iGuess;

	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number between 1 and 10: */
	iSecret = rand() % 10 + 1;
