/* sl01.c */

#include <stdio.h>

int main()
{
	int a;

	a = 5;

	/*正しい*/
	printf(" a < 10は「%d」です\n", a < 10);
	/*正しくない*/
	printf(" a > 10は「%d」です\n", a > 10);

	return 0;
}