#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *fp;
	char fileName[256];

	int c;

	printf("ファイル名(拡張子不要)--- ");
	gets_s(fileName);
	strcat_s(fileName, ".txt");
	errno_t error  = fopen_s(&fp, fileName, "r");

	if (error != 0){
		perror("ファイルがオープンできません\n");
		system("pause");
		return -1;
	}

	c = fgetc(fp);

	while (c != EOF){
		putc(c, stdout); //標準出力にcを出力
		c = fgetc(fp);
	}

	system("pause");
	return 0;
}