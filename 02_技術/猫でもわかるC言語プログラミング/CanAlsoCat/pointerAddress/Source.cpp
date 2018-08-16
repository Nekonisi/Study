#include <stdio.h>
#include <stdlib.h>

int main()
{
	char _charArray[10];
	printf("__charArray's Address: %p\n", &_charArray[0]);
	printf("__charArray's Address: %p\n", &_charArray[1]);

	int _intArray[10];
	printf("__intArray's Address: %p\n", &_intArray[0]);
	printf("__intArray's Address: %p\n", &_intArray[1]);

	double _doubleArray[10];
	printf("__doubleArray's Address: %p\n", &_doubleArray[0]);
	printf("__doubleArray's Address: %p\n", &_doubleArray[1]);

	system("pause");
	return 0;
}