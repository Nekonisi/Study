/* funcptr02.c */

#include <stdio.h>

int func(int);

int main()
{
	int (*ptr1)(), (*ptr2)();

	ptr1 = main;
	ptr2 = func;

	printf("main関数のアドレス = %p, ptr1 = %p\n", main, ptr1);
	printf("func関数のアドレス = %p, ptr2 = %p\n", func, ptr2);

	return 0;
}

int func(int x)
{
	printf("x = %d\n", x);

	return 0;
}