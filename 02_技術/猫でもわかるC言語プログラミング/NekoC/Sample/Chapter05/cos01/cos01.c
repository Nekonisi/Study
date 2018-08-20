/* cos01.c */

#include <stdio.h>
#include <math.h>  /* cos()を使うので必要 */

int main()
{
	int i, j, genbun = 5;
	double rad, cosvalue, pai = 3.14;

	printf("角度\tcos値\tイメージ\n");

	for (i = 0; i < 70; i++)
		printf("-");

	for (i = 90; i >= 0; i -= genbun) {
		rad = (pai * i) / 180;
		cosvalue = cos(rad);
		printf("\n%2d\t%f ", i, cosvalue);
		for (j = 1; j <= (int)(cosvalue * 40); j++)
			printf("*");
	}
	printf("\n");
	return 0;
}
		
