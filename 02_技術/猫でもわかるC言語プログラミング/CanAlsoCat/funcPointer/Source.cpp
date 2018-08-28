#include <stdio.h>

int main(){
	int myFunc(char*,char*);//プロトタイプ宣言
	int(*ptr)(char*, char*); // 関数へのポインタ

	ptr = myFunc;

	(*myFunc)("田中", "学生");
	(*ptr)("小西", "会社員");
	myFunc("佐藤", "自衛官");

	return 0;
}

int myFunc(char *str1, char *str2){
	printf("%sさんは、%sです。\n", str1, str2);
	return 0;
}