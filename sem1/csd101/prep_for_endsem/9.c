#include <stdio.h>
typedef union details
{
    int age;
    int salary;
    int debt;
    int body_count;
}details;
int main()
{
    details anuran;
    anuran.age=69;
    anuran.salary=100;
    anuran.debt=1;
    anuran.body_count=3;

    details arnab;
    arnab.age=23;
    arnab.salary=100;
    arnab.debt=0;
    arnab.body_count=1;

    printf("for anuran, his age is %d, salary is %d, debt is %d, and body count is %d.\n", anuran.age, anuran.salary, anuran.debt, anuran.body_count);
}