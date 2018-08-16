/* string05.c */

#include <string.h>
#include <stdio.h>

int main()
{
	char str[32];
	size_t len;

	printf("•¶Žš—ñ‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢--");
	scanf("%s", str);

	len = strlen(str);

	printf("%s‚Ì’·‚³%d‚Å‚·\n", str, len);

	return 0;
}