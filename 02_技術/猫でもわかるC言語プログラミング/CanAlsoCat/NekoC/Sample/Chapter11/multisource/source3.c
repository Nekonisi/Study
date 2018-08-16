/* source3.c */

#include <stdio.h>

int func2()
{
	extern int a;
	extern char *str;  /*¥¥¥¥¥(1)*/

	printf("‚±‚±‚ÍAsource3.c‚Ìfunc2ŠÖ”‚Å‚·\na = %d\n", a);
	printf("%s\n", str);	 /* (1)‚ª–³‚¢‚ÆƒGƒ‰[‚Æ‚È‚é */
	return 0;
}

char *str = "abc";