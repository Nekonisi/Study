/* file02.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mywrite(FILE *);

int main()
{
	FILE *fp;
	char filename[256];

	printf("ファイル名(拡張子不要)--- ");
	gets(filename);
	strcat(filename, ".txt");

	fp = fopen(filename, "a");/*追加モード*/
	if (fp == NULL) {
		perror("ファイルのオープンに失敗しました。\n");
		return -1;
	}
	while (!mywrite(fp)); /* ←この書き方に注意 */

	fclose(fp);
	return 0;
}

int mywrite(FILE *f)
{
	char name[16];
	char tel[16];
	char yesno[8];
	char *format = "%-15s %-15s\n";

	printf("氏名-- ");
	gets(name);
	printf("電話-- ");
	gets(tel);

	printf(format, name, tel);
	printf("このデータを書き込みますか(y/n):");
	gets(yesno);
	if (strcmp(yesno, "Y") == 0 || strcmp(yesno, "y") == 0)
		fprintf(f, format, name, tel);
	
	printf("さらにデータを入力しますか(y/n):");
	gets(yesno);
	if (strcmp(yesno, "N") == 0 || strcmp(yesno, "n") == 0)
		return -1;

	return 0;
}



