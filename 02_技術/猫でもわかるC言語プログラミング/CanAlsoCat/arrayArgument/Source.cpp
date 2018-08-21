#include <stdio.h>
#include <stdlib.h>

int showName(char **);

int main(){
	char *name[] = {
		"John Nash",
		"Tyler Durden",
		"Marty Macfly",
		"Rasty"
	};

	if (!showName(name) == 0){
		printf("ƒGƒ‰[I");
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}

int showName(char **p){
	int count;
	for (count = 0; count < 4; count++){
		printf("%s\n", p[count]);
	}

	return 0;
}