#include <stdio.h>
#include <string.h>
#define EOL '\n'
void palindrome_check(char word[])
{
    int n=strlen(word), i;
    int isPalindrome=1;
    for (i=0; i<n/2; i++)
    {
        if (word[i]==word[n-i-1])
        {
            ;
        }
        else
        {
            isPalindrome=0;
        }
    }
    if (isPalindrome)
    {
        printf ("Chosen word is a palindrome\n");
    }
    else
    {
        printf ("Not a palindrome bitch\n");
    }
}
int main()
{
    printf ("Please enter desired word:\n");
    int c, i=0;
    char word[100];
    c=getchar();
    while (c!=EOL)
    {
        word[i]=c;
        i++;
        c=getchar();
    }
    palindrome_check(word);
}