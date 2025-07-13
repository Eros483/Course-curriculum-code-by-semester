#include <stdio.h>
struct fun
{
    int x;
    int y;
    char haha;
    float meow;
};
int main()
{
    struct fun s1;
    s1.x=4;
    s1.y=7;
    s1.meow=11.2;
    printf("%d\n", s1.x+s1.y+(int)s1.meow);
}