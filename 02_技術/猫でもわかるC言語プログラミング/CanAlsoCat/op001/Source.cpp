/*upgradeAndDowngrade.c*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int a=10, b=3;
	double c;
	int d1=10;
	double d2=2.35;

	// 10/3=0.3333...
	c = a / b;

	// 出力結果: 3.0000
	printf("int同士の計算だと結果もintになる。\n");
	printf("%d ÷ %d = %f\n", a, b, c);

	// 出力結果: 12.350000
	printf("異なる型で計算を行う時は、大きい型に合わせられる。*格上げ*\n");
	printf("%d + %f = %f\n", d1, d2, d1 + d2);

	system("pause");
	return 0;
}