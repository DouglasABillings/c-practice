#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#include "util.h"

/* A generic quick sort */
void
quicksort(void * arr, int n, size_t size,
          int (*compFunc)(void *, void *))
{
    if(n < 2)
        return;

    int l, r;
    void * pAddr = malloc(size);
    void * tAddr = malloc(size);
    assert(pAddr != NULL && tAddr != NULL);
    memcpy(pAddr, (char *)arr + (n / 2) * size, size);

    for(l = 0, r = n - 1 ;; l++, r--)
    {
        while(compFunc((char *)arr + l * size, pAddr))
            l++;
        while(compFunc(pAddr, (char *)arr + r * size))
            r--;
        if(l >= r)
            break;
        memcpy(tAddr, (char *)arr + l * size, size);
        memcpy((char *)arr + l * size, (char *)arr + r * size, size);
        memcpy((char *)arr + r * size, tAddr, size);
    }

    free(tAddr);
    free(pAddr);

    quicksort(arr, l, size, compFunc);
    quicksort((char *)arr + l * size, n - l, size, compFunc);
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
    quicksort(arr, 7, sizeof(int), compInt);
    printArray(arr, 7, sizeof(int), printInt);

    printf("\nLongs:\n");
    printArray(arrL, 7, sizeof(long), printLong);
    quicksort(arrL, 7, sizeof(long), compLong);
    printArray(arrL, 7, sizeof(long), printLong);

    printf("\nShorts:\n");
    printArray(arrS, 6, sizeof(short), printShort);
    quicksort(arrS, 6, sizeof(short), compShort);
    printArray(arrS, 6, sizeof(short), printShort);

    printf("\nChars:\n");
    printArray(arrC, 10, sizeof(char), printChar);
    quicksort(arrC, 10, sizeof(char), compChar);
    printArray(arrC, 10, sizeof(char), printChar);

    printf("\nFloats:\n");
    printArray(arrF, 5, sizeof(float), printFloat);
    quicksort(arrF, 5, sizeof(float), compFloat);
    printArray(arrF, 5, sizeof(float), printFloat);

    return 0;
}
