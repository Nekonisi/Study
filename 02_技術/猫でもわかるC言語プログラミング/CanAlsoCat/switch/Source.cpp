#include <stdio.h>
#include <stdlib.h>

void IntMode();
void CharMode();

int main()
{
	int mode;

	printf("モード選択(IntMode: 0 CharMode: 1 Exit: other)");
	scanf_s("%d", &mode);

	/*モード選択*/
	switch (mode) {
	case 0:
		IntMode();
		break;
	case 1:
		CharMode();
		break;
	default:
		printf("プログラムを終了します。\n");
		system("pause");
		return 0;
	}
	return 0;
}

void IntMode(){

	int input;

	printf("------------------------------------\n");
	printf("IntMode\n");
	printf("------------------------------------\n");
	printf("1から5までの整数を入力してください。\n");
	scanf_s("%d", &input);

	switch (input){
	case 1:
		printf("1が入力されました。\n");
		break;
	case 2:
		printf("2を入力しましたね。\n");
		break;
	case 3:
		printf("あなたは3を入力しました。\n");
		break;
	case 4:
		printf("4とは不吉な。\n");
		break;
	case 5:
		printf("5か縁起がいいね。\n");
		break;
	default:
		printf("1から5までの整数を入力してください。\n");
		break;
	}

	system("pause");
}

void CharMode(){

	char input;

	printf("------------------------------------\n");
	printf("CharMode\n");
	printf("------------------------------------\n");
	printf("aからcまでを1文字入力してください。\n");
	scanf_s("%c", &input);

	switch (input){
	case 'a':
		printf("Kiss\n");
		break;
	case 'b':
		printf("bust\n");
		break;
	case 'c':
		printf("fuck\n");
		break;
	default:
	printf("aからcまでを1文字入力してください。\n");
		break;
	}

	system("pause");

}