#include <stdio.h>
#include <stdlib.h>

int main(){
	int outer, inner;

	for (outer = 0; outer < 3; outer++){
			printf(" outer: %d\n", outer);
		for (inner = 2; inner < 7; inner += 2){
			printf("\t inner: %d\n", inner);
		}
	}

	system("pause");
	return 0;

}