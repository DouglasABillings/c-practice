#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <assert.h>

#include "util.h"

/* A generic insertion sort */
void
insertionSort(void * arr, int numElems, size_t size,
              int (*compFunc)(void *, void *))
{
    for(int i = 1; i < numElems; i++)
    {
        void * elemMem = malloc(size);
        assert(elemMem != NULL);
        memcpy(elemMem, (char *)arr + i * size, size);

        int j = i - 1;
        while(j >= 0)
        {
            void * lMem = (char *)arr + j * size;
            void * rMem = (char *)arr + (j + 1) * size;

            if(compFunc(elemMem, lMem))
                memcpy(rMem, lMem, size);
            else
                break;

            j--;
        }

        void * dest = (char *)arr + (j + 1) * size;
        memcpy(dest, elemMem, size);
        free(elemMem);
    }
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
    insertionSort(arr, 7, sizeof(int), compInt);
    printArray(arr, 7, sizeof(int), printInt);

    printf("\nLongs:\n");
    printArray(arrL, 7, sizeof(long), printLong);
    insertionSort(arrL, 7, sizeof(long), compLong);
    printArray(arrL, 7, sizeof(long), printLong);

    printf("\nShorts:\n");
    printArray(arrS, 6, sizeof(short), printShort);
    insertionSort(arrS, 6, sizeof(short), compShort);
    printArray(arrS, 6, sizeof(short), printShort);

    printf("\nChars:\n");
    printArray(arrC, 10, sizeof(char), printChar);
    insertionSort(arrC, 10, sizeof(char), compChar);
    printArray(arrC, 10, sizeof(char), printChar);

    printf("\nFloats:\n");
    printArray(arrF, 5, sizeof(float), printFloat);
    insertionSort(arrF, 5, sizeof(float), compFloat);
    printArray(arrF, 5, sizeof(float), printFloat);

    return 0;
}
