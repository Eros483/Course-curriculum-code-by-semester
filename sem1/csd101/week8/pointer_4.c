#include <stdio.h>
void func1 (int u, int v); //sort of prototyping the function ig? maybe more productive 
void func2 (int *pu, int *pv);
int main()
{
    int u=1;
    int v=1;
    printf ("before calling func1: u=%d, v=%d\n", u, v);
    func1(u,v);
    printf ("after calling func1: u=%d, v=%d\n", u, v);
    printf ("before calling func2: u=%d, v=%d\n", u, v);
    func2 (&u, &v);
    printf ("after calling func2: u=%d, v=%d\n", u, v);
}
void func1(int u, int v)
{
    u=0;
    v=0;
    printf("within func1: u=%d, v=%d\n", u, v);
    return;
}
void func2(int *pu, int *pv)
{
    *pu=0;
    *pv=0;
    printf("within func2: *pu=%d, *pv=%d\n", *pu, *pv);
    return;
}
