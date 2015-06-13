#ifndef STACK_H
#define STACK_H

#include <string.h>
#include <stdlib.h>

typedef struct {
	void * elems;
	int elemSize;
	int logLen;
	int allocLen;
} Stack;


void stackInit(Stack * s, int elemSize);
void stackDestroy(Stack * s);
void stackPush(Stack * s, void * nAddr);
void stackPop(Stack * s, void * resAddr);

#endif
