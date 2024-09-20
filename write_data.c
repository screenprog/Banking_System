#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int accno, pin; char name[30]; float balance;
} customer;

main()
{
	FILE *fw, *fr;
	customer c, lastacc;
	char enter;
	fw = fopen("CUSTOME.DAT","a+");
	fr = fopen("CUSTOME.DAT","rb");
	if(fw == NULL)
	{
		printf("File Error");
		exit(1);
	}
	
	while(fread(&lastacc,sizeof(customer),1,fr) == 1);
	

	
	if(lastacc.accno < 100)
	{
		printf("\nEnter Custemor Ac. number : ");
		scanf("%d",&lastacc.accno);
	}
	else
		lastacc.accno++;

	do
	{	
		fflush(stdin);
		do
		{
			printf("\nEnter Custemor Name : ");
			gets(c.name);
		}while(strlen(c.name) < 2);
		
		do
		{
			printf("\nSet a 4 digit account pin : ");
			scanf("%d",&c.pin);
		}while(c.pin < 1000 && c.pin > 9999);
		
		do
		{
			printf("\nEnter Custemor Balance : ");
			scanf("%f",&c.balance);
		}while(c.balance < 100);

		c.accno = lastacc.accno;
		
		fwrite(&c,sizeof(customer),1,fw);
		
		printf("\nTo store more data press y : ");
		enter = getche();
		
		lastacc.accno++;

	}while(enter == 'y');
	
	fclose(fw);
	fclose(fr);
	return 1;

}
