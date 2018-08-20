/* sprintf01.c */

#include <stdio.h>

int main()
{
	char buffer[128], name[32];
	int age;
	double bl, bw;

	while (1) {
		printf("氏名---");
		gets(name);
		if (!strcmp(name, "")) {
			printf("氏名が記入されていません\n");
			continue;
		}
		break;
	}
	while (1) {
		printf("年齢---");
		scanf("%d", &age);
		if (age < 0 || age > 150) {
			printf("年齢が不適切です\n");
			continue;
		}
		break;
	}
	while (1) {
		printf("身長(cm)---");
		scanf("%lf", &bl);
		if (bl < 0.0 || bl > 250.0) {
			printf("身長の値が不適切です\n");
			continue;
		}
		break;
	}
	while (1) {
		printf("体重(kg)---");
		scanf("%lf", &bw);
		if (bw < 0.0 || bw > 200.0) {
			printf("体重の値が不適切です\n");
			continue;
		}
		break;
	}
	sprintf(buffer,
		"\n%sさん(年齢は%d歳)のプロフィール\n身長は%5.1fcm、体重%5.1fkgで、BMIは%4.1fです\n",
		name, age, bl, bw, bw * 10000.0 / (bl * bl));
	printf(buffer);

	return 0;
}
				