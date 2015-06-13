#include <stdio.h>
#include "stack.h"

int main()
{
	Stack s;
	stackInit(&s, sizeof(double));
	double p[] = { 2.12, 1.337, 3.145, 2.0, 8.0, 10.0, 217.0 };
	for(int i = 0; i < 7; i++)
		stackPush(&s, p + i);

	printf("length: %d\n", s.logLen);
	for(int i = 0; i< s.logLen; i++)
	{
		double temp = *((double *) ((char *)s.elems + i * s.elemSize));
		printf("%f\n", temp);
	}

	double res;
	stackPop(&s, &res);
	printf("POP! %f\n", res);

	printf("length: %d\n", s.logLen);
	for(int i = 0; i< s.logLen; i++)
	{
		double temp = *((double *) ((char *)s.elems + i * s.elemSize));
		printf("%f\n", temp);
	}
	
	stackDestroy(&s);
	
	return 0;
}
