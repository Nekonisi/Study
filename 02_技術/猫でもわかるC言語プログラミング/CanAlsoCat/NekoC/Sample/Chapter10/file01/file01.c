/* file01.c */

#include <stdio.h>

int main()
{
	FILE *fp; /*ファイル・ポインタ*/

	/* ファイルを書き込みモードでオープン */
	fp = fopen("test.txt", "w");

	if (fp == NULL) {
		perror("ファイル・オープンに失敗しました\n");
		return -1;
	} else {
		printf("ファイルを正常にオープンしました\n");
	}

	fprintf(fp, "初めてのファイル入出力です。\n");

	/* ファイルのクローズ */
	if (fclose(fp) != 0) {
		perror("ファイルのクローズに失敗しました\n");
	} else {
		printf("ファイルを正常にクローズしました\n");
	}

	return 0;
}

