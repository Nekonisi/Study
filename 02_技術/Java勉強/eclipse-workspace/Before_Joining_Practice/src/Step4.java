import java.util.Scanner;

public class Step4 {
	public static void main() {

		try {
			// 最初のメッセージを表示するよ！
			ShowMessage(0);

			// キーボードからの読込
		} catch (Exception e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
		String inputString = scan.next();

		// キーボードからの入力をchar配列に変換
		char[] inputCharArray =inputString.toCharArray();

		// 桁数チェック
		if (!checkDigit(inputCharArray)){
			// ダメだった場合
			ShowMessage(1);
			System.exit(1);
		}

		// 文字の種類チェック
		if (!checkCharKind(inputCharArray)){
			//ダメだった場合
			ShowMessage(2);
			System.exit(2);
		}

		// 結果表示

		// 入力値 String -> int
		int inputInt=Integer.parseInt(inputString);

		// 桁数を取得
		int digitLen=String.valueOf(inputInt).length();

		// 1文字目が-だったら桁数を一つ少なく
		if( inputCharArray[0]=='-'){
			digitLen--;
		}

		System.out.println("＊＊□数字チェック結果□＊＊");
		System.out.println("□ＡＬＬ ＮＵＭＢＥＲ！！\r\n");

		System.out.print("入力した文字列は" + inputInt);
		System.out.print("で桁数は" + digitLen + "です。\r\n");
	}

	/* メッセージを表示するだけのクソクラス*/
	private static void ShowMessage(int num){
		switch (num){
		case 0: // 最初のメッセージのやつ
			System.out.println("＊＊□数字チェックプログラム□＊＊");
			System.out.println("＊＊□整数を入力して下さい□□＊＊");
			break;

		case 1: // 桁数がおかしいとき
			System.out.println("＊＊□入力桁数が不正です！□□＊＊\r\n");
			break;

		case 2: // 文字の種類がおかしいとき
			System.out.println("＊＊□入力した文字が不正です！□□＊＊\r\n");
			break;
		}
	}

	/* 入力文字列の桁数が10桁以上かどうかを判断するだけのクソメソッド*/
	private static boolean checkDigit(char inputChar[]){
		// 最初の文字が"+" or "-" かどうか？
		if (inputChar[0]=='+' || inputChar[0]=='-'){
			// 最初の文字が+か-だった場合
			if (inputChar.length > 11){
				return false;
			} else {
				return true;
			}
		} else {
			if (inputChar.length > 10){
				return false;
			} else {
				return true;
			}
		}
	}

	/* 文字の種類をチェックする
		 仕様見る限り、半角数字だけOKにすればよくね？*/
	private static boolean checkCharKind(char inputChar[]){

		// match関数で使用する正規表現のパターン
		String pattern="";
		for (int charCount = 0; charCount < inputChar.length; charCount++){
			if (charCount==0) {
				// 1文字目
				pattern="[-|+|0-9]";
			} else {
				// 1文字よりあと
				pattern="[0-9]";
			}
			if (String.valueOf(inputChar[charCount]).matches(pattern)) {
			} else {
				return false;
			}
		}
		return true;
	}
}