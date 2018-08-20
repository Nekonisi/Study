/* continue01.c */

#include <stdio.h>

int main()
{
	int i, j;

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			if (i > j)
				continue;
			printf("%d X %d = %2d\n", i, j, i * j);
		}
		printf("-----------------\n");
		
	}

	return 0;
}

