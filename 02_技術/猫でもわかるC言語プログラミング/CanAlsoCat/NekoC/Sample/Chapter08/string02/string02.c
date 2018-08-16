/* string02.c */

#include <stdio.h>

int main()
{
	printf("%c, %c, %c\n", *("ABC" + 0), *("ABC" + 1), *("ABC" + 2));
	printf("%c, %c, %c\n", "ABC"[0], "ABC"[1], "ABC"[2]);

	return 0;
}