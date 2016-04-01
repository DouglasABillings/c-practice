#include <string.h>
#include <iostream>

void swap(void * a, void * b, int size)
{
	char * buffer = new char[size];
	memcpy(buffer, a, size);
	memcpy(a, b, size);
	memcpy(b, buffer, size);
	delete buffer;
}


void * lSearch( void * key, void * base, int n, int elemSize,
		int (*cmpfn) (void *, void *))
{
	for(int i = 0; i < n; i++)
	{
		void * elemAddr = (char *) base + i * elemSize;
		if(cmpfn(key, elemAddr) == 0)
			return elemAddr;
	}

	return NULL;
}


int intCmp(void * a, void * b)
{
	return *((int *) a) - *((int *) b);
}


int doubleCmp(void * a, void * b)
{
	return (int) (*((double *) a) - *((double *) b));
}


int stringCmp(void * a, void * b)
{
	char * s1 = *(char **) a;
	char * s2 = *(char **) b;
	return strcmp(s1, s2);
}


int main()
{
	float a = 1.33, b = 3.14156;
	std::cout << a << ", " << b << std::endl;
	swap(&a, &b, sizeof(float));
	std::cout << a << ", " << b << std::endl;

	char * husband = strdup("Fred");
	char * wife = strdup("Wilma");
	std::cout << husband << ", " << wife << std::endl;
	swap(&husband, &wife, sizeof(char *));
	std::cout << husband << ", " << wife << std::endl;

	int array[] = { 4, 2, 3, 7, 11, 6 };
	int size = 6;
	int number = 7;
	int * found = (int *) lSearch(&number, array, size, sizeof(int), intCmp);
	if(found != NULL)
		std::cout << *found << " at address: " << found << std::endl;
	else
		std::cout << "not found" << std::endl;

	double arrayd[] = { 4.0, 2.0, 3.0, 7.0, 11.0, 6.0 };
	int sized = 6;
	double numberd = 11.0;
	double * foundd = (double *) lSearch(&numberd, arrayd, sized, sizeof(double), doubleCmp);
	if(foundd != NULL)
		std::cout << *foundd << " at address: " << foundd << std::endl;
	else
		std::cout << "not found" << std::endl;

	const char * notes[] = { "Ab", "F#", "B", "Gb", "D" };
	const char * favoriteNote = "Ab";
	char ** foundc = (char **) lSearch(&favoriteNote, notes, 5, sizeof(char *), stringCmp);
	if(foundc != NULL)
		std::cout << *foundc << " at address: " << foundc << std::endl;
	else
		std::cout << "not found" << std::endl;
}
