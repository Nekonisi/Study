/* param02.c */

#include <stdio.h>

int showname(char **);

int main()
{
	char *name[] = {
		"ŒHˆäNF",
		"“c’†—Çˆê",
		"Thomas",
		"ƒGƒWƒ\ƒ“"
	};

	showname(name);

	return 0;
}

int showname(char **p)
{
	int i;

	for (i = 0; i < 4; i++)
		printf("%s\n", p[i]);

	return 0;
}