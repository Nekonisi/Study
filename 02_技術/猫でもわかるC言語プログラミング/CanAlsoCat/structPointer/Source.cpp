#include <stdio.h>
#include <stdlib.h>

struct Data{
	char name[32];
	int age;
	double height;
	double weight;
	double bmi;
};

int struct_input(struct Data *);

int main(){
	struct Data MyData;
	char format[] = "%sさん(%d歳)のプロフィール\n"
		"身長 = %5.1fcm\t体重 = %5.1fkg\tBMI = %4.1f\n";
	char buffer[256];

	struct_input(&MyData);
	/*sprintf_s: 書式にのっとって変換した出力を文字列に格納する*/
	sprintf_s(buffer, format, MyData.name, MyData.age,
		MyData.height, MyData.weight, MyData.bmi);
	printf(buffer);

	/*ポインタによる参照*/
	struct Data *dataPointer = &MyData;
	printf("\n\n**** ポインタによる参照 *****\n");
	printf("name: %s\n", (*dataPointer).name);
	printf("age: %d\n", (*dataPointer).age);
	printf("height: %4.1f\n", (*dataPointer).height);
	printf("weight: %4.1f\n", (*dataPointer).weight);
	system("pause");
	return 0;
}

int struct_input(struct Data *p){
	printf("氏名---");
	gets_s(p->name);
	printf("年齢---");
	scanf_s("%d", &p->age);
	printf("身長(cm)---");
	scanf_s("%lf", &p->height);
	printf("体重(kg)---");
	scanf_s("%lf", &p->weight);
	p->bmi = p->weight * 10000.0 / (p->height * p->height);

	return 0;
}