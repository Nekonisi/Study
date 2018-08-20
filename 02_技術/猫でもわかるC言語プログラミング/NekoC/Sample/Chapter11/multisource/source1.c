/* source1.c */

#include <stdio.h>

int func1();
int func2();

int a = 100;

int main()
{
	extern char *str;

	printf("‚±‚±‚ÍmainŠÖ”‚Å‚·\na = %d\n", a);
	printf("*str‚àŒ©‚¦‚Ü‚·---%s\n", str);
	func1();
	func2();

	return 0;
}