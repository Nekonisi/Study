/* strcat01.c */

#include <stdio.h>
#include <string.h>

int main()
{
	char name[64], sama[] = "様";

	printf("お名前を入力してください。---");
	gets(name);
	printf("%sですね。お待ちしておりました\n", strcat(name, sama));

	return 0;
}

