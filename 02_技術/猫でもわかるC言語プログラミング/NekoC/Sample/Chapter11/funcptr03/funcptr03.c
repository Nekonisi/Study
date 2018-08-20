/* funcptr03.c */

#include <stdio.h>

int main()
{
	int myfunc(char *, char *);
	int (*ptr)();

	ptr = myfunc;

	(*myfunc)("田中", "学生");
	(*ptr)("山田", "会社員");
	myfunc("佐藤", "公務員");

	return 0;
}


int myfunc(char *str1, char *str2)
{
	printf("%sさんは、%sです\n", str1, str2);

	return 0;
}

