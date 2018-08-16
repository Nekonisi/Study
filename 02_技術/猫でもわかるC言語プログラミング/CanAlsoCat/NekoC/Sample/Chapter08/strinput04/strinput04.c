/* strinput04.c */

#include <stdio.h>

int main()
{
	char str[64], *s ="•¶Žš—ñ‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢---";

	printf(s);
	while (strcmp(gets(str), "")) {
		printf("“ü—Í‚µ‚½•¶Žš—ñ‚Í%s‚Å‚·‚Ë\n", str);
		printf(s);
	}

	return 0;
}