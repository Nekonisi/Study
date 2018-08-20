/* readfile01x.c */

#include <stdio.h>
#include <string.h> /* strcat関数で必要 */

int main()
{
	FILE *fp;
	char filename[256];
	int c;

	printf("ファイル名(拡張子不要)--");
	gets(filename);
	strcat(filename, ".txt");
	fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("ファイルをオープンできません\n");
		return -1;
	}

	while (fscanf(fp, "%c", &c) != EOF)
		printf("%c", c);

	fclose(fp);
	return 0;
}
