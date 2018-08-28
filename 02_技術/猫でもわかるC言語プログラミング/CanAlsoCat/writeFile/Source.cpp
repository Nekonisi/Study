#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myWrite(FILE *);

int main(){
	FILE *fp;
	char fileName[256];

	printf("ファイル名(拡張子不要)--- ");
	gets_s(fileName);
	strcat_s(fileName, ".txt"); /*文字列を連結*/

	errno_t error = 0;
	error = fopen_s(&fp, fileName, "a"); /*追加モード*/
	if (fp == NULL){
		perror("ファイルのオープンに失敗しました。\n");
		return -1;
	}
	while (!myWrite(fp));
	fclose(fp);
	system("pause");
	return 0;
}

int myWrite(FILE *file){
	char name[16];
	char tel[16];
	char yesNo[8];

	char *format = "%-15s\t%-15s\n";

	printf("氏名-- ");
	gets_s(name);
	printf("電話-- ");
	gets_s(tel);

	printf(format, name, tel);
	printf("このデータを書き込みますか(y/n): ");
	gets_s(yesNo);
	if (strcmp(yesNo, "Y") == 0 || strcmp(yesNo, "y") == 0){
		fprintf_s(file, format,name,tel);
	} 

	printf("さらにデータを入力しますか？(y/n): ");
	gets_s(yesNo);
	if (strcmp(yesNo, "N") == 0 || (strcmp(yesNo, "n") == 0)){
		return -1;
	}
	return 0;
}