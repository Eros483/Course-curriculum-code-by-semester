#include <stdio.h>
struct MyStructure{
    int MyNum;
    char MyLetter;
};
int main()
{
    struct MyStructure s1;
    s1.MyNum=13;
    s1.MyLetter='B';
    printf("My Number: %d\n", s1.MyNum);
    printf("My Letter: %c\n", s1.MyLetter);
}