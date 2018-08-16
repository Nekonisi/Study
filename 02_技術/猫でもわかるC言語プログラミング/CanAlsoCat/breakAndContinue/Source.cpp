#include <stdio.h>
#include <stdlib.h>

int main()
{
	int outer, inner;

	for (outer = 1; outer < 10; outer++){
		printf("%d ‚Ì’i\n", outer);
		for (inner = 1; inner < 10; inner++){
			if (outer > inner){
				continue;
			}
			printf("%d ~ %d = %2d\n", outer, inner, outer*inner);
		}
		printf("---------------------------------------\n");
	}
	system("pause");
	return 0;
}