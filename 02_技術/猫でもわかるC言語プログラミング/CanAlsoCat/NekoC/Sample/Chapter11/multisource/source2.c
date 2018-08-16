/* source2.c */
#include <stdio.h>

extern int a;

int func1()
{
	extern char *str;

	printf("‚±‚±‚ÍAsource2.c‚Ìfunc1ŠÖ”\na = %d\n", a);
	printf("str‚àŒ©‚¦‚Ü‚·---%s\n", str);
	return 0;
}

