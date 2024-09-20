#include<stdio.h>
#include<stdlib.h>
main()
{
	
	char ch;

	do
	{
		printf("\nPress R to view records");
		printf("\nPress T to make a transaction");
		printf("\nPress D to delete an account");
		printf("\nPress A to add accounts");
		printf("\nPress E to exit");
		printf("\nYour Choice	: ");
		ch = getche();
		Sleep(500);
		switch(ch)
		{
			case 'E':
				case 'e':
					exit(1);
					break;
			
			case 'R':
				case 'r':
					system("view_data");
					break;
			
			case 'T':
				case 't':
					system("transaction_engine");
					break;
					
			case 'A':
				case 'a':
					system("write_data");
					break;
			
			case 'D':
				case 'd':
					system("delete_data");
					break;
					
			default :
				printf("\nWrong Option");
		}
		
	}while(1);
	
	return 1;
}
