/* for03.c */

#include <stdio.h>

int main()
{
	int i, j;

	for (i = 0; i < 4; i++) {
		printf("ŠO‘¤‚Ìfor•¶‚Ì‚P, i = %d\n", i);

		for (j = 0; j < 3; j++) {
			printf("\t“à‘¤‚Ìfor•¶, j = %d\n", j);
		}

		printf("ŠO‘¤‚Ìfor•¶‚Ì‚Q, i = %d\n", i);
	}

	return 0;
}