#include <stdio.h>
#include <stdlib.h>

int main(){

	int _int1;
	/*ポインタ*/
	int *p;
	int *p2;
	/*ポインタのポインタ*/
	int **pp;

	p = &_int1;
	pp = &p;

	**pp = 10;

	printf("******\n");
	printf("値\n");
	printf("******\n");
	printf("_int1 = %d, *p = %d, **pp = %d\n", _int1, *p, **pp);

	printf("******\n");
	printf("アドレス\n", _int1, *p, **pp);
	printf("******\n");
	printf("_int1 = %p, *p = %p, **pp = %p\n", &_int1, &p, &pp);
	system("pause");

	return 0;
}