#define PAN "パン食い競争"
#define RUN "100m 競走"
#define NO 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int myinput(LPDATA, char *, char *, char *);

int main(){
	DATA data[NO];
	LPDATA lpdata;
	int i;

	lpdata = data;

	myinput(lpdata + 0, "田中", PAN, "1");
	myinput(lpdata + 1, "佐藤", RUN, "20.5");
	myinput(lpdata + 2, "太田", PAN, "2");
	myinput(lpdata + 3, "加藤", PAN, "4");
	myinput(lpdata + 4, "筒井", RUN, "15.2");
	myinput(lpdata + 5, "鈴木", PAN, "3");

	printf("%4s\t%-14s\t%4s\n"
		, "氏名", "競技名", "成績");
	printf("-------------------------------\n");
	for (i = 0; i < NO; i++){
		printf("%4s\t%-14s\t", data[i].name, data[i].kind);
		if (strcmp(data[i].kind, RUN) == 0){
			printf("%4.1f秒\n", data[i].record.time);
		}
		else{
			printf("%4d位\n", data[i].record.time);
		}
	}
	system("pause");
	return 0;
}

int myinput(LPDATA lpData, char *name, char *kind, char *record){
	strcpy_s(lpData->name, name);
	strcpy_s(lpData->kind, kind);
	if (!strcmp(kind, PAN)){
		lpData->record.rank = atoi(record);
	}
	else{
		lpData->record.time = atof(record);
	}
	return 0;
}
