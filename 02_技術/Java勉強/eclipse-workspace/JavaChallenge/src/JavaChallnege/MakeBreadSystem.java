package JavaChallnege;

import java.util.Scanner;

public class MakeBreadSystem {

	/**
	 * ���C������
	 */
	public static void main(String args[]) {
		try (Scanner scan = new Scanner(System.in)) {
			int[] breadOrder = new int[2];

			System.out.println("�������邠��p���̌�����͂��Ă��������B");
			String inputValue = scan.next();

			if (!checkIntegerValue(inputValue)) {
				throw new Exception("�t�H�[�}�b�g�G���[: �����l����͂��Ă�������");
			}

			breadOrder[0] = Integer.parseInt(inputValue);

			System.out.println("��������H�p���̌�����͂��Ă��������B");
			inputValue = scan.next();

			if (!checkIntegerValue(inputValue)) {
				throw new Exception("�t�H�[�}�b�g�G���[: �����l����͂��Ă�������");
			}

			breadOrder[1] = Integer.parseInt(inputValue);

			SuperMarket superMarket = SuperMarket.getSuperMarketInstance();
			superMarket.order(breadOrder);

			System.out.println("�݌ɂ�\��");
			System.out.println(superMarket.getStock());

		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			System.out.println("�p���쐬�V�X�e�����I�����܂��B");
		}
	}

	/**
	 * @param value
	 * @return �t�H�[�}�b�g�`�F�b�N�̐���
	 * 
	 */
	private static boolean checkIntegerValue(String value) {
		String pattern = "[0-9]+";
		return value.matches(pattern);
	}
}