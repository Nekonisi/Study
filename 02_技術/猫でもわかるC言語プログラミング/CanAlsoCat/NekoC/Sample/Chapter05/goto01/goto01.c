/* goto01.c */

#include <stdio.h>

int main()
{
	int i = 10;

	START:
	if ( i > 0) {
		printf("%2d‰ñ–Ú‚ÌÀs‚Å‚·\n", 11 - i);
		i--;
		goto START;
	}
	return 0;
}
