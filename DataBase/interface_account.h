/* Created by :: Jesal Shah */
#define FALSE 1
#define TRUE 0
//declarations
struct data_account
{
	char username[20],password[7];
};
struct user_account
{
	char username[20],password[7];
}USER_ACCOUNT;
char *str_ptr;
//functions
int interface_account();
int password_account();
int search();
int file_allocator();
//functions
int interface_account()
{
	CYAN();
	printf("\n\n\t\t</> Sign Up </>\n\n");
	RESET();
	GREEN();
	printf("   -> Username :: ");
	RESET();
	scanf("%s",USER_ACCOUNT.username);
	GREEN();
	printf("   -> Password :: ");
	RESET();
	password_account();
	if(search()!=FALSE)
	{
		file_allocator();
	}
	else
	{
		YELLOW();
		printf("\t\t >> Profile Exists\n\n");
		RESET();
	}
}
int password_account()
{
	while(1)
	{
		char *password;
		password = (char *)calloc(6,sizeof(char));
		bzero(password,7);
		password = getpass("");
		if(strlen(password)==6)
		{
			memcpy(USER_ACCOUNT.password,password,6);
			break;
		}
		else
		{
			printf(" >> Renter Password (Length >> 6 characters) :: ");
		}
	}
}
int search()
{
	struct data_account DAT_ACCOUNT;
	int i=0,flag=TRUE;
	FILE *ptr;
	ptr = fopen("base","ab+");
	while(!feof(ptr))
	{
		fseek(ptr,sizeof(struct data_account)*i,SEEK_SET);
		fread(&DAT_ACCOUNT,sizeof(struct data_account),1,ptr);
		if(memcmp(USER_ACCOUNT.username,DAT_ACCOUNT.username,strlen(DAT_ACCOUNT.username))==0)
		{
			flag=FALSE;
		}
		i++;
	}
	fclose(ptr);
	return flag;
}
int file_allocator()
{
	FILE *ptr,*fptr;
	ptr = fopen("base","ab");
	str_ptr = (char *)calloc(strlen(USER_ACCOUNT.username),sizeof(char));
	strncpy(str_ptr,USER_ACCOUNT.username,strlen(USER_ACCOUNT.username));
	fptr = fopen(str_ptr,"wb");
	fseek(ptr,SEEK_END,SEEK_SET);
	fwrite(&USER_ACCOUNT,sizeof(struct user_account),1,ptr);
	YELLOW();
	printf("\t\t >> Profile Created\n\n");
	RESET();
	fclose(ptr);
	fclose(fptr);
}