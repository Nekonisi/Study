/* structcopy.c */

#include <stdio.h>

int main()
{
	struct DATA {
		int x;
		int y;
	} a = {10, 20}, b;

	/* 構造体のコピー */
	b = a;

	printf("x = %d, y = %d\n", b.x, b.y);

	return 0;
}
