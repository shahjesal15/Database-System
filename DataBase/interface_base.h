/* Created By :: Jesal Shah */
#include "search.h"
#include "print.h"
#include "edit.h"
#define TRUE 0
#define FALSE 1
struct data_base
{
	char name[22];
	long int phone;
}DAT_BASE;
//declarations
int record_no=0;
int clear_stdin();
int interface_base(char *str);
int new_record(char *str);
int list_record(char *str);
int delete_record(char *str);
//functions
int interface_base(char *str)
{
	int flag=FALSE;
	while(flag)
	{	
		clear_stdin();
		record_no=0;
		char temp;
		CLEARSCREEN();
		CYAN();
		printf("\n    Logged In :: %s\n",str);
		RESET();
		list_record(str);
		GREEN();
		printf("   -> New     :: 1\n");
		printf("   -> View    :: 2\n");
		printf("   -> Delete  :: 2\n");
		printf("   -> Edit    :: 3\n");
		printf("   -> Search  :: 4\n");
		printf("   -> Print   :: 5\n");
		printf("   -> Logout  :: 6\n");
		CYAN();
		printf("   -> Input   :: ");
		RESET();
		scanf("%c",&temp);
		switch(temp)
		{
			case '1':
				new_record(str);
				sleep(1);
				break;
			case '2':
				view_record(str);
				break;
			case '3':
				delete_record(str);
				sleep(1);
				break;
			case '4':
				edit_record(str);
				sleep(1);
				break;
			case '5':
				search_record(str);
				break;
			case '6':
				printer(str);
				sleep(1);
				break;
			case '7':
				CYAN();
				printf("\n\n\t\t<( Logging Out )>\n\n");
				RESET();
				sleep(1);
				flag=TRUE;
				break;
			default:
				YELLOW();
				printf("\n\t\t >> Invalid Input \n\n");
				sleep(1);
				RESET();
		}
	}
}
int list_record(char *str)
{
	int i=0;
	FILE *ptr;
	ptr = fopen(str,"ab+");
	YELLOW();
	printf("\n\t\t </> Records </>\n\n");
	RESET();
	GREEN();
	printf("   Sr. | Name                    | Phone              \n\n");
	RESET();
	if(fread(&DAT_BASE,sizeof(struct data_base),1,ptr)==1)
	{
		bzero(&DAT_BASE,sizeof(struct data_base));
		rewind(ptr);
		while(!feof(ptr))
		{	
			fseek(ptr,sizeof(struct data_base)*i,SEEK_SET);	
			if(fread(&DAT_BASE,sizeof(struct data_base),1,ptr)==1)
			{
				record_no++;
				YELLOW();
				printf("   #%d   ",record_no);
				RESET();
				BLUE();
				printf("%s     \t\t\t%ld\n",DAT_BASE.name,DAT_BASE.phone);
				RESET();
				bzero(&DAT_BASE,sizeof(struct data_base));
			}
			i++;
		}
	}
	else
	{
		YELLOW();
		printf("\t >> Nothing to display\n");
	}
	printf("\n\n");
	fclose(ptr);
}
int new_record(char *str)
{
	FILE *ptr;
	ptr =  fopen(str,"ab");
	CYAN();
	printf("\n\n\t <#> New Record <#>\n\n");
	RESET();
	GREEN();
	printf("   -> Name  :: ");
	RESET();
	scanf("%s",DAT_BASE.name);
	GREEN();
	printf("   -> Phone :: ");
	RESET();
	scanf("%ld",&DAT_BASE.phone);
	YELLOW();
	fwrite(&DAT_BASE,sizeof(struct data_base),1,ptr);
	printf("\n\t\t >> Record Saved\n\n");
	RESET();
	fclose(ptr);
}
int delete_record(char *str)
{
	char name[22];
	int seeker=0,flag=TRUE;
	FILE *ptr,*fptr; 
	ptr = fopen(str,"rb");
	fptr = fopen("temp","wb");
	CYAN();
	printf("\n\n\t <</>> Delete Record <</>>\n\n");
	RESET();
	GREEN();
	printf("   -> Name   :: ");
	RESET();
	scanf("%s",name);
	while(fread(&DAT_BASE,sizeof(struct data_base),1,ptr)!=0)
	{
		fseek(ptr,seeker*sizeof(struct data_base),SEEK_SET);
		if(strncmp(name,DAT_BASE.name,strlen(DAT_BASE.name))!=0)
		{
			fwrite(&DAT_BASE,sizeof(struct data_base),1,fptr);
		}
		else
		{
			flag=FALSE;
		}
		bzero(&DAT_BASE,sizeof(struct data_base));
		seeker++;
	}
	fclose(ptr);
	fclose(fptr);
	YELLOW();
	if(flag!=TRUE)
	{
		remove(str);
		rename("temp",str);
		printf("\n\t\t >> Record Deleted\n\n");
	}
	else
	{
		remove("temp");
		printf("\n\t\t >> Record Not Found\n\n");
	}
	RESET();
}
int clear_stdin()
{
	do
	{

	}while(getchar()!='\n');
}