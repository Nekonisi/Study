/* recursive02.c */

#include <stdio.h>

int kaijo(int);

int main()
{
	int i;
	for (i = 0; i < 11; i++)
		printf("%d! = %d\n", i, kaijo(i));

	return 0;
}

int kaijo(int n)
{
	if (n == 0)
		return 1;
	else
        return n * kaijo(n - 1);
}
