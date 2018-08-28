#define RECORDLEN 33

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *fp;
	char fileName[256], data[256], ans[8];
	int no;

	printf("ファイル名(拡張子不要)-- ");
	gets_s(fileName);
	strcat_s(fileName, ".txt");

	errno_t error = fopen_s(&fp, fileName, "r");
	if (error != 0){
		perror("ファイルオープンできませんでした。\n");
		system("pause");
		return -1;
	}

	while(1){
		printf("何人目のデータを読み込みますか？--- ");
		gets_s(ans);
		no = atoi(ans);
		fseek(fp, RECORDLEN *(no-1), SEEK_SET);
		if (fscanf_s(fp, "%s", data) == EOF) {
			perror("読み込みエラーです。\n");
			continue;
		}
		printf("[氏名] %s", data);
		fscanf_s(fp, "%s", data);
		printf("[電話] %s\n", data);
		printf("続けますか(y/n): ");
		gets_s(ans);
		if (strcmp(ans, "n") == 0 || strcmp(ans, "N") == 0){
			break;
		}
	} 
	fclose(fp);

	system("pause");
	return 0;
}