/* param01.c */

#include <stdio.h>

int showarray(int *);

int main()
{
	int a[3] = {10, 20, 30};

	showarray(a);

	return 0;
}

int showarray(int x[])
{
	int i;

	for (i = 0; i < 3; i++)
		printf("x[%d] = %d\n", i, x[i]);

	return 0;
}