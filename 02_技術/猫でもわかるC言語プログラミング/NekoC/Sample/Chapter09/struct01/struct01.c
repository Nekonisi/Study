/* struct01.c */

#include <stdio.h>

struct Man {
	char name[32];
	int age;
};

int main()
{
	struct Man student;

	strcpy(student.name, "山田太郎");
	student.age = 16;

	printf("生徒の名前は%sです\n", student.name);
	printf("年は%d歳です\n", student.age);

	return 0;
}

