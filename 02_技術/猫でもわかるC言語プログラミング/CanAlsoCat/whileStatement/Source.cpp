#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum = 0, score = 0, count = 0, endFlg = 0;

	while (endFlg == 0){

		printf("\n999で終了\n");
		printf("%d人目の点数を入力してください: ", count);
		scanf_s("%d", &score);

		if (0 <= score && score <= 100){
			sum += score;
			count++;
		}
		else if (score == 999){
			endFlg = 1;
		}
		else {
			printf("不正な入力です。\n");
		}
	}
	printf("%d 人の点数が入力されました。\n", count);
	printf("平均点は[%5.2f点]です。\n", (double)sum / count);

	system("pause");
	return 0;
}