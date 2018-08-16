/*sizeOf.c*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*各種変数を宣言*/
	char _char = 'A';
	short _short = 50;
	int _int=10;
	unsigned int _unsignedInt = 128;
	float _float = 0.5f;
	double _double = 2568.2;
	long double _longDouble = 1.258E-25;
	size_t _size_t;

	/*各変数のサイズをsizeof演算子で計測*/

	_size_t = sizeof(_char);
	printf("size of char is %dバイト\n", _size_t);

	_size_t = sizeof(_short);
	printf("size of short is %dバイト\n", _size_t);

	_size_t = sizeof(_int);
	printf("size of int is %dバイト\n", _size_t);

	_size_t = sizeof(_unsignedInt);
	printf("size of unsigned int is %dバイト\n", _size_t);

	_size_t = sizeof(_float);
	printf("size of float is %dバイト\n", _size_t);

	_size_t = sizeof(_double);
	printf("size of double is %dバイト\n", _size_t);

	_size_t = sizeof(_longDouble);
	printf("size of long double is %dバイト\n", _size_t);

	_size_t = sizeof(_size_t);
	printf("size of size_t double is %dバイト\n", _size_t);

	system("pause");

	return 0;

}