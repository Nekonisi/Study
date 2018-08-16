/* param03.c */

#include <stdio.h>

int showint(int x[][2]);

int main()
{
	int a[][2] = {1, 2,
		3, 4,
		5, 6,
		7, 8
	};

	showint(a);

	return 0;
}

int showint(int m[][2])
{
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2; j++) {
			printf("m[%d][%d] = %d\n", i, j, m[i][j]);
		}
	}

	return 0;
}