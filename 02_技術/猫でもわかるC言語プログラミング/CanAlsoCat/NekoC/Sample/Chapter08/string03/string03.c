/* string04.c */

#include <stdio.h>
#include <string.h> /* strcmp関数を使うので必要 */

int main()
{
	char str1[32], str2[32];
	int cmp;

	printf("str1を入力してください--");
	scanf("%s", str1);
	printf("str2を入力してください--");
	scanf("%s", str2);

	cmp = strcmp(str1, str2);
	if (cmp < 0)
		printf("%sは、%sより前にあります\n", str1, str2);
	else if (cmp > 0)
		printf("%sは、%sより後ろにあります\n", str1, str2);
	else
		printf("%sと%sは、同じ文字列です\n", str1, str2);

	return 0;
}