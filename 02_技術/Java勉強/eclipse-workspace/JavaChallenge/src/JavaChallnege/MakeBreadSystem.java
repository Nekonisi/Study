package JavaChallnege;

import java.util.Scanner;

/**
 * @author nl_konishi �p���쐬�V�X�e��
 * 
 *         �V���O���g���p�^�[���Ő݌v
 */
public class MakeBreadSystem {

	/*
	 * ==============================================================
	 * Singleton�p�^�[���Ő݌v����
	 * ==============================================================
	 */

	private static MakeBreadSystem makeBreadSystem = null;

	/**
	 * @return MakeBreadSystem�̃C���X�^���X
	 */
	public static MakeBreadSystem getMakeBreadSystem() {

		if (MakeBreadSystem.makeBreadSystem != null) {
			return MakeBreadSystem.makeBreadSystem;
		}

		MakeBreadSystem.makeBreadSystem = new MakeBreadSystem();

		return MakeBreadSystem.makeBreadSystem;
	}

	/**
	 * �R���X�g���N�^
	 */
	private MakeBreadSystem() {

	}

	/**
	 * ���C������
	 */
	public void exec() {
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