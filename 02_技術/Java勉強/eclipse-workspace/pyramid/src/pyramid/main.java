package pyramid;

import java.util.ArrayList;
import java.util.IllegalFormatException;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.zip.DataFormatException;

public class main {
	public static void main(String args[]) {

		try {
			// 入力値
			System.out.println("整数を入力してください。");

			try (Scanner scanner = new Scanner(System.in);) {

				String input = scanner.next();
				if (!checkFormat(input)) {
					System.out.println("入力された値が整数でないので終了します。");
					throw new DataFormatException();
				}

				int inputNum = 0;
				inputNum = Integer.parseInt(input);

				String reversePyramidString = createReversePyramid(inputNum);

				System.out.println("*************************************************");
				System.out.println("逆ピラミッドを出力 ");
				System.out.println("*************************************************");
				System.out.print(reversePyramidString);

				// ピラミッド型の文字列から数値のリストを作成
				List<Integer> integerList = ejecttionInteger(reversePyramidString);

				// 数値のリストから最大値を抽出
				int maxInt = searchMaxInt(integerList);

				String pyramidString = createPyramid(maxInt);

				System.out.println("*************************************************");
				System.out.println("ピラミッドを出力 ");
				System.out.println("*************************************************");
				System.out.print(pyramidString);

				String alphabetPyramidString = createAlphabetPyramid(maxInt);

				System.out.println("*************************************************");
				System.out.println("アルファベットピラミッドを出力 ");
				System.out.println("*************************************************");
				System.out.print(alphabetPyramidString);
			}

		} catch (IllegalFormatException e) {
			System.out.println("フォーマットエラー");
			e.printStackTrace();
		} catch (Exception e) {
			System.out.println("例外終了");
			e.printStackTrace();
		}
	}

	/**
	 * @param height
	 * @return アルファベットピラミッドの文字列
	 * @throws DataFormatException
	 * 
	 *             入力された高さのアルファベットピラミッドを作成します。
	 */
	private static String createAlphabetPyramid(int height) throws DataFormatException {

		// 順方向のピラミッドを作る。
		String space = "";
		String spacing = " ";
		StringBuilder outputString = new StringBuilder();
		outputString.append("\r\n");

		for (int pyramidHeight = 0; pyramidHeight <= height; pyramidHeight++) {
			space = "";

			for (int temp = height - pyramidHeight; 0 < temp; temp--) {
				space = space + spacing;
			}
			outputString.append(space);
			space = space + spacing;
			for (int i = 0; i < pyramidHeight; i++) {

				// 番号 + スペースで文字列作成
				outputString.append(convertAlphabet(pyramidHeight) + spacing);
			}
			// 改行
			outputString.append("\r\n");
		}

		return outputString.toString();

	}

	/**
	 * @param number
	 * @return アルファベット
	 * @throws DataFormatException
	 * 
	 *             入力値から対応するアルファベットを大文字で返します。
	 */
	private static char convertAlphabet(int number) throws DataFormatException {

		if (number > 26) {
			throw new DataFormatException("入力された整数値がアルファベットより大きいです。");
		}
		String line = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		char[] alphabetCharArray = line.toCharArray();

		return alphabetCharArray[number - 1];
	}

	/**
	 * @param height
	 * @return 逆ピラミッド
	 * 
	 *         入力値の高さの、逆ピラミッドを作成する。
	 */
	private static String createReversePyramid(int height) {
		String space = "";
		String format = createFormat(height);
		String spacing = createSpace(height);
		StringBuilder outputString = new StringBuilder();
		outputString.append("\r\n");

		for (int pyramidHeight = height; 0 < pyramidHeight; pyramidHeight--) {

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

		return outputString.toString();

	}

	/**
	 * @param height
	 * @return 順方向のピラミッド
	 * 
	 *         入力値の高さのピラミッドを作成する。
	 */
	private static String createPyramid(int height) {

		// 順方向のピラミッドを作る。
		String space = "";
		String format = createFormat(height);
		String spacing = createSpace(height);
		StringBuilder outputString = new StringBuilder();

		for (int pyramidHeight = 0; pyramidHeight <= height; pyramidHeight++) {
			space = "";

			for (int temp = height - pyramidHeight; 0 < temp; temp--) {
				space = space + spacing;
			}
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

		return outputString.toString();

	}

	/**
	 * @param string
	 *            文字列
	 * @return 文字列中の最大値
	 * 
	 * 
	 */
	private static int searchMaxInt(List<Integer> intgerList) {
		int maxInt = 0;
		// コレクション内繰り返し
		for (Integer integer : intgerList) {
			if (maxInt < integer) {
				maxInt = integer;
			}
		}
		return maxInt;
	}

	/**
	 * @param
	 * @return 取り出した数値のリスト
	 * 
	 *         String文字列
	 * 
	 */
	private static List<Integer> ejecttionInteger(String string) {
		Pattern pattern = Pattern.compile("\\d+");
		Matcher matcher = pattern.matcher(string);

		List<Integer> list = new ArrayList<Integer>();

		while (matcher.find()) {
			list.add(Integer.parseInt(matcher.group()));
		}
		return list;
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