// mystrCat.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

char *mystrcat(char *str1, char *str2);

int _tmain(int argc, _TCHAR* argv[])
{
	char str1[16] = "abc";
	char str2[16] = "def";

	printf("%s\n", mystrcat(str1, str2));
	return 0;
}

char *mystrcat(char *str1, char *str2){
	char *ptr;
	int n = 0;

	ptr = str1 + strlen(str1);
	while (*(ptr + n) = *(str2 + n)){
		n++;
	}

	return str1;
}

