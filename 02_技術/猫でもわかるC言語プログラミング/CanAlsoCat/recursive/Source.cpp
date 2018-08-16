#include <stdio.h>
#include <stdlib.h>

/*プロトタイプ宣言*/
int factorial(int);

int main()
{
	int count;
	for (count = 1; count < 11; count++){
		printf("%d! = %d \n",count,factorial(count));
	}
	system("pause");
	return 0;
}

int factorial(int value)
{
	if (value == 0){
		return 1;
	}
	else {
		return value * factorial(value - 1);
	}
}