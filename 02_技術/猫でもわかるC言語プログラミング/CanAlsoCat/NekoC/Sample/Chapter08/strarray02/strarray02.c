/* strarray03.c */

#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "ABC";

	printf("%s\n", str);
	strcpy(str, "def");
	printf("%s\n", str);

	return 0;
}