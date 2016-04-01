#include<stdio.h>

void swap(char * i, char * j)
{
    char temp = *i;
    *i = *j;
    *j = temp;
}

void permute(char * str, int i, int length)
{
    if(i == length)
    {
        printf("%s\n", str);
        return;
    }

    for(int j = i; j < length; j++)
    {
        swap(str + i, str + j);
        permute(str, i + 1, length);
        swap(str + i, str + j);
    }
    return;
}

int main()
{
    char str[3] = "cat";

    permute(str, 0, 3);

    return(0);
}
