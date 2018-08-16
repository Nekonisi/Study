/*bitOperate.c*/

#include <stdio.h>
#include <stdlib.h>

int main(){

	unsigned short a, b;

	a= 1;
	b = 3;

	printf("-----------------------------\n");
	printf(" a      = 0000 0000 0000 0001\n");
	printf(" b      = 0000 0000 0000 0011\n");
	printf(" a & b  = 0000 0000 0000 0001\n");
	printf("-----------------------------\n");
	printf("êœ a & b = %d\n", a & b);
	printf("\n\n");


	printf("-----------------------------\n");
	printf(" a      = 0000 0000 0000 0001\n");
	printf(" b      = 0000 0000 0000 0011\n");
	printf(" a | b  = 0000 0000 0000 0011\n");
	printf("-----------------------------\n");
	printf("òa a | b = %d\n", a | b);
	printf("\n\n");


	printf("-----------------------------\n");
	printf(" a      = 0000 0000 0000 0001\n");
	printf(" b      = 0000 0000 0000 0011\n");
	printf(" a ^ b  = 0000 0000 0000 0010\n");
	printf("-----------------------------\n");
	printf("ç∑ a ^ b = %d\n", a ^ b);
	printf("\n\n");

	system("pause");
	return 0;
}