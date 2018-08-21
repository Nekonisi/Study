#include <stdio.h>
#include <stdlib.h>

struct DATA{
	char name[32];
	int age;
	double height;
	double weight;
};

int main(){
	struct DATA me = { "Kousuke", 27, 176.0, 61.8 };
	printf("My name is %s, I'm %d years old, I'm %4.1f cm/%4.1f kg\n", me.name, me.age, me.height, me.weight);
	system("pause");
	return 0;
}