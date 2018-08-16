/* binary01.c */

#include <stdio.h>

int main()
{
	FILE *fp;
	int a[3] = {1, 2, 3};

	fp = fopen("mybinary.b", "wb");
	if (fp == NULL) {
		perror("ファイルがオープンできません\n");
		return -1;
	}
	fwrite(a, sizeof(int), 3, fp);
	fclose(fp);
	printf("ファイルに書き込みました\n");

	return 0;
}