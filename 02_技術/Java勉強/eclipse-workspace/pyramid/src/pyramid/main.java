package pyramid;

import java.awt.FontFormatException;
import java.util.Scanner;

public class main {

	public static void main(String[] args) {

		try {
			// ���͒l
			System.out.println("��������͂��Ă�");

			try (Scanner scanner = new Scanner(System.in);) {

				String input = scanner.next();
				if (!checkFormat(input)) {
					System.out.println("����A������A�������͂��Ă�");
					throw new FontFormatException("�t�H�[�}�b�g������!");
				}

				int inputNum = 0;
				inputNum = Integer.parseInt(input);

				String space = "";
				String format = createFormat(inputNum);
				String spacing = createSpace(inputNum);
				StringBuilder outputString = new StringBuilder();

				for (int pyramidHeight = inputNum; 0 < pyramidHeight; pyramidHeight--) {

					// �X�y�[�X���i�[
					outputString.append(space);
					space = space + spacing;
					for (int i = 0; i < pyramidHeight; i++) {

						// �ԍ����쐬
						String number = String.format(format, pyramidHeight);

						// �ԍ� + �X�y�[�X�ŕ�����쐬
						outputString.append(number + spacing);
					}
					// ���s
					outputString.append("\r\n");
				}
				System.out.print(outputString.toString());
			}

		} catch (Exception e) {
			System.out.print("���s�`");
			e.printStackTrace();
		}
	}

	private static void createPyramid(String string) {

	}

	/**
	 * @param inputString
	 *            ���͒l
	 * @return �����`�F�b�N�̌���
	 */
	private static boolean checkFormat(String inputString) {

		if (!inputString.matches("[0-9]+")) {
			return false;
		}
		return true;
	}

	/**
	 * @param inputNum
	 * @return �X�y�[�X��
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
	 * @return �t�H�[�}�b�g
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
