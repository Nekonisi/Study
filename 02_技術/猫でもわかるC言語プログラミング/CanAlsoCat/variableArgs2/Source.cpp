#include <stdio.h>
#include <stdarg.h>
#include <string.h>

char* myfunc(char*, ...);

int main(){

	char str1[256] = "Today is "; /*\•ª‚È—]”’‚ğŠm•Û‚µ‚Ä‚¨‚­*/
	char *str2 = "sunny, but";
	char *str3 = "I don't know what the weather is tommorow\n";
	myfunc(str1, str2, str3,"");
	printf(str1);
	return 0;
}

char* myfunc(char* p, ...){
	va_list ptr;
	char *str;

	if (p[0] == '\0'){
		return p;
	}

	va_start(ptr, p);
	while (1){
		str = va_arg(ptr, char *);
		if (str[0] == '\0'){
			break;
		}
		strcat_s(p, 256,str);
		}
	va_end(ptr);
	return p;
}