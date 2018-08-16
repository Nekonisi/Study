/* array08.c */

#define NO 3  /* NOを3と定義 */

#include <stdio.h>

int main()
{
	int point[][2] = {
		80, 80, 	/* 出席番号1の英語、数学の得点 */
		100, 98,	/* 出席番号2 */
		60, 80, 	/* 出席番号3 */
	};

	int i, j, sum = 0, p_sum[NO];
	double ave;

	/* 英語の平均点を求める */
	for (i = 0; i < NO; i++)
		sum += point[i][0];
	ave = (double)sum / NO;

	printf("英語の平均点は%5.1f点です\n", ave);

	/* 数学の平均点を求める */
	sum = 0; /*合計点を0にもどしておく */
	for (i = 0; i < NO; i++)
		sum += point[i][1];
	ave = (double)sum / NO;

	printf("数学の平均点は%5.1f点です\n\n", ave);
	
	/* 個人別合計点を求める */
	for (i = 0; i < NO; i++)
		p_sum[i] = 0;

	for (i = 0; i < NO; i++) {
		for (j = 0; j < 2; j++) {
			p_sum[i] += point[i][j];
		}
		printf("出席番号%dの総得点 %d\n", i + 1, p_sum[i]);
	}

	return 0;
}
