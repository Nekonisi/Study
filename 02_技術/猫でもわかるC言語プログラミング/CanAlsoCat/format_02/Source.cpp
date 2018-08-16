/*format2.c*/

#include <stdio.h>
#include <float.h>
#include <stdlib.h>

int main(){

	double pai = 3.14159265358979;
	int mon = 2;
	float flt = 1.2f;

	/*•‚“®¬”“_*/
	printf("%5.2hf\n", flt);
	printf("%-5.2hf\n", flt);
	printf("%05.2hf\n", flt);
	printf("%+08.2hf\n", flt);
	printf("%-08.2f\n", flt);

	/*®”*/
	printf("%d\n", mon = 3);
	printf("%05d\n", mon);

	/*‰~ü—¦*/
	printf("%e\n", pai);
	printf("%08.2f\n", pai);
	printf("‰~ü—¦‚Í%f‚Å‚·\n", pai);
	printf("‰~ü—¦‚Í%1f‚Å‚·\n", pai);
	printf("‚à‚¤­‚µÚ‚µ‚¢’l‚Í%10.81f‚Å‚·\n", pai);
	printf("‚à‚¤­‚µÚ‚µ‚¢’l‚Í%15.131f‚Å‚·\n", pai);
	printf("‚à‚¤­‚µÚ‚µ‚¢’l‚Í%20.18f‚Å‚·\n", pai);
	printf("‰~ü—¦‚Í%010.2f\n", pai);
	printf("‰~ü—¦‚Í%-10.2f\n", pai);
	printf("‰~ü—¦‚Í%10.2f\n", pai);
	system("pause");

	return 0;
}
