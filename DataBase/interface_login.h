/* written by Jesal Shah */
#include "interface_base.h"
#define TRUE 0
#define FALSE 1
//struct declarations
struct data_login
{
	char username[20],password[7];
};
struct user_login
{
	char username[20],password[7];	
}USER_LOGIN;
char *str_param;
//functions declaration
int engine();
int interface();
int password_login();
int unlock();
//functions
int interface()
{
	int login_flag=TRUE;
	bzero(&USER_LOGIN,sizeof(struct user_login));
	CYAN();
	printf("\n\t\t << Login >>\n\n");
	RESET();
	GREEN();
	printf("   -> Username :: ");
	RESET();
	scanf("%s",USER_LOGIN.username);
	GREEN();
	printf("   -> Password :: ");
	password_login();
	RESET();
	if(strlen(USER_LOGIN.password)==6)
	{
		login_flag=engine();
		if(login_flag==FALSE)
		{
			unlock();
		}
	}
	return login_flag;
}
int engine()
{
	struct data_login DAT_LOGIN;
	FILE *ptr;
	int flag=TRUE,i=0;
	ptr = fopen("base","rb");
	if(ptr==0)
	{
		YELLOW();
		printf(" \t\t >> Database Corrupted\n\n");
		RESET();	
		exit(1);
	}
	while(!feof(ptr))
	{
		bzero(&DAT_LOGIN,sizeof(struct data_login));
		fseek(ptr,sizeof(struct data_login)*i,SEEK_SET);
		fread(&DAT_LOGIN,sizeof(struct data_login),1,ptr);
		if((strncmp(USER_LOGIN.username,DAT_LOGIN.username,strlen(DAT_LOGIN.username))==0) && (strlen(USER_LOGIN.username)==strlen(DAT_LOGIN.username)))
		{
			if(strncmp(USER_LOGIN.password,DAT_LOGIN.password,strlen(DAT_LOGIN.password))==0)
			{
				YELLOW();
				printf("\t\t >> Logging In...\n\n");
				RESET();
				flag=FALSE;
				sleep(1);
				break;
			}
		}
		i++;
	}
	fclose(ptr);
	return flag;
}
int password_login()
{
	char *password_ptr;
	password_ptr = (char *)calloc(6,sizeof(char));
	password_ptr = getpass("");
	memcpy(USER_LOGIN.password,password_ptr,strlen(password_ptr));
}
int unlock()
{
	str_param = (char *)calloc(strlen(USER_LOGIN.username),sizeof(char));
	strncpy(str_param,USER_LOGIN.username,strlen(USER_LOGIN.username));
	interface_base(str_param);
}