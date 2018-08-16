#include <stdio.h>
#include <stdlib.h>

int main()
{
	short _short1 = 10;
	short _short2 = -50;

	printf("_short1      = %d\n", _short1);
	printf("_short1 >> 2 = %d\n", _short1 >> 2);
	printf("_short1 << 2 = %d\n", _short1 << 2);

	printf("-----------------------------------\n");

	printf("_short2      = %d\n", _short2);
	/* 左シフトした場合は下位ビットに0が入ってくる。*/
	printf("_short2 >> 1 = %d\n", _short2 >> 1);
	/* 右シフトした場合は上位ビットに符号ビットと同じビットが入ってくる。*/
	printf("_short2 << 1 = %d\n", _short2 << 1);

	system("pause");

	return 0;

}
