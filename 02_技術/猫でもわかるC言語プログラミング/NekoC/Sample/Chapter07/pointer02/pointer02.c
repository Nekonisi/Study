/* pointer02.c */

#include <stdio.h>

int main()
{
	int *pa; /* paにはゴミがはいっている */
    int a;

	pa = &a; /* 変数aのアドレスが代入された */

	*pa = 5; /* aのアドレスに5を代入つまりaに5を代入*/

	printf("*pa = %d\n", *pa);
	printf("a = %d\n", a);
	
	return 0;
}