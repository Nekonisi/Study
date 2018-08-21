#include <stdio.h>
#include <stdlib.h>

typedef struct _tagDATA {
	char name[32];
	int age;
	struct _tagDATA *nextdata;
}DATA;

int main(){
	DATA a = { "¬¼", 28 },
		b = { "“c’†", 35 },
		c = { "—é–Ø", 28 };
	DATA *lpdata;

	a.nextdata = &b;
	b.nextdata = &c;
	c.nextdata = NULL;

	for (lpdata = &a; lpdata; lpdata = lpdata->nextdata){
		printf("%s (%dÎ)\n", lpdata->name, lpdata->age);
	}

	system("pause");
	return 0;
}