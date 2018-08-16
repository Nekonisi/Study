/*escape.c*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*タブの実験*/
	printf("商品名\t定価\n");
	printf("猫\t100\n");
	printf("犬\t80\n");
	printf("\n");
	/*バックスペースの実験*/
	printf("バックスペースの実験\n");
	printf("ABC\bDEFG\n");
	printf("ABC\b\n");
	printf("\b\n");
	/*ベルの実験*/
	printf("\a");

	system("pause");
	return 0;

}