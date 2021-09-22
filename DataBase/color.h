/*	Color changing header file by Jesal Shah only for linux*/
//color function declarations
int GREEN();
int YELLOW();
int CYAN();
int RESET();
int CLEARSCREEN();
//declarations
int CLEARSCREEN()
{
	printf("\033c");
}
int GREEN()
{
	printf("\033[1;32m");
}
int YELLOW()
{
	printf("\033[1;33m");
}
int CYAN()
{
	printf("\033[1;36m");
}
int RESET()
{
	printf("\033[0m");
}
int BLUE()
{
	printf("\033[1;34m");
}
int RED()
{
	printf("\033[1;31m");
}
int GREY()
{
	printf("\033[1;30m");
}
