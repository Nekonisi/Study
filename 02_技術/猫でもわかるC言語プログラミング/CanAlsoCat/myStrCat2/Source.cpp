#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mystrcat(char* str1, char* str2);

int main(){

	char str1[32] = "Hello, ";
	char str2[16] = "World!\n";

	printf(mystrcat(str1, str2));
	return 0;
}

char *mystrcat(char* str1, char* str2){
	char *aorg;
	aorg = str1;
	while (*str1){
		str1++;
	}
	while (*str1++ = *str2++);

	return aorg;
}