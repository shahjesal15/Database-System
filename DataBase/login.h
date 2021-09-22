#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "interface_login.h"
#define TRUE 0
#define FALSE 1
int login_main()
{
	CLEARSCREEN();
	if(interface()!=FALSE)
	{
		YELLOW();
		printf("\t\t >> Access denied\n");
		RESET();
		sleep(1);
	}
}
