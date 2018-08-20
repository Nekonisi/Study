/* struct03.c */

#include <stdio.h>

struct Data {
	char name[32];
	int age;
	double bl;
	double bw;
	double bmi;
};

int struct_input(struct Data *);

int main()
{
	struct Data MyData;
	char format[] = "%sさん(%d歳)のプロフィール\n"
		"身長 = %5.1fcm, 体重 = %5.1fkg, BMI = %4.1f\n";
	char buffer[256];

	struct_input(&MyData);
	sprintf(buffer, format,
		MyData.name, MyData.age, MyData.bl, MyData.bw, MyData.bmi);
	printf(buffer);
	printf("%s", MyData.name);
	return 0;
}

int struct_input(struct Data *p)
{
	printf("氏名---");
	gets(p->name);
	printf("年齢---");
	scanf("%d", &p->age);
	printf("身長(cm)---");
	scanf("%lf", &p->bl);
	printf("体重(kg)---");
	scanf("%lf", &p->bw);
	p->bmi = p->bw * 10000.0 / (p->bl * p->bl);	

	return 0;
}



	
