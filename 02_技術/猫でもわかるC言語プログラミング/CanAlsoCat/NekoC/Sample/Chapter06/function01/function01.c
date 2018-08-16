/* function01.c */

#include <stdio.h>
/* 自作関数のプロトタイプ宣言 */
int func(int, int);

int main()
{
	int a, b, c;

	a = 10;
	b = 20;
	c = func(a, b);

	printf("%d x %d = %d\n", a, b, c);

	return 0;
}

int func(int a, int b)
{
	int c;

	c = a * b;

	return c;
}