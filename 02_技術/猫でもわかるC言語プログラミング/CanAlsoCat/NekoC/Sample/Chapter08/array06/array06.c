/* array07.c */

#include <stdio.h>

int main()
{
	int a[5][2] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int i, j;

	/* 各要素の値を確かめる */
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 2; j++) {
			printf("a[%d][%d] = %d\n", i, j, a[i][j]);
		}
	}

	printf("\n");

	/* 各要素のアドレスを確かめる */
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 2; j++) {
			printf("&a[%d][%d] = %p   (a[%d] + %d) = %p\n",
				i, j, &a[i][j], i, j, (a[i] + j));
		}
	}

	printf("\n");

	/* a[m][n]を*(*(a + m) + n)と書けるのか確かめる */

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 2; j++) {
			printf("*(*(a + %d) + %d) = %d\n",
				i, j, *(*(a + i) + j));
		}
	}

	return 0;
}