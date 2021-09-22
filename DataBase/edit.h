/* Created by jesal shah */
struct data_edit
{
	char name[22];
	int phone;
}DATA_EDIT;
//functions
int edit_record(char *str);
//declarations
int edit_record(char *str)
{
	int offset;
	FILE *ptr;
	ptr = fopen(str,"ab");
	CYAN();
	printf("\n\t\t >> Edit Record\n");
	RESET();
	GREEN();
	printf("\n\n   -> Enter the number :: ");
	RESET();
	scanf("%d",&offset);	
	GREEN();
	printf("   -> Name  :: ");
	RESET();
	scanf("%s",DATA_EDIT.name);
	GREEN();
	printf("   -> Phone :: ");
	RESET();
	scanf("%d",&DATA_EDIT.phone);
	fseek(ptr,(offset*sizeof(struct data_edit)),SEEK_SET);
	fwrite(&DATA_EDIT,sizeof(struct data_edit),1,ptr);
	YELLOW();
	printf("\n\n\t\t >> Changes Saved\n\n");
	RESET();
	fclose(ptr);
}