#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *fp;
	char fileName[256];
	int c;

	printf("ファイル名(拡張子不要)-- ");
	gets_s(fileName);
	strcat_s(fileName, ".txt");

	errno_t error;
	error = fopen_s(&fp, fileName, "r");
	if (error != 0){
		perror("ファイルをオープンできませんでした。");
		system("pause");
		return -1;
	}

	while (fscanf_s(fp, "%c", &c) != EOF){
		printf("%c", c);
	}

	fclose(fp);
	system("pause");
	return 0;
}