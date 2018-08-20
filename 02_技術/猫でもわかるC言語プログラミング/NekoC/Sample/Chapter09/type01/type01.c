/* type01.c */

#include <stdio.h>

typedef int SEISU;

SEISU main()
{
	SEISU n;

	for (n = 0; n < 10; n++)
		printf("%d, ", n);
	printf("\n");

	return 0;
}