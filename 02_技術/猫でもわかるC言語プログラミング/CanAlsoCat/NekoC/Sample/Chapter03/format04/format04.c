/* format04.c */

#include <stdio.h>
#include <float.h>

int main()
{
	double pai = 3.14159265358979;
	int mon = 2;
	char *str = "abc";
	float flt = 1.2f;

	printf("%5.2hf\n", flt);
	printf("%-5.2f\n", flt);
	printf("%05.2f\n", flt);
	printf("%+08.2f\n", flt);
	printf("%-08.2f\n", flt);

	printf("%d\n", mon = 3);

	printf("%e\n", pai);

	printf("%08.2f\n", pai);
	printf("%05d\n", mon);
	printf("%09s\n", str);

	printf("‰~ü—¦‚Í%f‚Å‚·\n", pai);
	printf("‰~ü—¦‚Í%lf‚Å‚·\n", pai);
	printf("‚à‚¤­‚µÚ‚µ‚¢’l‚Í%10.8lf‚Å‚·\n", pai);
	printf("‚à‚¤­‚µÚ‚µ‚¢’l‚Í%15.13lf‚Å‚·\n", pai);
	printf("‚à‚¤­‚µÚ‚µ‚¢’l‚Í%20.18f‚Å‚·\n", pai);
	printf("‰~ü—¦‚Í%010.2f\n", pai);
	printf("‰~ü—¦‚Í%-10.2f\n", pai);
	printf("‰~ü—¦‚Í%10.2f\n", pai);
	return 0;
}