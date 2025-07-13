#include <stdio.h>
int main()
{
    int principle, rateofinterestpermonth, timeinmonths, totalinterest, amount;
    principle=25000;
    rateofinterestpermonth=200;
    timeinmonths=24;
    totalinterest=rateofinterestpermonth*timeinmonths;
    amount=principle+totalinterest;
    printf ("The total interest to be paid is %d\n",totalinterest);
    printf ("Kindly repay the total amount of %d\t within a week",amount);
    return 0;
}