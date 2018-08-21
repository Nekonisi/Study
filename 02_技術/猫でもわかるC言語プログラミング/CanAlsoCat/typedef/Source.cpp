#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*構造体の宣言*/
typedef struct {
	char name[32];
	char tel[32];
}MYDATA, *LPMYDATA;

/*プロトタイプ宣言*/
int menu();
int rosterInput(LPMYDATA);
int rosterOutput(LPMYDATA);

int main(){
	int mode, repeatFlg = 1;

	/*データの初期化*/
	MYDATA mydata = { "", "" };

	/*ポインタの初期化*/
	LPMYDATA lpMyData = &mydata;

	do {
		mode = menu();

		switch (mode){
		case 1:
			rosterInput(lpMyData);
			break;
		case 2:
			rosterOutput(lpMyData);
			break;
		default:
			repeatFlg = 0;
			break;
		}
	} while (repeatFlg);

	system("pause");
	return 0;
}

int menu(){
	char ret[8];
	printf_s("\n***** MENU *****\n");
	printf_s("1: データ入力\n");
	printf_s("2: データ表示\n");
	printf_s("0: 終了\n");
	printf_s("***************\n");
	printf_s("-----> ");
	gets_s(ret);

	return atoi(ret);
}

int rosterInput(LPMYDATA lpData){
	printf_s("氏名--");
	gets_s(lpData->name);
	printf_s("電話番号--");
	gets_s(lpData->tel);

	return 0;
}

int rosterOutput(LPMYDATA lpData){
	if (!strcmp(lpData->name, "")) {
		printf("データがありません\n");
		return -1;
	}
	printf_s("氏名 -- %s\n", lpData->name);
	printf_s("電話番号 -- %s\n", lpData->tel);

	return 0;
	}