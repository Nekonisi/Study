/* array03.c */

#include <stdio.h>

int main()
{
	int a[4] = {1, 2, 3, 4}, i;

	for (i = 0; i < 4; i++) {
		printf("&a[%d] = %p\n", i, &a[i]);
	}
	printf("\na = %p\n", a);
	return 0;
}