package JavaChallnege;

import JavaChallnege.bread.BreadKind;

public class BreadOrder {

	/**
	 * @author nl_konishi
	 *
	 *         �p���̎��
	 */
	private BreadKind kind;

	private int orderNumber = 0;

	// TODO �v�s�v�𔻒f���A�s�v�Ȃ�폜���邱��
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

	public BreadKind getKind() {
		return this.kind;
		// String �ŕԂ������ꍇ��
		// return nthis.kind.name
		// TODO ���r���[�O�ɍ폜���邱��
	}

	public int getOrderNumber() {
		return this.orderNumber;
	}
}
