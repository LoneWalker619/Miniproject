/**
 * @bank.h
 * @author Lingala sai poornima(https://github.com/saipoor/miniproject)
 * @brief This program is for including function prototypes.
 * @version 0.1
 * @date 2021-04-014
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#ifndef __BANK_H__
#define __BANK_H__
/**
  *@brief Structure containing details for creting account
  */
struct date{
    int m,d,y;
 };
/**
  *@brief structure containing details required to perform online banking functions
  */
 struct {
    char name[60];
    int account_no,age;
    int storedpin;
    char address[60];
    char aadhar_no[15];
    double phone;
    char account_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
 }ad,to_check,rem,transaction;
/**
  *@brief about calculating interest.
  */
float interest(float t,float amount,int rate);
/**
  *@breif about delay
  */
void delay(int t);
/**
  *@brief about creating new account
  */
void new_acc();
/**
  *@brief about transactions like deposit and withdraw
  */
void transact(void);
/**
  *@brief about displaying the details of exisisting bank account
  */
void see(void);
/**
  *@brief about choosing the any one of above mentioned actions
  */
void menu(void);
#endif

