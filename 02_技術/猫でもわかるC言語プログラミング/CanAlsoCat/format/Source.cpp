/*format.c*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	double a = 0.5, b = 10.5;
	int c = 215, d;
	char e = 'A';

	printf("%f + %f =%f\n", a, b, a + b);
	d = c + 11;
	printf("c is %d, and add 11 then %d\n", c, d);
	printf("e is %c\n", e);
	system("pause");

	return 0;

}