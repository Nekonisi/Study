package JavaChallnege;

import JavaChallnege.bread.BreadKind;

/**
 * @author nl_konishi
 * 
 *         �p���̒����\�N���X �������s���p���̎�ނƒ������𑮐��Ƃ��ĕێ�����B
 * 
 */
public class BreadOrder {

	/**
	 * �p���̎��
	 */
	private BreadKind kind;

	/**
	 * �p���̒�����
	 */
	private int orderNumber = 0;

	/**
	 * @param kind
	 *            ��������p���̎��
	 * @param orderNumber
	 *            ������
	 * @throws Exception
	 * 
	 *             �R���X�g���N�^
	 */
	public BreadOrder(String kind, int orderNumber) throws Exception {
		switch (kind) {
		case "����p��":
			this.kind = BreadKind.BeanPasteBread;
			break;
		case "�H�p��":
			this.kind = BreadKind.PlainBread;
			break;
		default:
			System.out.println(kind);
			throw new Exception("BreadOrder�̃t�H�[�}�b�g���Ⴂ�܂��B");
		}
		this.orderNumber = orderNumber;
	}

	/**
	 * @return �p���̎��
	 * 
	 *         �p���̎�ނ�getter
	 */
	public BreadKind getKind() {
		return this.kind;
	}

	/**
	 * @return �p���̒�����
	 * 
	 *         �p���̒�������getter
	 */
	public int getOrderNumber() {
		return this.orderNumber;
	}
}
