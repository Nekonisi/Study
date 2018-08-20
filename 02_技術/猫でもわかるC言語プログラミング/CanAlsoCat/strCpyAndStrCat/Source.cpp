#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[] = "ABC";
	strcpy_s(str, "def");
	printf("str is %s\n", str);

	char name[64];
	char honorific[] = "—l";

	printf("What's your name? -> ");
	gets_s(name);
	strcat_s(name, honorific);
	printf("Welcome %s!\n", name);

	system("pause");
	return 0;

}