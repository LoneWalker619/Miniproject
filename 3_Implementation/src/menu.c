#include<stdio.h>
#include<stdlib.h>
#include"bank.h"
/*Function to select options to complete the aim*/
void menu(void)
{   int choice;
    system("color b");
    printf("\n\n\t\t\tWELCOME TO ONLINE BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\tWELCOME TO THE MAIN MENU ");
    printf("\n\n\t\t1.Create new account\n\t\t2.For transactions\n\t\t3.Check the details of existing account\n\t\t4.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:transact();
        break;
        case 3:see();
        break;
        case 4:printf("\t\t\t\tThankyou for using online banking management sysytem");
        break;
    }
}
