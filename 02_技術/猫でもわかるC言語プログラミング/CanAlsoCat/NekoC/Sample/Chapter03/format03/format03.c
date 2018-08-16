/* format03.c */

#include <stdio.h>

int main()
{
	double a = 0.5, b = 10.5;
	int c = 215, d;
	char e = 'A';


	printf("%f + %f = %f\n", a, b, a + b);
	d = c + 11;
	printf("c‚Ì’l‚Í%d‚Å‚±‚ê‚É11‚ð‰Á‚¦‚é‚Æ%d‚Æ‚È‚è‚Ü‚·\n", c, d);
	printf("e‚É‚Í\"%c\"‚ª‘ã“ü‚³‚ê‚Ä‚¢‚Ü‚·\n", e);

	return 0;
}