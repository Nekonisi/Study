#define STUDENTNO 5
#define SUBJECTNO 3

#include <stdio.h>
#include <stdlib.h>

int drawline(void);

struct RECORD{
	char name[32];
	int national;
	int mathematics;
	int english;
};

int main(){
	struct RECORD myClass[STUDENTNO] = {
		"田中", 80, 80, 55,
		"佐藤", 75, 90, 70,
		"太田", 50, 45, 30,
		"鈴木", 100, 55, 90,
		"加藤", 60, 85, 35,
	};
	int i, totalSum = 0, subjectSum[SUBJECTNO], studentSum[STUDENTNO];

	for (i = 0; i < SUBJECTNO; i++){
		subjectSum[i] = 0;
	}

	for (i = 0; i < STUDENTNO; i++){
		studentSum[i] = 0;
	}

	for (i = 0; i < STUDENTNO; i++){
		subjectSum[0] += myClass[i].national;
		subjectSum[1] += myClass[i].mathematics;
		subjectSum[2] += myClass[i].english;
	}

	for (i = 0; i < STUDENTNO; i++){
		studentSum[i] = myClass[i].national + myClass[i].mathematics + myClass[i].english;
	}

	for (i = 0; i < STUDENTNO; i++){
		totalSum += studentSum[i];
	}

	printf("**** 成績 ****\n\n");

	printf("%6s\t%6s\t%6s\t%6s\t%6s\n",
		"氏名", "国語", "数学", "英語", "合計");
	drawline();

	for (i = 0; i < STUDENTNO; i++){
		printf("%6s\t%6d\t%6d\t%6d\t%6d\n",
			myClass[i].name, myClass[i].national,
			myClass[i].mathematics, myClass[i].english, studentSum[i]);
	}
	drawline();

	printf("%6s\t%6.1f\t%6.1f\t%6.1f\t%6.1f\n",
		"平均",
		(double)subjectSum[0] / STUDENTNO,
		(double)subjectSum[1] / STUDENTNO,
		(double)subjectSum[2] / STUDENTNO,
		(double)totalSum / STUDENTNO);

	system("pause");
	return 0;
}

int drawline(){
	int i;

	for (i = 0; i < 35; i++){
		printf("-");
	}
	printf("\n");
	return 0;

}