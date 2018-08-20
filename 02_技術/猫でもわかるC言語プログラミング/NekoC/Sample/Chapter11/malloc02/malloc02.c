/* malloc02.c */

#include <stdio.h>
#include <malloc.h>

int main()
{
	int *pi, no, i;

	printf("何個の整数値を入力しますか--");
	scanf("%d", &no);
	pi = (int *)malloc(sizeof(int) * no);
	if (pi == NULL) {
		perror("メモリ確保に失敗しました\n");
		return -1;
	}
	for(i = 0; i < no; i++) {
		printf("%d個目のデータ---", i + 1);
		scanf("%d", pi + i);
	}
	printf("入力されたデータは次の通りです\n");
	for (i = 0; i < no; i++) 
		printf("No.%d = %d\n", i + 1, *(pi + i));

	free(pi);

	return 0;
}
