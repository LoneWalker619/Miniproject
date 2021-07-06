#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bank.h"
int i,j,pin;
int mainexit;
/*Function to create a new account*/
void new_acc()
{  
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    ac_no:
    system("cls");
    printf("\t\t\t ADD RECORD");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&ad.deposit.m,&ad.deposit.d,&ad.deposit.y);
    printf("\nEnter the account number:");
    scanf("%d",&to_check.account_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&ad.account_no,ad.name,&ad.dob.m,&ad.dob.d,&ad.dob.y,&ad.age,ad.address,ad.aadhar_no,&ad.phone,ad.account_type,&ad.amt,&ad.deposit.m,&ad.deposit.d,&ad.deposit.y)!=EOF)
    {
        if (to_check.account_no==ad.account_no)
            {printf("Account number is already in use!");
               delay(1000000000);
                goto ac_no;

            }
    }
    ad.account_no=to_check.account_no;
    printf("\nEnter the name:");
    scanf("%s",ad.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&ad.dob.m,&ad.dob.d,&ad.dob.y);
    printf("\nEnter the age:");
    scanf("%d",&ad.age);
    printf("\nEnter the address:");
    scanf("%s",ad.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",ad.aadhar_no);
    printf("\nEnter the phone number: ");
    scanf("%lf",&ad.phone);
    printf("\nEnter the amount to deposit:");
    scanf("%f",&ad.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",ad.account_type);
    printf("Enter the upi pin which will be used for further transactions.");
    scanf("%d",&ad.storedpin);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",ad.account_no,ad.name,ad.dob.m,ad.dob.d,ad.dob.y,ad.age,ad.address,ad.aadhar_no,ad.phone,ad.account_type,ad.amt,ad.deposit.m,ad.deposit.d,ad.deposit.y);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&mainexit);
    system("cls");
    if (mainexit==1)
        menu();
    else if(mainexit==0)
            printf("\t\t\t\tThankyou for using online banking management sysytem");
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
