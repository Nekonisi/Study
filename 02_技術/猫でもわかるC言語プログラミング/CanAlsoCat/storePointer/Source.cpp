#include <stdio.h>
#include <stdlib.h>

int main(){

	int _int1, _int2;
	int* p_int;

	_int1 = 5;
	_int2 = 10;

	p_int = &_int1;

	printf_s("_int1 = %d, _int2 = %d, *p_int = %d\n", _int1, _int2, *p_int);

	p_int = &_int2;

	printf_s("_int1 = %d, _int2 = %d, *p_int = %d\n", _int1, _int2, *p_int);

	system("pause");
	return 0;
}