#include <stdio.h>
#include <stdlib.h>

int main(){

	int array[] = { 10, 20, 30, 40, 50 }, count, *p;

	p = array;
	for (count = 0; count < 5; count++){
		printf("array[%d] = %d\t&array[%d] = %p\tp + %d = %p\n",count,array[count],count,&array[count],count,p + count );
	}
	system("pause");
	return 0;
}