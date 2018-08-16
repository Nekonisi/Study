/* type03.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DATA {
	char name[32];
	char tel[32];
} MYDATA, *LPMYDATA;

int menu();
int meibo_input(LPMYDATA);
int meibo_output(LPMYDATA);

int main()
{
	int selectno, loopend = 0;

	MYDATA mydata[10];
	LPMYDATA lpMydata = mydata;

	memset(mydata, '\0', sizeof(MYDATA[10]));

	while (1) {
		selectno = menu();

		switch (selectno) {
			case 1:
				meibo_input(lpMydata);
				break;
			case 2:
				meibo_output(lpMydata);
				break;
			default:
				loopend = 1;
				break;
		}
		if (loopend)
			break;
	}
	return 0;
}

int menu()
{
	char ret[8];

	printf("****** MENU *****\n");
	printf("1:データ入力\n");
	printf("2:データ表示\n");
	printf("0:終了\n");
	printf("*****************\n");
	printf("---->");
	gets(ret);

	return atoi(ret);
}

int meibo_input(LPMYDATA lpData)
{
	char strno[8];
	int no;

	printf("何番のデータを入力しますか(0-9)--");
	gets(strno);
	if (strno[0] < '0' || strno[0] > '9') {
		printf("入力が不正です\n");
		return -1;
	}
	strno[1] = '\0';
	no = atoi(strno);

	printf("氏名--");
	gets((lpData + no)->name);
	printf("電話番号--");
	gets((lpData + no)->tel);

	return 0;
}

int meibo_output(LPMYDATA lpData)
{
	char strno[8];
	int no;

	printf("何番のデータを読み出しますか(0-9)--");
	gets(strno);
	if (strno[0] < '0' || strno[0] > '9') {
		printf("入力が不正です\n");
		return -1;
	}
	strno[1] = '\0';
	no = atoi(strno);

	if (!strcmp((lpData + no)->name, "")) {
		printf("データがありません\n");
		return -1;
	}
	printf("氏名-- %s\n", (lpData + no)->name);
	printf("電話番号-- %s\n", (lpData + no)->tel);

	return 0;
} 
