/* readfile02.c */

#include <stdio.h>

int main()
{
	FILE *fp;
	char fname[256];

	int c;

	printf("ファイル名(拡張子不要)---");
	fp = fopen(strcat(gets(fname), ".txt"), "r");

	if (fp == NULL) {
		perror("ファイルがオープンできません\n");
		return -1;
	}
	while ((c = fgetc(fp)) != EOF)
		putc(c, stdout);

	return 0;
}