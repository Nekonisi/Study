/* bit03.c */

#define CAT 1
#define DOG 2
#define RAT 4
#define RABBIT 8

#include <stdio.h>

int main()
{
	int a = CAT | DOG;
	int b = RAT;
	int c = CAT | DOG | RAT | RABBIT;
	int d = DOG | RAT;

	printf("Ａさんのペット(猫 = %d, 犬 = %d, ネズミ = %d, ウサギ = %d)\n",
		(a & CAT) != 0, (a & DOG) != 0, (a & RAT) != 0, (a & RABBIT) != 0);
	printf("Ｂさんのペット(猫 = %d, 犬 = %d, ネズミ = %d, ウサギ = %d)\n",
		(b & CAT) != 0, (b & DOG) != 0, (b & RAT) != 0, (b & RABBIT) != 0);
	printf("Ｃさんのペット(猫 = %d, 犬 = %d, ネズミ = %d, ウサギ = %d)\n",
		(c & CAT) != 0, (c & DOG) != 0, (c & RAT) != 0, (c & RABBIT) != 0);
	printf("Ｄさんのペット(猫 = %d, 犬 = %d, ネズミ = %d, ウサギ = %d)\n",
		(d & CAT) != 0, (d & DOG) != 0, (d & RAT) != 0, (d & RABBIT) != 0);

	return 0;
}
