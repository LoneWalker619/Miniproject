#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bank.h"
int i,j,pin;
int mainexit;
/*Function to perform Transactions.*/
 void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account number:");
    scanf("%d",&transaction.account_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&ad.account_no,ad.name,&ad.dob.m,&ad.dob.d,&ad.dob.y,&ad.age,ad.address,ad.aadhar_no,&ad.phone,ad.account_type,&ad.amt,&ad.deposit.m,&ad.deposit.d,&ad.deposit.y)!=EOF)
   {

            if(ad.account_no==transaction.account_no)
            {   test=1;
                if(strcmp(ad.account_type,"fixed1")==0||strcmp(ad.account_type,"fixed2")==0||strcmp(ad.account_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    delay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit: ");
                    scanf("%f",&transaction.amt);
                    printf("enter UPI PIN:");
                    scanf("%d",&pin);
                    if(pin==ad.storedpin)
                    {ad.amt+=transaction.amt;
                     fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",ad.account_no,ad.name,ad.dob.m,ad.dob.d,ad.dob.y,ad.age,ad.address,ad.aadhar_no,ad.phone,ad.account_type,ad.amt,ad.deposit.m,ad.deposit.d,ad.deposit.y);
                     printf("\n\nDeposited successfully!");
                    }
                    else{
                        printf("upi pin is wrong amount cannot be deposited.");
                    }
                }
                else
                {
                    printf("Enter the amount you want to withdraw: ");
                    scanf("%f",&transaction.amt);
                    printf("enter UPI PIN:");
                    scanf("%d",&pin);
                    if(pin==ad.storedpin){
                     ad.amt-=transaction.amt;
                     fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",ad.account_no,ad.name,ad.dob.m,ad.dob.d,ad.dob.y,ad.age,ad.address,ad.aadhar_no,ad.phone,ad.account_type,ad.amt,ad.deposit.m,ad.deposit.d,ad.deposit.y);
                     printf("\n\nWithdrawn successfully!");
                    }
                    else{
                        printf("upi pin is wrong amount cannot be withdrawn.");
                    }
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",ad.account_no,ad.name,ad.dob.m,ad.dob.d,ad.dob.y,ad.age,ad.address,ad.aadhar_no,ad.phone,ad.account_type,ad.amt,ad.deposit.m,ad.deposit.d,ad.deposit.y);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&mainexit);
      system("cls");
      if (mainexit==0)
        transact();
    else if (mainexit==1)
        menu();
    else if (mainexit==2)
        printf("\t\t\t\tThankyou for using online banking management sysytem");
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&mainexit);
        system("cls");
        if (mainexit==1)
            menu();
        else
            printf("\t\t\t\tThankyou for using online banking management sysytem");
   }

}
