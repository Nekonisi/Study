/* funcptr04.c */

#define PAI 3.141592653589793

#include <stdio.h>
#include <stdlib.h>

double sankaku();
double daikei();
double en();

int main()
{
	double (*fn[3])() = {sankaku, daikei, en};
	char ret[8];
	int fnno;

	while (1) {
		printf("‚Ç‚Ì–ÊÏ‚ğ‹‚ß‚Ü‚·‚©\n(1:OŠpŒ` 2:‘äŒ` 3:‰~ 0:I—¹)--");
		gets(ret);
		if (ret[0] < '0' || ret[0] > '3') {
			printf("”Ô†‚ª•s³‚Å‚·\n");
			continue;
		}
		ret[1] = '\0';
		fnno = atoi(ret);
		if (fnno == 0)
			break;
		printf("–ÊÏ‚Í%f‚Å‚·\n", (*fn[fnno - 1])());
	}
	return 0;
}

double sankaku()
{
	char str[32];
	double teihen, takasa;

	printf("OŠpŒ`‚Ì–ÊÏ‚ğ‹‚ß‚Ü‚·\n");
	printf("’ê•Ó = ");
	gets(str);
	teihen = atof(str);
	printf("‚‚³ = ");
	gets(str);
	takasa = atof(str);

	return teihen * takasa / 2.0;
}

double daikei()
{
	char str[32];
	double jotei, katei, takasa;

	printf("‘äŒ`‚Ì–ÊÏ‚ğ‹‚ß‚Ü‚·\n");
	printf("ã’ê = ");
	gets(str);
	jotei = atof(str);
	printf("‰º’ê = ");
	gets(str);
	katei = atof(str);
	printf("‚‚³ = ");
	gets(str);
	takasa = atof(str);

	return (jotei + katei) * takasa / 2.0;
}

double en()
{
	char str[32];
	double hankei;

	printf("‰~‚Ì–ÊÏ‚ğ‹‚ß‚Ü‚·\n");
	printf("”¼Œa = ");
	gets(str);
	hankei = atof(str);

	return (hankei * hankei) * PAI;
}


