/* bit01.c */

#include <stdio.h>

int main()
{
	unsigned short a, b;

	a = 1;
	b = 3;

	printf("a & b = %d\n", a & b);
	printf("a | b = %d\n", a | b);
	printf("a ^ b = %d\n", a ^ b);

	return 0;
}