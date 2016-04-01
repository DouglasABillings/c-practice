#include <iostream>

struct Fraction
{
	int num;
	int denom;
};

using namespace std;

int main()
{
	Fraction pi;
	pi.num = 22;
	pi.denom = 7;
	((Fraction *) &(pi.denom))->num = 12; // pi.denom becomes 12
	(*((Fraction *) &(pi.denom))).denom = 33; // 4 bytes after pi.denom becomes 33

	int array[10];
	array[0] = 44;
	array[9] = 100;
	array[5] = 45;

	cout << *(array + 5) << endl; // 45

	int arr[5];
	// _ | _ | _ | 128 | _ //
	arr[3] = 128;
	// _ _ | _ _ | _ _ | 2 128 | _ _ //
	*(((short *) arr) + 6) = 2;
	cout << arr[3] << endl;

	return 0;
}
