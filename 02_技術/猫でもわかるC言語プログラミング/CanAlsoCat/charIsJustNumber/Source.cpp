#include <stdio.h>
#include <stdlib.h>

int main(){

	char _char;

	for (_char = '!'; _char <= '~'; _char++){
		printf("\t%3d(0x%2X) -- %c",
			_char, _char, _char);

		if ((_char - 'i' + 1) % 4 == 0){
			printf("\n");
		}
	}
	printf("\n");
		system("pause");
		return 0;
}