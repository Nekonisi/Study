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
	/**
	 * �p���H��̃C���X�^���X���쐬
	 */
	private static final BreadFactory instance = new BreadFactory();

	/**
	 * ���݂̃X�g�b�N
	 */
	private List<Bread> stock;

	/**
	 * �R���X�g���N�^
	 */
	private BreadFactory() {
	}

	/**
	 * @return �������g�̃I�u�W�F�N�g
	 * 
	 *         �� �V���O���g���p�^�[���̎���
	 */
	public static BreadFactory getInstance() {
		return BreadFactory.instance;
	}

	/**
	 * @param kind
	 *            �p���̎��
	 * 
	 * @return �쐬�����p��
	 * @throws Exception
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
	 * @return ���������p��(���X�g�^)
	 * @throws Exception
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
