/* local01.c */

#include <stdio.h>

int function();

int i = 10;

int main()
{
	int i = 5;
	{
		int i = 3;
		printf("mainŠÖ”‚Ì’†‚ÌƒuƒƒbƒN“à:i = %d\n", i);
	}
	printf("mainŠÖ”“à:i = %d\n", i);
	function();

	return 0;

}

int function()
{
	printf("functionŠÖ”:i = %d\n", i);

	return 0;
}