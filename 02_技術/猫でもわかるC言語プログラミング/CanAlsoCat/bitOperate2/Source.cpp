#define CAT 1 /*CATを1と定義*/
#define DOG 2 /*CATを1と定義*/
#define RAT 4 /*CATを1と定義*/
#define RABBIT 8 /*CATを1と定義*/

# include <stdio.h>
# include <stdlib.h>

int main()
{
	int aPet = CAT | DOG; /*Aさんのペット*/
	int bPet = RAT; /*Bさんのペット*/
	int cPet = CAT | DOG | RAT | RABBIT; /*Cさんのペット*/
	int dPet = DOG | RAT; /*Dさんのペット*/

	printf("Aさんのペット(猫=%d, 犬=%d, ネズミ=%d, ウサギ=%d)\n",
		(aPet & CAT) != 0, (aPet & DOG) != 0, (aPet & RAT) != 0, (aPet & RABBIT) != 0);

	printf("Bさんのペット(猫=%d, 犬=%d, ネズミ=%d, ウサギ=%d)\n",
		(bPet & CAT) != 0, (bPet & DOG) != 0, (bPet & RAT) != 0, (bPet & RABBIT) != 0);

	printf("Cさんのペット(猫=%d, 犬=%d, ネズミ=%d, ウサギ=%d)\n",
		(cPet & CAT) != 0, (cPet & DOG) != 0, (cPet & RAT) != 0, (cPet & RABBIT) != 0);

	printf("Dさんのペット(猫=%d, 犬=%d, ネズミ=%d, ウサギ=%d)\n",
		(dPet & CAT) != 0, (dPet & DOG) != 0, (dPet & RAT) != 0, (dPet & RABBIT) != 0);

	system("pause");

	return 0;
}