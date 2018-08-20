/* string01.c */

#include <stdio.h>

int main()
{
	char *str;

	str = "ABC";
	
	printf("*(str + 0) = '%c', *(str + 1) = '%c', *(str + 2) = '%c'\n",
		*(str + 0), *(str + 1), *(str + 2));
	printf("str[0] = '%c', str[1] = '%c', str[2] = '%c'\n",
		str[0], str[1], str[2]);

	return 0;
}