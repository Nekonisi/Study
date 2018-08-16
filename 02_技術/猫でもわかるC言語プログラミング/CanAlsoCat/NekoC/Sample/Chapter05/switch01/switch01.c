/* switch01.c */

#include <stdio.h>

int main()
{
	int n;

	printf("1‚©‚ç5‚Ü‚Å‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B----");
	scanf("%d", &n);

	switch (n) {
		case 1:
			printf("‚ ‚È‚½‚Íˆê”Ô¬‚³‚¢”š‚ğ“ü—Í‚µ‚Ü‚µ‚½‚Ë\n");
			break;
		case 2:
			printf("¡“ú‚Í‚æ‚¢‚±‚Æ‚ª‚ ‚é‚Å‚µ‚å‚¤\n");
			break;
		case 3:
			printf("’†—f‚Ì“¿‚Å‚·\n");
			break;
		case 4:
			printf("‚S‚ÍK‚¹‚Ì‚S\n");
			break;
		case 5:
			printf("‚ ‚È‚½‚Í5‚ğ‘I‚Ñ‚Ü‚µ‚½\n");
			break;
		default:
			printf("1‚©‚ç5‚Ü‚Å‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
			break;
	}

	printf("‚±‚ê‚Å‚¨‚µ‚Ü‚¢‚Å‚·\n");

	return 0;
}
