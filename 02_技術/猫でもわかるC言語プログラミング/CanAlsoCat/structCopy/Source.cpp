#include <stdio.h>
#include <stdlib.h>

int main(){
	struct DATA {
		int x;
		int y;
	} a = { 10, 20 }, b;

	/*copy struct*/
	b = a;

	printf("a's x = %d, a's y = %d\n"
		"b's x = %d, b's y = %d\n"
		, a.x, a.y, b.x, b.y);

	system("pause");
	return 0;
}