#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bank.h"
/*Function to check details of exisisting account*/
void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Enter account number:");
    scanf("%d",&to_check.account_no);
       while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&ad.account_no,ad.name,&ad.dob.m,&ad.dob.d,&ad.dob.y,&ad.age,ad.address,ad.aadhar_no,&ad.phone,ad.account_type,&ad.amt,&ad.deposit.m,&ad.deposit.d,&ad.deposit.y)!=EOF)
        {
            if(ad.account_no==to_check.account_no)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",ad.account_no,ad.name,ad.dob.m,ad.dob.d,ad.dob.y,ad.age,ad.address,ad.aadhar_no,ad.phone,
                ad.account_type,ad.amt,ad.deposit.m,ad.deposit.d,ad.deposit.y);
                if(strcmp(ad.account_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,ad.amt,rate);
                        printf("\n\nYou will get %.2f as interest on %d/%d/%d",intrst,ad.deposit.m,ad.deposit.d,ad.deposit.y+1);
                    }
                else if(strcmp(ad.account_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,ad.amt,rate);
                        printf("\n\nYou will get %.2f as interest on %d/%d/%d",intrst,ad.deposit.m,ad.deposit.d,ad.deposit.y+2);

                    }
                else if(strcmp(ad.account_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,ad.amt,rate);
                        printf("\n\nYou will get %.2f as interest on %d/%d/%d",intrst,ad.deposit.m,ad.deposit.d,ad.deposit.y+3);

                    }
                 else if(strcmp(ad.account_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,ad.amt,rate);
                        printf("\n\nYou will get %.2f as interest on %d of every month",intrst,ad.deposit.d);

                     }
                 else if(strcmp(ad.account_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
    }
}
