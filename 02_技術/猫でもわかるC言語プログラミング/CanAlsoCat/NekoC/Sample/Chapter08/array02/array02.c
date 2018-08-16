/* array02.c */

#include <stdio.h>

int main()
{
	int a[] = {1, 2, 100, 50};
	int i;

	for (i = 0; i < 4; i++)
		printf("a[%d] = %d, ", i, a[i]);
	printf("\b\b \b\n");

	return 0;
}