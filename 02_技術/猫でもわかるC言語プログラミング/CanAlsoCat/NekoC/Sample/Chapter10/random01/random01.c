/* random01.c */

#define RECORDLEN 33

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char fname[256], data[16], ans[8];
	int no;

	printf("ファイル名(拡張子不要)--");
	fp = fopen(strcat(gets(fname), ".txt"), "r");
	if (fp == NULL) {
		perror("ファイルがオープンできません\n");
		return -1;
	}
	while (1) {
		printf("何人目のデータを読み込みますか---");
		gets(ans);
		no = atoi(ans);
		fseek(fp, RECORDLEN * (no - 1), SEEK_SET);
		if (fscanf(fp, "%s", data) == EOF) {
			perror("読み込みエラーです\n");
			continue;
		}
		printf("[氏名] %s", data);
		fscanf(fp, "%s", data);
		printf("[電話] %s\n", data);
		printf("続けますか(y/n): ");
		gets(ans);
		if (strcmp(ans, "n") == 0 || strcmp(ans, "N") == 0)
			break;
	}

	fclose(fp);

	return 0;
}