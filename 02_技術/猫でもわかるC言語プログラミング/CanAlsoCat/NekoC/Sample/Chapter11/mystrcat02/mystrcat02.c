/* mystrcat02.c */

#include <stdio.h>

char *mystrcat(char *, char *);

int main()
{
	char str1[32] = "Hello, ";
	char str2[16] = "World!\n";

	printf(mystrcat(str1, str2));

	return 0;
}

char *mystrcat(char *a, char *b)
{
	char *aorg;

	aorg = a;

	while (*a)
		a++;
	while (*a++ = *b++);

	return aorg;
}