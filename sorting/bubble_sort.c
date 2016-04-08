#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#include "util.h"

void
bubbleSort(void * arr, int n, int elemSize,
           int (*compFunc)(void * a, void * b))
{
    int i, s = 1;
    void * t = malloc(elemSize);
    assert(t != NULL);

    while(s)
    {
        s = 0;
        for(i = 1; i < n; i++)
        {
            void * a = (char *)arr + i * elemSize;
            void * b = (char *)arr + (i - 1) * elemSize;
            if(compFunc(a, b))
            {
                memcpy(t, (char *)arr + (i - 1) * elemSize, elemSize);
                memcpy((char *)arr + (i - 1) * elemSize, (char *)arr + i * elemSize, elemSize);
                memcpy((char *)arr + i * elemSize, t, elemSize);
                s = 1;
            }
        }
    }

    free(t);
}

/* Testing */
int main()
{
    int arr[] = { 10, 30, 11, 10, 81, 43, 2 };
    long arrL[] = { 10001, 30, 110, 10, 81, 43, 2 };
    short arrS[] = { 6, 110, 10, 1, 81, 600 };
    char arrC[] = "zxdfgbzuan";
    float arrF[] = { 1.337, 0.012, 3.345, 1000.12, 99.13 };

    printf("Ints:\n");
    printArray(arr, 7, sizeof(int), printInt);
    bubbleSort(arr, 7, sizeof(int), compInt);
    printArray(arr, 7, sizeof(int), printInt);

    printf("\nLongs:\n");
    printArray(arrL, 7, sizeof(long), printLong);
    bubbleSort(arrL, 7, sizeof(long), compLong);
    printArray(arrL, 7, sizeof(long), printLong);

    printf("\nShorts:\n");
    printArray(arrS, 6, sizeof(short), printShort);
    bubbleSort(arrS, 6, sizeof(short), compShort);
    printArray(arrS, 6, sizeof(short), printShort);

    printf("\nChars:\n");
    printArray(arrC, 10, sizeof(char), printChar);
    bubbleSort(arrC, 10, sizeof(char), compChar);
    printArray(arrC, 10, sizeof(char), printChar);

    printf("\nFloats:\n");
    printArray(arrF, 5, sizeof(float), printFloat);
    bubbleSort(arrF, 5, sizeof(float), compFloat);
    printArray(arrF, 5, sizeof(float), printFloat);

    return 0;
}
