#include <stdio.h>
#include <stdlib.h>

int main(){
	char str[64];

	printf("str = ");
	gets_s(str);
	printf("str is %s\n", str);
	system("pause");
	return 0;
}