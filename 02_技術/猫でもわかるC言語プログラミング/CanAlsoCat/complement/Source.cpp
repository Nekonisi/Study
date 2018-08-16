#include <stdio.h>
#include <stdlib.h>

int main(){
	short _short = 10;

	printf("_short =%08X(16êiêî)\n",_short);
	printf("_short =%d(10êiêî)\n",_short);

	printf("----------------------------\n");

	printf("~_short =%08X\n",~_short);
	printf("~_short =%d(10êiêî)\n",~_short);

	system("pause");
	return 0;

}