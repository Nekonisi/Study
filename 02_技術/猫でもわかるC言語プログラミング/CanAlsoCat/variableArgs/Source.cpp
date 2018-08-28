#include <stdio.h>
#include <stdarg.h>

int myfunc(int a, ...);

int main(){
	int wa;

	wa = myfunc(4, 1, 2, 3, 4);
	printf("wa = %d\n", wa);
	wa = myfunc(2, 100, -45);
	printf("wa = %d\n", wa);

	return 0;
}

int myfunc(int x, ...){
	va_list ptr;
	int i, sum = 0;

	va_start(ptr, x);
	for (i = 0; i < x; i++){
		sum += va_arg(ptr, int);
	}
	va_end(ptr);

	return sum;
}