/* assignmentOperator.c*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a1, a2, a3, a4;

	a1 = 5;
	a1 = a1 + 2;
	printf("----------------------\n");
	printf("a1 = 5;\n");
	printf("a1 = a1 + 2;\n");
	printf("----------------------\n");
	printf("a1 = %d\n", a1);

	a2 = 5;
	a2 += 2;
	printf("----------------------\n");
	printf("a2 = 5;\n");
	printf("a2 += 2;\n");
	printf("----------------------\n");
	printf("a2 = %d\n", a2);

	a3 = 5;
	a3 = a3++ + 2;
	printf("----------------------\n");
	printf("a3 = 5;\n");
	printf("a3 = a3++ + 2;\n");
	printf("----------------------\n");
	printf("a3 = %d\n", a3);

	a4 = 5;
	printf("----------------------\n");
	printf("a4 = 5;\n");
	printf("ï\é¶éûÇ… a4++ + 2 Ç∑ÇÈÅB\n");
	printf("----------------------\n");
	printf("a4 = %d\n", a4++ + 2);

	system("pause");
	return 0;
}