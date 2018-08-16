/* as01.c */

#include <stdio.h>

int main()
{
	int a1, a2, a3, a4;

	a1 = 5;
	a1 = a1 + 2;
	printf("a1 = %d\n", a1);

	a2 = 5;
	a2 += 2;
	printf("a2 = %d\n", a2);

	a3 = 5;
	a3 = a3++ + 2;
	printf("a3 = %d\n", a3);

	a4 = 5;
	printf("a4 = %d\n", a4++ + 2);

	return 0;
}