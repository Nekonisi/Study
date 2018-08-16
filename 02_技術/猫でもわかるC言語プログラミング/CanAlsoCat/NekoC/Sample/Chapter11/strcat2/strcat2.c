/* strcat2.c */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

char *strcat2(char *, ...);

int main()
{
	char str1[256] = "今日は、"; /* 十分な領域を確保しておく */
	char *str2 = "よい天気ですが、";
	char *str3 = "明日はどうなるかはわかりません\n";
	strcat2(str1, str2, str3, "");
	printf(str1);

	return 0;
}

char *strcat2(char *p, ...)
{
	va_list ptr;
	char *st;

	/*必須引数がヌル文字の文字列であればすぐに帰る*/
	if (p[0] == '\0') 
		return p;

	/*ヌル文字の文字列を見つけたらループ脱出*/
	va_start(ptr, p);
	while (1) {
		st = va_arg(ptr, char *);
		if (st[0] == '\0')
			break;
		strcat(p, st);
	}
	va_end(ptr);

	return p;
}