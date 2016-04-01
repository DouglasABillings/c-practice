#include<stdio.h>
#include<string.h>

int isPalindrome(char * str, int size)
{
    int count = size - 2;
    int isPali = 1;

    int forward = 0, backward = count;
    while(forward <= count && backward >= 0)
    {
        //printf("Testing %c ==> %c\n", str[forward], str[backward]);
        if(str[forward] != str[backward])
        {
            isPali = 0;
            break;
        }

        forward++;
        backward--;
    }

    return isPali;
}

int main(void)
{
    char str[] = "ogeeseseegod";

    if(isPalindrome(str, sizeof(str)))
    {
        printf("%s is a palindrome!", str);
    }
    else
    {
        printf("%s is not a palindrome!", str);
    }
   
    return 0;
}
