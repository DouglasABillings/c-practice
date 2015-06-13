#ifndef STACKINT_H
#define STACKINT_H

#include <stdlib.h>

typedef struct {
	int * elems;
	int logLen;
	int allocLen;
} stackInt;

void stackIntInit(stackInt * s);
void stackIntDestroy(stackInt * s);
void stackIntPush(stackInt * s, int n);
int stackIntPop(stackInt * s);

#endif
