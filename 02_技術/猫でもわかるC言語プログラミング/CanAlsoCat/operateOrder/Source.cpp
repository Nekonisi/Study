/*operatorOrder.cpp*/

# include <stdio.h>
# include <stdlib.h>

int main()
{
	double height = 1.76, weight = 62.0;

	printf("BMIは体重(kg)を身長(m)の2乗を割ったものですが\n");
	printf("これが25を超えると肥満です\n");
	printf("例えば、身長%4.2fmで体重%4.2fkgの人では\n",height,weight);
	printf("%4.2f ÷ (%4.2f × %4.2f) で計算します。\n",weight,height,height);
	printf("結果は%4.2f でした。\n", weight / (height * height));
	system("pause");

	return 0;
}