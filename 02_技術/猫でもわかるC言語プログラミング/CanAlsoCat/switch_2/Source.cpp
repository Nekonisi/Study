#include <stdio.h>
#include <stdlib.h>

int main(){
	int choise;

	/*終了フラグ*/
	int endFlg = 0;

	while (1){
		printf("********** Menu **********\n");
		printf("A: ゲーム\n");
		printf("B: 音楽\n");
		printf("C: 表計算\n");
		printf("X: 終了\n");
		printf("*************************\n");
		printf("-------> ");

		while (1) {
			choise = getchar();
			if (choise != '\n'){
				break; //whileループを抜ける
			}
		}

			switch (choise){
			case 'A':
			case 'a':
				printf("\n ゲームばかりしないでください\n\n");
				break;
			case 'B':
			case 'b':
				printf("\n 音楽が選択されました。\n\n");
				break;
			case 'C':
			case 'c':
				printf("\n 表計算が選択されました。\n\n");
				break;
			case 'X':
			case 'x':
				endFlg = 1;
				break;
			default:
				printf("不正な入力です。\n\n");
				break;
			}
			if (endFlg == 1){
				break;
			}
		}
		printf("\n 終了です。\n");
		system("pause");
		return 0;
}