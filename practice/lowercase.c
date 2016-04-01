#include <stdio.h>

char * toLowercase(char * str)
{
    int i = 0;
    while(*(str + i) != '\0')
    {
        if(*(str + i) >= 65 && *(str + i) <= 90)
        {
            *(str + i) += 32;
        }
        i++;
    }

    return(str);
}

int main()
{
    printf("%s\n", toLowercase("I AM SAD!"));
}
