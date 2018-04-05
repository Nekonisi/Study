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
			// ���͒l
			System.out.println("��������͂��Ă��������B");

			try (Scanner scanner = new Scanner(System.in);) {

				String input = scanner.next();
				if (!checkFormat(input)) {
					System.out.println("���͂��ꂽ�l�������łȂ��̂ŏI�����܂��B");
					throw new DataFormatException();
				}

				int inputNum = 0;
				inputNum = Integer.parseInt(input);

				String reversePyramidString = createReversePyramid(inputNum);

				System.out.println("*************************************************");
				System.out.println("�t�s���~�b�h���o�� ");
				System.out.println("*************************************************");
				System.out.print(reversePyramidString);

				// �s���~�b�h�^�̕����񂩂琔�l�̃��X�g���쐬
				List<Integer> integerList = ejecttionInteger(reversePyramidString);

				// ���l�̃��X�g����ő�l�𒊏o
				int maxInt = searchMaxInt(integerList);

				String pyramidString = createPyramid(maxInt);

				System.out.println("*************************************************");
				System.out.println("�s���~�b�h���o�� ");
				System.out.println("*************************************************");
				System.out.print(pyramidString);

				String alphabetPyramidString = createAlphabetPyramid(maxInt);

				System.out.println("*************************************************");
				System.out.println("�A���t�@�x�b�g�s���~�b�h���o�� ");
				System.out.println("*************************************************");
				System.out.print(alphabetPyramidString);
			}

		} catch (IllegalFormatException e) {
			System.out.println("�t�H�[�}�b�g�G���[");
			e.printStackTrace();
		} catch (Exception e) {
			System.out.println("��O�I��");
			e.printStackTrace();
		}
	}

	/**
	 * @param height
	 * @return �A���t�@�x�b�g�s���~�b�h�̕�����
	 * @throws DataFormatException
	 * 
	 *             ���͂��ꂽ�����̃A���t�@�x�b�g�s���~�b�h���쐬���܂��B
	 */
	private static String createAlphabetPyramid(int height) throws DataFormatException {

		// �������̃s���~�b�h�����B
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

				// �ԍ� + �X�y�[�X�ŕ�����쐬
				outputString.append(convertAlphabet(pyramidHeight) + spacing);
			}
			// ���s
			outputString.append("\r\n");
		}

		return outputString.toString();

	}

	/**
	 * @param number
	 * @return �A���t�@�x�b�g
	 * @throws DataFormatException
	 * 
	 *             ���͒l����Ή�����A���t�@�x�b�g��啶���ŕԂ��܂��B
	 */
	private static char convertAlphabet(int number) throws DataFormatException {

		if (number > 26) {
			throw new DataFormatException("���͂��ꂽ�����l���A���t�@�x�b�g���傫���ł��B");
		}
		String line = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		char[] alphabetCharArray = line.toCharArray();

		return alphabetCharArray[number - 1];
	}

	/**
	 * @param height
	 * @return �t�s���~�b�h
	 * 
	 *         ���͒l�̍����́A�t�s���~�b�h���쐬����B
	 */
	private static String createReversePyramid(int height) {
		String space = "";
		String format = createFormat(height);
		String spacing = createSpace(height);
		StringBuilder outputString = new StringBuilder();
		outputString.append("\r\n");

		for (int pyramidHeight = height; 0 < pyramidHeight; pyramidHeight--) {

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

		return outputString.toString();

	}

	/**
	 * @param height
	 * @return �������̃s���~�b�h
	 * 
	 *         ���͒l�̍����̃s���~�b�h���쐬����B
	 */
	private static String createPyramid(int height) {

		// �������̃s���~�b�h�����B
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

				// �ԍ����쐬
				String number = String.format(format, pyramidHeight);

				// �ԍ� + �X�y�[�X�ŕ�����쐬
				outputString.append(number + spacing);
			}
			// ���s
			outputString.append("\r\n");
		}

		return outputString.toString();

	}

	/**
	 * @param string
	 *            ������
	 * @return �����񒆂̍ő�l
	 * 
	 * 
	 */
	private static int searchMaxInt(List<Integer> intgerList) {
		int maxInt = 0;
		// �R���N�V�������J��Ԃ�
		for (Integer integer : intgerList) {
			if (maxInt < integer) {
				maxInt = integer;
			}
		}
		return maxInt;
	}

	/**
	 * @param
	 * @return ���o�������l�̃��X�g
	 * 
	 *         String������
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