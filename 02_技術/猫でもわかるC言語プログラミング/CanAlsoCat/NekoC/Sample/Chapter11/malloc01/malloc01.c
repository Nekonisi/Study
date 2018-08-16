  /* malloc01.c */

#include <stdio.h>
#include <malloc.h>

int main()
{
	int *pi;

	/* int型1個分のメモリブロックを確保 */
	pi = (int *)malloc(sizeof(int));

	if (pi == NULL) {
		perror("メモリの確保に失敗しました。\n");
		return -1;
	}

	*pi = 100;

	printf("*pi = %d\n", *pi);

	/* 不要になったメモリは解放する */
	free(pi);

	return 0;
}
