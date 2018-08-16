#include <stdio.h>
#include <stdlib.h>

int main(){
	int array[3][2] = {10,20,30,40,50,60};
	int outer, inner;
	
	/************
	格納のされ方
	[10]	[20]
	[30]	[40]
	[50]	[60]
	************/

	printf("\n各要素の値\n");
	for (outer = 0; outer < 3; outer++){
		for (inner = 0; inner < 2; inner++){
			printf("\tarray[%d][%d] = %d",
				outer,inner,array[outer][inner]);
		}
	printf("\n");
	}

	printf("\n各要素のアドレスを確かめる\n");
	for (outer = 0; outer < 3; outer++){
		for (inner = 0; inner < 2; inner++){
			printf("\t&array[%d][%d] = %p\t(array[%d] + %d) = %p\t"
				, outer, inner, &array[outer][inner], outer, inner, (array[outer] + inner));
		}
	printf("\n");
	}

	printf("\narray[m][n]を *(*(a + m) + n)と書けるのか確かめる。\n");
	for (outer = 0; outer < 3; outer++){
		for (inner = 0; inner < 2; inner++){
			printf("\t*(*(array + %d) + %d) = %d\n"
				, outer, inner, *(*(array + outer) + inner));
		}
	}

	system("pause");
	return 0;

}