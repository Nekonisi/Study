#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int argCount;

	if (argc == 1){
		printf("コマンドライン引数がありません。\n");
		system("pause");
		return -1;
	}
	for (argCount = 0; argCount < argc; argCount++){
		printf("argv[%d] is %s\n", argCount, argv[argCount]);
	}
	system("pause");
	return 0;
}