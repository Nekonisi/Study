#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char str1[8] = "ABC";
	char str2[8] = "ABC";
	char str3[8] = "DEF";

	/*値の表示*/
	printf("<値>\n");
	printf("\tstr1's value = %s\n", str1);
	printf("\tstr2's value = %s\n", str2);
	printf("\tstr3's value = %s\n", str3);

	/*アドレスの表示*/
	printf("<アドレス>\n");
	printf("\tstr1's address = %p\n", &str1);
	printf("\tstr2's address = %p\n", &str2);
	printf("\tstr3's address = %p\n", &str3);
	printf("※ 同じ文字列でも異なるアドレスに格納される。\n");

	/*文字列比較*/
	// 比較結果格納用の変数
	int cmp1;
	int cmp2;

	cmp1 = strcmp(str1, str2);
	cmp2 = strcmp(str1, str3);

	/*cmp1の判定*/
	printf("\n<cmp1の判定>\n");
	if (cmp1 < 0){
		printf("\t%sは%sより前にあります。\n", str1, str2);
	}
	else if (cmp1 >0){
		printf("\t%sは%sより後ろにあります。\n", str1, str2);
	}
	else if (cmp1 == 0){
		printf("\t%sと%sは同じ文字列です。\n", str1, str2);
	}

	/*cmp2の判定*/
	printf("\n<cmp2の判定>\n");
	if (cmp2 < 0){
		printf("\t%sは%sより前にあります。\n", str1, str3);
	}
	else if (cmp2 >0){
		printf("\t%sは%sより後ろにあります。\n", str1, str3);
	}
	else if (cmp2 == 0){
		printf("\t%sと%sは同じ文字列です。\n", str1, str3);
	}

	system("pause");
	return 0;

}