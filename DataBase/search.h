/* Created by :: Jesal Shah */
#define TRUE 0
#define FALSE 1
struct data_search
{
	char name[22];
	long int phone;
}DAT_SEARCH;
//declarations
int search_record(char *str);
int void_flush();
//functions
int search_record(char *str)
{
	FILE *ptr;
	int seek=0,count=1,flag_search=FALSE;
	char name[22];
	CYAN();
	printf("\n\t\t<?> Search Records <?>\n\n");
	RESET();
	GREEN();
	printf(" >> Enter :: ");
	RESET();
	scanf("%s",name);
	ptr = fopen(str,"rb");
	printf("\n");
	while(!feof(ptr))
	{
		fseek(ptr,seek*sizeof(struct data_search),SEEK_SET);
		if(fread(&DAT_SEARCH,sizeof(struct data_search),1,ptr)==1)
		{
			if(strncmp(name,DAT_SEARCH.name,strlen(name))==0)
			{
				YELLOW();
				printf("   #%d  ",count);
				RESET();
				GREEN();
				printf("%s     \t\t%ld\n",DAT_SEARCH.name,DAT_SEARCH.phone);
				RESET();
				flag_search=TRUE;
				count++;
			}
			seek++;
		}
		bzero(&DAT_SEARCH,sizeof(struct data_search));
	}
	printf("\n");
	if(flag_search!=TRUE)
	{
		YELLOW();
		printf(" >> No records found\n\n");
		RESET();
	}
	GREY();
	printf(" => Press [ENTER] to countinue... ");
	// /void_flush();
	getchar();
	RESET();
	fclose(ptr);
}
int void_flush()
{
	do
	{}while(getchar()!='\n');
}