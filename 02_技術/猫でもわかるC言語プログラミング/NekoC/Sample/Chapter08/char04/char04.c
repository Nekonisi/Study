/* char04.c */

#include <stdio.h>

int main()
{
	int c;

	for (c = 'A'; c <= 'z'; c++) {
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			printf("%c = %3d(0x%X)\n", c, c, c);
	}

	return 0;
}