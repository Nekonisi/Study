/* nyujoryo02.c */

#include <stdio.h>

int main()
{
	int age;

	printf("このたびは「猫でもランド」に\nご来園ありがとうございます。\n");
	printf("----------------------------------\n");
	printf("年齢を入力してください---");
	scanf("%d", &age);

	if (age < 6) {
		printf("入場料は無料です\n");
	} else {
		printf("入場料1000円を頂きます\n");
	}
	printf("----------------------------------\n");
	printf("では、ごゆっくりお楽しみください\n");

	return 0;
}