#include<stdio.h>
#include<stdlib.h>
struct customer
{
    int accno, pin; char name[30]; float balance;
};

struct trans
{
    int accno, pin; char trans_type; float amount;
};

int main()
{
    FILE *fc,*ft;
    fc=fopen("CUSTOME.DAT","rb+");
    ft=fopen("TRANSACTIONS.DAT","a+");
    if(fc==NULL)
    {
        printf("\nCant open customer file\n");
        exit(0);
    }
    if(ft==NULL)
    {
        printf("\nCant open transaction file\n");
        exit(0);
    }
    struct customer c;
    struct trans t;
    int scus,strans;
    scus=sizeof(struct customer);
    strans=sizeof(struct trans);
    char another;
    do
    {
        printf("\nEnter the account no\n");
        scanf("%d",&t.accno);
        while(getchar()!='\n');
        printf("Enter the transaction type D for deposit and W for withdrawl\n");
        scanf("%c",&t.trans_type);
        while(getchar()!='\n');
        if(t.trans_type=='D')
        {
            printf("Enter the amount to be deposited\n");
            scanf("%f",&t.amount);
            while(getchar()!='\n');
            rewind(fc);

            while(fread(&c,scus,1,fc)==1)
            {
               if(c.accno==t.accno)
               {
                    fseek(fc,-scus,SEEK_CUR);
                    c.balance=c.balance+t.amount;
                    fwrite(&c,scus,1,fc);
                    fwrite(&t,strans,1,ft);
                    break;
                }
               
            }
            
        }
        else if(t.trans_type=='W')
        {
        	printf("\n Enter pin : ");
        	scanf("%d",&t.pin);
            printf("Enter the amount to be withdrawn\n");
            scanf("%f",&t.amount);
            while(getchar()!='\n');
            rewind(fc);
            while (fread(&c,scus,1,fc)==1)
            {
            	if(c.accno==t.accno && c.pin == t.pin)
            	{
                    fseek(fc,-scus,SEEK_CUR);
                    if((c.balance-t.amount)<100)
                    {
                        printf("Insufficient balance\n");
                        break;
                    }
                    else
                    {
                        c.balance=c.balance-t.amount;
                        fwrite(&c,scus,1,fc);
                        fwrite(&t,strans,1,ft);
                        break;
                        
                    }

                }
               
            }
            
            
        }

        printf("Enter another transaction(y/n)\n");
        scanf("%c",&another);
        while(getchar()!='\n');
    
    }while(another=='y');

    
       
        
    fclose(fc);
    fclose(ft);
     return 0;
}
