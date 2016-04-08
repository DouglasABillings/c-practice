#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

/* Printing functions */
void printChar(void * n)  { printf("%c " , *((char  *)n)); }
void printInt(void * n)   { printf("%i " , *((int   *)n)); }
void printShort(void * n) { printf("%hi ", *((short *)n)); }
void printLong(void * n)  { printf("%li ", *((long  *)n)); }
void printFloat(void * n) { printf("%f " , *((float *)n)); }


/* Comparison functions */
int compChar(void * a, void * b)  { return *(char  *)a < *(char  *)b ? 1 : 0; }
int compInt(void * a, void * b)   { return *(int   *)a < *(int   *)b ? 1 : 0; }
int compShort(void * a, void * b) { return *(short *)a < *(short *)b ? 1 : 0; }
int compLong(void * a, void * b)  { return *(long  *)a < *(long  *)b ? 1 : 0; }
int compFloat(void * a, void * b) { return *(float *)a < *(float *)b ? 1 : 0; }

/* A generic function for printing arrays */
void
printArray(void * arr, int numElems, size_t size,
           void (*printFunc)(void *))
{
    for (int i = 0; i < numElems; i++)
    {
        printFunc(((char *)arr) + i * size);
    }
    printf("\n");
}

#endif
