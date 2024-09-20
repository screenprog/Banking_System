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
    FILE *fp,*ft;
    ft=fopen("CUSTOME.DAT","rb");
    fp=fopen("TRANSACTIONS.DAT","rb");
    if (fp==NULL)
    {
        printf("Cant open tfile\n");
        exit(1);

    }
    if (ft==NULL)
    {
        printf("Cant open cfile\n");
        exit(2);

    }
    struct trans c;
    struct customer t;
    printf("\nTransaction History\n");
    while (fread(&c,sizeof(struct trans),1,fp)==1)
    {
        printf("%-20d%-20c%-20f\n",c.accno,c.trans_type,c.amount);
    }
    printf("\nCustomer's record\n");


    while (fread(&t,sizeof(struct customer),1,ft)==1)
    {
        printf("%-20d%-20s%-20f\n",t.accno,t.name,t.balance);
    }
    
 
   
    fclose(ft);
    fclose(fp);
    return 0;
}
