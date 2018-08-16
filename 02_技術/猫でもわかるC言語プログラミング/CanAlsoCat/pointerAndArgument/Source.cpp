#include <stdio.h>
#include <stdlib.h>

void swap(int, int);
void swap_pointer(int*, int*);

int main(){

	int _int1, _int2;
	_int1 = 10;
	_int2 = 20;

	/* _int1 ‚Æ _int2 ‚ð“ü‚ê‘Ö‚¦‚½‚¢*/
	printf("Œ³ \n");
	printf("_int1 = %d, _int2 = %d \n", _int1, _int2);

	printf("----------------------------------------\n");

	swap(_int1, _int2);
	printf("swap‚ð—˜—p \n");
	printf("_int1 = %d, _int2 = %d \n", _int1, _int2);

	printf("----------------------------------------\n");

	swap_pointer(&_int1, &_int2);
	printf("swap_pointer‚ð—˜—p \n");
	printf("_int1 = %d, _int2 = %d \n", _int1, _int2);

	system("pause");
	return 0;
}

void swap(int value1, int value2){
	int temp;
	temp = value1;
	value1 = value2;
	value2 = temp;
	return;
}

void swap_pointer(int* value1, int* value2){
	int temp;
	temp = *value1;
	*value1 = *value2;
	*value2 = temp;
	return;
}