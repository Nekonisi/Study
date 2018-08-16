/* calloc01.c */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
	char *pc;

	pc = (char *)calloc(16, sizeof(char));
	if (pc == NULL) {
		perror("ÉÅÉÇÉäÇÃämï€Ç…é∏îsÇµÇ‹ÇµÇΩ\n");
		return -1;
	}

	strcpy(pc, "Ç†Ç¢Ç§Ç¶Ç®");
	printf("%s\n", pc);

	free(pc);

	return 0;
}