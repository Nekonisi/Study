package pyramid;

import java.awt.FontFormatException;
import java.util.Scanner;

public class main {

	public static void main(String[] args) {

		try {
			// 入力値
			System.out.println("整数を入力してよ");

			try (Scanner scanner = new Scanner(System.in);) {

				String input = scanner.next();
				if (!checkFormat(input)) {
					System.out.println("いや、だから、整数入力してや");
					throw new FontFormatException("フォーマットがだめ!");
				}

				int inputNum = 0;
				inputNum = Integer.parseInt(input);

				String space = "";
				String format = createFormat(inputNum);
				String spacing = createSpace(inputNum);
				StringBuilder outputString = new StringBuilder();

				for (int pyramidHeight = inputNum; 0 < pyramidHeight; pyramidHeight--) {

					// スペースを格納
					outputString.append(space);
					space = space + spacing;
					for (int i = 0; i < pyramidHeight; i++) {

						// 番号を作成
						String number = String.format(format, pyramidHeight);

						// 番号 + スペースで文字列作成
						outputString.append(number + spacing);
					}
					// 改行
					outputString.append("\r\n");
				}
				System.out.print(outputString.toString());
			}

		} catch (Exception e) {
			System.out.print("失敗～");
			e.printStackTrace();
		}
	}

	private static void createPyramid(String string) {

	}

	/**
	 * @param inputString
	 *            入力値
	 * @return 整数チェックの結果
	 */
	private static boolean checkFormat(String inputString) {

		if (!inputString.matches("[0-9]+")) {
			return false;
		}
		return true;
	}

	/**
	 * @param inputNum
	 * @return スペース幅
	 */
	private static String createSpace(int inputNum) {

		if (inputNum < 10) {
			return " ";
		} else if (inputNum < 100) {
			return "  ";
		} else if (inputNum < 1000) {
			return "   ";
		} else if (inputNum < 10000) {
			return "     ";
		}
		return "";

	}

	/**
	 * @param inputNum
	 * @return フォーマット
	 */
	private static String createFormat(int inputNum) {

		if (inputNum < 10) {
			return "%1d";
		} else if (inputNum < 100) {
			return "%2d";
		} else if (inputNum < 1000) {
			return "%3d";
		} else if (inputNum < 10000) {
			return "%4d";
		}
		return "";

	}

}
