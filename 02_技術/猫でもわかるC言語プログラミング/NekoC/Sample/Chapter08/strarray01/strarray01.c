/* strarray02.c */

#include <stdio.h>

int main()
{
	char str[] = "ABC";

	printf("%s\n", str);

	str[0] = 'd';
	str[1] = 'e';
	str[2] = 'f';
	/* str[3]‚Í‚à‚Æ‚à‚Æ'\0'‚È‚Ì‚Å‘Š·‚¦‚é•K—v‚È‚µ */

	printf("%s\n", str);

	return 0;
}