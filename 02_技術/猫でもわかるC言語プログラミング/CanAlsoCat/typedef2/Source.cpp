#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*構造体の宣言*/
typedef struct{
	char name[32];
	char sex[8];
}MYDATA, *LPMYDATA;

/*プロトタイプ宣言*/
int menu();
int rosterInput(LPMYDATA);
int rosterOutput(LPMYDATA);

int main(){
	int mode, repeatFlg = 1;

	/*配列 ->  連続するメモリの確保の最初のアドレス*/
	MYDATA mydata[10];
	LPMYDATA lpMyData = mydata;

	/*構造体の配列の初期化*/
	memset(mydata, '\0', sizeof(MYDATA[10]));

	do{
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
}

int menu(){
	char mode[8];
	printf("**** モード選択 ****\n"
	"1. 名簿入力\n"
	"2. 名簿出力\n"
	"0. 終了\n"
	"***************\n\n"
	"---------> "
	);
	gets_s(mode);
	return atoi(mode);
}

int rosterInput(LPMYDATA lpData){
	char strNo[8];
	int no;

	printf("何番のデータを入力しますか(0-9)--");
	gets_s(strNo);
	if (strNo[0] < '0' || strNo[0] > '9'){
		printf("入力が不正です。\n\n");
		return -1;
	}
	strNo[1] = '\0';
	no = atoi(strNo);

	printf("氏名--");
	gets_s((lpData + no)->name);
	printf("性別--");
	gets_s((lpData + no)->sex);

	return 0;
}

int rosterOutput(LPMYDATA lpData){
	char strNo[8];
	int no;

	printf("何番のデータを読み出しますか？(0-9)--");
	gets_s(strNo);
	
	if (strNo[0] < '0' || strNo[0] > '9') {
		printf("入力が不正です。\n\n");
		return -1;
	}
	strNo[1] = '\0';
	no = atoi(strNo);

	if (!strcmp((lpData + no)->name, "")){
		printf("データがありません。\n\n");
		return -1;
	}
	printf("氏名-- %s\n", (lpData + no)->name);
	printf("性別-- %s\n\n", (lpData + no)->sex);

	return 0;
}