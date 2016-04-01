#include <iostream>
#include <string.h>

struct Student
{
	char * name;
	char suid[8];
	int numUnits;
};

using namespace std;

int main()
{
	Student pupils[4];
	pupils[0].numUnits = 21;
	pupils[2].name = strdup("Adam");
	pupils[3].name = pupils[0].suid + 6;
	strcpy(pupils[1].suid, "40415xx");
	strcpy(pupils[3].name, "123456");
	free(pupils[2].name);
}
