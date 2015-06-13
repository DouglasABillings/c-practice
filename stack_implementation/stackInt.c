#include "stackInt.h"
#include "assert.h"

void stackIntInit(stackInt * s)
{
	s->logLen = 0;
	s->allocLen = 4;
	s->elems = malloc(4 * sizeof(int));
	assert(s->elems != NULL);
}


void stackIntDestroy(stackInt * s)
{
	free(s->elems);
}


void stackIntPush(stackInt * s, int n)
{
	if(s->logLen == s->allocLen)
	{
		s->allocLen *= 2;
		s->elems = realloc(s->elems, s->allocLen * sizeof(int));
		assert(s->elems != NULL);
	}

	s->elems[s->logLen] = n;
	s->logLen++;
}


int stackIntPop(stackInt * s)
{
	assert(s->logLen > 0);
	s->logLen--;
	return s->elems[s->logLen];
}




















