/* swap01.c */

#include <stdio.h>

void swap(int, int);

int main()
{
	int a, b;

	a = 10;
	b = 20;

	/* swap関数でaとbの値を入れ替えてもらうことを期待*/
	swap(a, b);

	printf("a = %d, b = %d\n", a, b);

	return 0;
}

void swap(int a, int b)
{
	int c;

	c = b; /* bの値をcに代入 */
	b = a; /* aの値をbに代入 */
	a = c; /* cに入れてあった元のbの値をaに代入 */
	/* これで、aとbの値が入れ替わったはずだが・・・*/
	return;
}
	
	