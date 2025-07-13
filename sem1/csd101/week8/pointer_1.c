#include <stdio.h>
int main()
{
int u=3, v, *pu, *pv;
pu=&u;
v=*pu;
pv=&v;
printf("u=%d &u=%p pu=%p *pu=%d\n", u, &u, pu, *pu);
printf("v=%d &v=%p pv=%p *pv=%d\n", v, &v, pv, *pv);
}