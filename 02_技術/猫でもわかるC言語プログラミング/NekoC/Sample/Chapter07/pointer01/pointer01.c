/* pointer01.c */

#include <stdio.h>

int main()
{
	int a;
	int *lpa;

	lpa = &a;

	printf("適当な整数値を入力してください----");
	scanf("%d", &a);

	printf("変数aに%dが代入されました。\n", a);
	printf("変数aのアドレスは%pです。\n", &a);
	printf("変数aを指しているポインタはlpaです\n");
	printf("*lpaの値は%dです。\n", *lpa);

	return 0;
}