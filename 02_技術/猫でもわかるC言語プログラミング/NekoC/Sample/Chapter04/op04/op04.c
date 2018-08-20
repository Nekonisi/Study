/* op04.c */

#include <stdio.h>

int main()
{
	double shincho = 1.72, taiju = 65.2;

	printf("BMIは体重(kg)を身長(m)の２乗で割ったものです\n");
	printf("これが25を超えると肥満です\n");
	printf("たとえば身長%4.2fmで体重%4.2fkgの人では\n", shincho, taiju);
	printf("BMI = %4.2f ÷ (%4.2f x %4.2f)で計算します\n", 
		taiju, shincho, shincho);
	printf("その結果は%4.1fでした\n", taiju / (shincho * shincho));

	return 0;
}