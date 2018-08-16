/* sum01.c */

#include <stdio.h>

int main()
{
	/* sum合計点, p点数 */
	int sum = 0, p;

	while (1) {
		printf("点数(999で終了)----");
		scanf("%d", &p);
		if (p == 999)
			break;
		sum = sum + p;
	}

	printf("合計点は%d点です\n", sum);

	return 0;
}

