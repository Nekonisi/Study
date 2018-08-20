/* main01.c */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	if (argc == 1) {
		printf("コマンドライン引数がありません\n");
		return -1;
	}
	for (i = 0; i < argc; i++)
		printf("argv[%d]は「%s」です\n", i, argv[i]);

	return 0;
}
