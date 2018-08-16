/* ave02.c */

#include <stdio.h>

int main()
{
	int sum = 0, p = 0, n = 0;

	while (p != 999) {
		printf("点数(999で終了)---");
		scanf("%d", &p);
		if (p != 999) {
			sum = sum + p;
			n++;
		}
	}
	printf("%d人の合計点は%d点です\n", n, sum);
	printf("平均点は%5.1f点です\n", (double)sum / n);

	return 0;
}