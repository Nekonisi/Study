package JavaChallnege;

import java.util.ArrayList;
import java.util.List;

import JavaChallnege.bread.BeanPasteBread;
import JavaChallnege.bread.Bread;
import JavaChallnege.bread.BreadKind;
import JavaChallnege.bread.PlainBread;

/**
 * @author nl_konishi
 *
 *         �p���H��N���X(�V���O���g���p�^�[���Ő݌v)
 * 
 *         �� ����: �V���O���g���p�^�[���̓v���O�������ɃC���X�^���X���B��ł��邱�Ƃ�ۏ؂���f�U�C��
 */
public class BreadFactory {

	/*
	 * ==============================================================
	 * Singleton�p�^�[���Ő݌v����
	 * ==============================================================
	 */
	private static BreadFactory breadFactory = null;

	/**
	 * @return BreadFactory�̃C���X�^���X���擾
	 */
	public static BreadFactory getBreadFactory() {

		if (BreadFactory.breadFactory != null) {
			return BreadFactory.breadFactory;
		}

		BreadFactory.breadFactory = new BreadFactory();

		return BreadFactory.breadFactory;
	}

	/**
	 * �R���X�g���N�^
	 */
	private BreadFactory() {
	}

	/**
	 * ���݂̃X�g�b�N
	 */
	private List<Bread> stock;

	/**
	 * @param kind
	 *            �쐬����p���̎��
	 * 
	 * @return �쐬�����p��
	 * @throws Exception
	 * 
	 *             �����Ŏ󂯎������ނ̃p���I�u�W�F�N�g���쐬����B
	 */
	private Bread makeBread(BreadKind kind) throws Exception {

		Bread bread = null;

		switch (kind) {
		case BeanPasteBread:
			bread = new BeanPasteBread();
			break;
		case PlainBread:
			bread = new PlainBread();
			break;
		default:
			throw new Exception("�p���I�u�W�F�N�g�̐������s���܂����B");
		}
		return bread;
	}

	/**
	 * @param order
	 *            �������e�̃��X�g
	 * 
	 * @return �쐬�����p���̃��X�g
	 * @throws Exception
	 * 
	 *             �p���̒����[�I�u�W�F�N�g�̃��X�g�^���󂯎���āA�p���̃��X�g��Ԃ��܂��B
	 */
	public List<Bread> makeBreads(List<BreadOrder> breadOrderList) throws Exception {

		// ������p���̃��X�g
		List<Bread> breads = new ArrayList<Bread>();

		for (BreadOrder breadOrder : breadOrderList) {
			BreadKind kind = breadOrder.getKind();
			int orderCount = breadOrder.getOrderNumber();

			// ���������A�p���̍쐬���s���B
			for (int breadOrderCount = 0; breadOrderCount < orderCount; breadOrderCount++) {
				breads.add(makeBread(kind));
			}

		}
		return breads;
	}

	/**
	 * @return ���݂̍݌ɗ�
	 */
	public List<Bread> getStock() {
		return this.stock;
	}
}
