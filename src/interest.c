#include<stdio.h>
#include"bank.h"
/*Function to calculate simple interest*/
float interest(float t,float amt,int r)
{
    float SI;
    SI=(r*t*amt)/100.0;
    return (SI);

}
