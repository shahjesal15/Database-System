/* Created by :: Jesal Shah */
struct data_printer
{
	char name[22];
	long int phone;
}DATA_PRINT;
//functions declarations
int printer(char *str);
//functions
int printer(char *str)
{
	char name[22];
	int phone,record=0;
	FILE *ptr,*printer_ptr;
	ptr = fopen(str,"rb");
	if(fread(&DATA_PRINT,sizeof(struct data_printer),1,ptr)==1)
	{
		rewind(ptr);
		printer_ptr = fopen("output.txt","w");
		fprintf(printer_ptr,"\n\t </> %s </>\n\n  Records :: \n\n",str);
		bzero(&DATA_PRINT,sizeof(struct data_printer));
		while(fread(&DATA_PRINT,sizeof(struct data_printer),1,ptr)==1)
		{
			memcpy(name,DATA_PRINT.name,strlen(DATA_PRINT.name));
			phone = DATA_PRINT.phone;
			fprintf(printer_ptr, "  #%d %s %ld\n",record+1,name,phone);
			bzero(&DATA_PRINT,sizeof(struct data_printer));
			record++;
			fseek(ptr,record*sizeof(struct data_printer),SEEK_SET);
		}
		fclose(printer_ptr);
		fclose(ptr);
		YELLOW();
		printf("\n\t >> Printed\n");
		RESET();
	}
	else
	{
		YELLOW();
		printf("\n\t >> No records found\n");
		RESET();
	}
}
