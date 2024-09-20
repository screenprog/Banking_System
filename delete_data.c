#include<conio.h>
#include<stdio.h>
//#include<structure.h>
typedef struct
{
    int accno, pin; char name[30]; float balance;
} customer;

main()
{
	int accdel, accpin, flag = 0;
	customer c;
	FILE *fw, *fr;
	
	printf("\nEnter account no to delete : ");
	scanf("%d",&accdel);
	printf("\nEnter pin : ");
	scanf("%d",&accpin);
	
	fr = fopen("CUSTOME.DAT","rb");
	fw = fopen("TEMP.DAT","wb");
	
	
	while(fread(&c, sizeof(customer), 1, fr) == 1)
	{
		if(c.accno == accdel && c.pin == accpin)
		{
			flag = 1;
			continue;
		}
		fwrite(&c, sizeof(customer), 1, fw);
	}
	
	fclose(fr);
	fclose(fw);
	
	remove("CUSTOME.DAT");
	
    if(flag == 1)
	printf("Deleted successfully");
    else
        printf("Unable to delete the file");

	rename("TEMP.DAT", "CUSTOME.DAT");
	return 1;
	
}
