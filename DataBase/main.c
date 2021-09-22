#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "color.h"
#include "login.h"
#include "add_account.h"
int flush();
//main
int main()
{
	int exit=FALSE;
	while(1)
	{
		CLEARSCREEN();
		char choice;
		CYAN();
		printf("\n\n\t\t <|> CJ-DATABASE <|> \n\n");
		RESET();
		GREEN();
		printf("   -> Login   :: 1\n");
		printf("   -> Sign Up :: 2\n");
		printf("   -> Exit    :: 3\n");
		RESET();
		YELLOW();
		printf("   -> Choice  :: ");
		scanf("%c",&choice);
		switch(choice)
		{
			case '1':
				login_main();
				break;
			case '2':
				add_main();
				sleep(1);
				break;
			case '3':
				CYAN();
				printf("\n\t\t <( Exiting )>\n\n");
				RESET();
				sleep(1);
				exit=TRUE;
				break;
			default:
				GREEN();
				printf("\n\t\t Invalid Choice\n\n");
				RESET();
		}
		flush();
		if(exit==TRUE)
		{
			break;
		}
	}
	return 0;
}
int flush()
{
	do
	{
	}while(getchar()!='\n');
}