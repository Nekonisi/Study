#include <stdio.h>
#include <stdlib.h>

int main(){
	char szStr[32];

	printf("szStr = ");
	scanf_s("%s",szStr,32);
	printf("szStr is %s\n", szStr);
	system("pause");
	return 0;
}