#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char buffer[128], name[32];
	int age;
	double height, weight;
	int endFlg=1;

	do{
		printf("氏名---");
		gets_s(name);
		if (!strcmp(name, "")){
			printf("氏名が入力されていません。\n");
		}
	} while (!strcmp(name, ""));

	do{
		printf("年齢---");
		scanf_s("%d", &age);
		if (age < 0 || age > 150){
			printf("年齢が不適切です。\n");
		}
	} while (age < 0 || age > 150);

	do{
		printf("身長(cm)---");
		scanf_s("%lf", &height);
		if (height < 0.0 || height > 250.0){
			printf("身長の値が不正です。\n");
		}
	} while (height < 0.0 || height > 250.0);

	do{
		printf("体重(kg)---");
		scanf_s("%lf", &weight);
		if (weight < 0.0 || weight > 200.0){
			printf("体重の値が不正です。\n");
		}
	} while (weight < 0.0 || weight > 200.0);

	sprintf_s(buffer,
		"\n%sさん(年齢は%d歳)のプロフィール\n"
		"身長は%5.1fcm, 体重 %5.1fkgで、BMIは%4.1fです\n",
		name, age, weight, height, weight * 10000.0 / (height * height)
		);
	printf(buffer);

	system("pause");
	return 0;

}