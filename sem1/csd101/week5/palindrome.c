#include <stdio.h>
#include <string.h>
int main()
{
    char word[1000];
    printf ("Please input word to be checked:\n");
    scanf ("%s", &word);

    int n=strlen(word);
    int isPalindrome=1;
    for (int i=0; i<n/2; i++)
    {
        if (word[i]!=word[n-i-1])
        {
            isPalindrome=0;
            break;
        }
    }
    if (isPalindrome)
    {
        printf ("%s is a palindrome.\n", word);
    }
    else
    {
        printf ("%s is not a palindrome.\n", word);
    }
    return 0;
}