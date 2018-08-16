/* mystrcat01.c */

#include <stdio.h>

char *mystrcat(char *, char *);

int main()
{
	char str1[16] = "abc";
	char *str2 = "def";

	printf("%s\n", mystrcat(str1, str2));

	return 0;
}

char *mystrcat(char *a, char *b)
{
	char *ptr;
	int n = 0;

	ptr = a + strlen(a);

	while(*(ptr + n) = *(b + n) ) {
		n++;
	}

	return a;
}