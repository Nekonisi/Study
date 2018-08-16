#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* 終端はおわりましたよ合図*/
	char charArray[6] = { 'a', 'b', 'c','d','e','\0'};
	int intArray[6] = {1,2,3,4,5,6};

	char* pCharArray = NULL;
	int* pIntArray = NULL;

	/* ポインタに配列先頭アドレスを割り当てる*/
	pCharArray = &charArray[0];
	pIntArray = &intArray[0];

	/* 下記コードを有効にするとバッファオーバーランする*/
	//char charArray[6] = { 'a', 'b', 'c','d','e','f'};

	printf("%s\n", charArray);

	/* ポインタをひとつの領域としてアクセス(char型でアクセス)*/
	int i = 0;
	for (i = 0; i < 6; i++){
		printf("%c", *(pCharArray+i));
	}
	printf("\n");

	/* ポインタの領域を全体をアクセス(文字列としてアクセス)*/
	char _char;
	int _size = sizeof(pCharArray)/sizeof(pCharArray[0]);
	printf("%s\n", pCharArray);
	printf("CharArrayのサイズ: %d\n", _size);

	/* %sは文字列のためエラーになる。*/
	//printf("%s\n", *pCharArray);
	printf("%d\n", *(pIntArray));
	printf("%d\n", *(pIntArray+1));
	printf("%x\n", pIntArray);
	system("pause");
	return 0;

}