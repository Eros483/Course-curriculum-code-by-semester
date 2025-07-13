#include <stdio.h>
struct customer_details
{
    int customer_account;
    int salary;
    int debt;
    int age;
};
int main()
{
    struct customer_details anuran;
    anuran.customer_account=1;
    anuran.salary=1;
    anuran.debt=100000000;
    anuran.age=69;

    struct customer_details arnab;
    arnab.customer_account=2;
    arnab.salary=100000000;
    arnab.debt=20;
    arnab.age=23;

    printf("anuran has debt: %d while arnab has debt: %d\n", anuran.debt, arnab.debt);
}