/* recursive01.c */

#include <stdio.h>

int main()
{
	static int i = 1;

	if (i <= 10) {
		printf("i = %d\n", i);
		i++;
		main();
	}
	return 0;
}