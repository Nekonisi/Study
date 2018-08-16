/*cast.c*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int _int1 = 10, _int2 = 4;
	double _double;

	_double = _int1 / _int2;

	printf("%d € %d = %f¥¥¥(1)\n", _int1, _int2, _int1 / _int2);
	printf("%d € %d = %f¥¥¥(2)\n", _int1, _int2, _double);
	printf("%d € %d = %f¥¥¥(3)\n", _int1, _int2, (double)_int1/_int2);

	system("pause");

	return 0;

}