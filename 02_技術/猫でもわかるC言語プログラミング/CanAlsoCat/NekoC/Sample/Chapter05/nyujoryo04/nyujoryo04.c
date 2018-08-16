/* nyujoryo04.c */

#include <stdio.h>

int main()
{
	int age;
	int is_seito; /*¶“k‚È‚ç1‚»‚¤‚Å‚È‚¢‚È‚ç0*/

	printf("”N—î‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢---");
	scanf("%d", &age);
	printf("u”L‚Å‚àŠw‰€v‚Ì\n¶“k‚³‚ñ‚Å‚·‚©(Yes:1, No:0)---");
	scanf("%d", &is_seito);

	if (age < 6 || is_seito == 1) {
		printf("“üê—¿‚Í–³—¿‚Å‚·\n");
	} else {
		printf("“üê—¿‚Í1000‰~‚Å‚·\n");
	}
	return 0;
}