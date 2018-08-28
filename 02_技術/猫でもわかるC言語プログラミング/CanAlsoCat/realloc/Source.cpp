#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int main(){
	double *pd, *pd2, sum = 0;
	int no = 0, i;
	char szData[32];

	pd = (double *)malloc(0);
	if (pd == NULL){
		perror("領域確保に失敗\n");
		exit(-1);
	}

	while (1){
		printf("数値を入力してください。(Eで終了): ");
		gets_s(szData);
		if (strcmp(szData, "E") == 0 || strcmp(szData, "e")==0){
			printf("入力を終了します。\n");
			break;
		}

		pd2 = (double *)realloc(pd, sizeof(double) * (no + 1));
		if (pd2 == NULL){
			perror("領域のサイズ変更に失敗しました。\n");
			free(pd); /*すでに確保してあるメモリを解放*/
			exit(-2);
		}
		pd = pd2;
		pd[no] = atof(szData);
		sum += pd[no];
		no++;
	}
	if (no){
		for (i = 0; i < no; i++){
			printf("No.%d %f\n", i + 1, pd[i]);
		}
		printf("合計\t%f\n", sum);
		printf("平均\t%f\n", sum/no);
	}
	free(pd);
	return 0;
}