
#include <stdio.h>
#include <stdlib.h>

int main(){
	int arrayInt[4] = { 0, 1, 2, 3 };
	int count;

	for (count = 0; count < 4; count++){
		printf("arrayInt[%d] = %p\n", count, &arrayInt[count]);
	}

	printf("arrayInt = %p\n", &arrayInt);
	if ((int*)&arrayInt == &arrayInt[0]){
		printf("arrayInt = arrayInt[0]\n");
	}
	else{
		printf("arrayInt ‚ arrayInt[0]\n");
	}

	system("pause");
	return 0;
}