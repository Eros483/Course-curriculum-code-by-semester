#include <stdio.h>
typedef struct structures
{
    int salary;
    int age;
}s;

typedef union unions
{
    int salary;
    int age;
}u;

int main()
{
    s x;
    x.salary=1;
    x.age=2;

    u y;
    y.salary=1;
    y.age=2;

    printf("For structures, %d, %d", x.salary, x.age);
    printf("for unions, %d, %d", y.salary, y.age);
}

