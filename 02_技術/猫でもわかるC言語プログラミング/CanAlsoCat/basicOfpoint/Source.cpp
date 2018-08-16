#include <stdio.h>
#include <stdlib.h>

int main()
{
	int _int;

	/*ポインタの宣言*/
	int* pointer_int;

	/*ポインタにアドレスを格納*/
	pointer_int = &_int;

	printf("適当な整数値を入力してください--- ");
	scanf_s("%d", &_int);
	printf("----------------------------------------\n");
	printf("_int\n");
	printf("\t_int(アドレス): %p\n", &_int);
	printf("\t_int(値): %d\n", _int);
	printf("----------------------------------------\n");
	printf("pointer_int\n");
	printf("\tpointer_int(アドレス): %p\n", pointer_int);
	printf("\tpointer_int(値): %d\n", *pointer_int);
	printf("----------------------------------------\n");

	system("pause");
	return 0;

}