#include "stack.h"
#include <assert.h>


void stackInit(Stack * s, int elemSize)
{
	s->elemSize = elemSize;
	s->logLen = 0;
	s->allocLen = 4;
	s->elems = malloc(4 * elemSize);
	assert(s->elems != NULL);
}


void stackDestroy(Stack * s)
{
	free(s->elems);
}


void stackPush(Stack * s, void * nAddr)
{
	if(s->logLen == s->allocLen)
	{
		s->allocLen *= 2;
		s->elems = realloc(s->elems, (s->allocLen * s->elemSize));
		assert(s->elems != NULL);
	}

	void * source = (char *)s->elems + s->logLen * s->elemSize;
	memcpy(source, nAddr, s->elemSize);
	s->logLen++;
}


void stackPop(Stack * s, void * resAddr)
{
	assert(s->logLen > 0);
	s->logLen--;
	memcpy(resAddr, (char *)s->elems + s->logLen * s->elemSize, s->elemSize);
}
