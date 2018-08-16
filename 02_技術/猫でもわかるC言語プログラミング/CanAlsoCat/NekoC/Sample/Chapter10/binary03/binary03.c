/* binary03.c */

#include <stdio.h>

int main()
{
	FILE *fp;
	int a[3];
	char buf[8];

	memset(buf, '\0', sizeof(buf[8]));

	fp = fopen("binary.b", "rb");
	fread(buf, sizeof(char), 3, fp);
	fread(a, sizeof(int), 3, fp);
	fclose(fp);
	printf("%s, %d, %d, %d\n", buf, a[0], a[1], a[2]);

	return 0;
}