/* type02.c */

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

	MYDATA mydata = {"", ""};
	LPMYDATA lpMydata = &mydata;

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
	printf("氏名--");
	gets(lpData->name);
	printf("電話番号--");
	gets(lpData->tel);

	return 0;
}

int meibo_output(LPMYDATA lpData)
{
	if (!strcmp(lpData->name, "")) {
		printf("データがありません\n");
		return -1;
	}
	printf("氏名-- %s\n", lpData->name);
	printf("電話番号-- %s\n", lpData->tel);

	return 0;
}
