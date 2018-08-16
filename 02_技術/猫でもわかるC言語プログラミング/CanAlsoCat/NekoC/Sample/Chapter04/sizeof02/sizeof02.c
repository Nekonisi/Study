/* sizeof02.c */

#include <stdio.h>

int main()
{
	int a = 10;
	size_t s;

	s = sizeof ++a;

	printf("a = %d\n", a);

	return 0;
}