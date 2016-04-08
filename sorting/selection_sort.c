#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#include "util.h"

void
selectionSort(void * arr, int n, int elemSize,
              int (*compFunc)(void * a, void * b))
{
    int i, j, m;
    void * t = malloc(elemSize);
    assert(t != NULL);

    for(i = 0; i < n; i++)
    {
        m = i;
        for(j = i; j < n; j++)
        {
            void * a = (char *)arr + j * elemSize;
            void * b = (char *)arr + m * elemSize;
            if(compFunc(a, b))
                m = j;
        }
        memcpy(t, (char *)arr + i * elemSize, elemSize);
        memcpy((char *)arr + i * elemSize, (char *)arr + m * elemSize, elemSize);
        memcpy((char *)arr + m * elemSize, t, elemSize);
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
    selectionSort(arr, 7, sizeof(int), compInt);
    printArray(arr, 7, sizeof(int), printInt);

    printf("\nLongs:\n");
    printArray(arrL, 7, sizeof(long), printLong);
    selectionSort(arrL, 7, sizeof(long), compLong);
    printArray(arrL, 7, sizeof(long), printLong);

    printf("\nShorts:\n");
    printArray(arrS, 6, sizeof(short), printShort);
    selectionSort(arrS, 6, sizeof(short), compShort);
    printArray(arrS, 6, sizeof(short), printShort);

    printf("\nChars:\n");
    printArray(arrC, 10, sizeof(char), printChar);
    selectionSort(arrC, 10, sizeof(char), compChar);
    printArray(arrC, 10, sizeof(char), printChar);

    printf("\nFloats:\n");
    printArray(arrF, 5, sizeof(float), printFloat);
    selectionSort(arrF, 5, sizeof(float), compFloat);
    printArray(arrF, 5, sizeof(float), printFloat);

    return 0;
}
