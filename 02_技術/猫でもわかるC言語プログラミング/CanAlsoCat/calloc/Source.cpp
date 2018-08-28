#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(){
	char *pc;
	pc = (char*)calloc(16, sizeof(char));
	if (pc == NULL){
		perror("メモリの確保に失敗しました。");
		return -1;
	}

	strcpy_s(pc,16, "あいうえお");
	printf("%s\n", pc);

	free(pc);
	return 0;
}