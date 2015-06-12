#include <cstdio>

int main()
{
	short s = 67;
	char c = s;
	printf("%c\n", c);

	float f = 7.0;
	short s2 = *(short *)&f;
	printf("%i\n", s2);

	double d = 3.1416;
	char ch = *((char *) &d);
	printf("%c\n", ch);

	short s3 = 45;
	double d2 = *((double *) &s3);
	printf("%f\n", d2);

	return 0;
}
