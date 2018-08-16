/* funcptr01.c */

#include <stdio.h>

int func(int);

int main()
{
	printf("main関数のアドレス = %p\n", main);
	printf("func関数のアドレス = %p\n", func);

	return 0;
}

int func(int x)
{
	printf("x = %d\n", x);

	return 0;
}