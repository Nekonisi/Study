/* strinput03.c */

#include <stdio.h>

int main()
{
	char str[64];

	while (1) {
		printf("•¶š—ñ‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢---");
		gets(str);
		if (strcmp(str, "") == 0)
			break;
		printf("“ü—Í‚µ‚½•¶š‚Íu%sv‚Å‚·‚Ë\n", str);
	}

	return 0;
}