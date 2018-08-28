#include <stdio.h>
#include <stdlib.h>

int main(){
	int *pi, no, i;

	printf("いくつの整数値を入力しますか？--");
	scanf_s("%d", &no);
	//pi = (int *)malloc(sizeof(int) *no);
	pi = (int *)malloc(sizeof(int) *no);
	
	if (pi == NULL){
		perror("メモリの確保に失敗しました。");
		return -1;
	}
	for (i = 0; i < no; i++){
		printf("%d個目のデータ---", i + 1);
		scanf_s("%d", pi + i);
	}
	printf("入力されたデータは次の通り\n");
	for (i = 0; i < no; i++){
		printf("No.%d = %d\n", i + 1, *(pi + i));
	}
	free(pi);
	return 0;
}