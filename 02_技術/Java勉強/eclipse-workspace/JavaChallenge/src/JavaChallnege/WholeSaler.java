package JavaChallnege;

import java.util.List;

import JavaChallnege.bread.Bread;

/**
 * @author nl_konishi
 *
 *         �����Ǝ҃N���X(�V���O���g���p�^�[���Ő݌v)
 * 
 *         �� ����: �V���O���g���p�^�[���̓v���O�������ɃC���X�^���X���B��ł��邱�Ƃ�ۏ؂���f�U�C��
 */
public class WholeSaler {

	/*
	 * ==============================================================
	 * Singleton�p�^�[���Ő݌v����
	 * ==============================================================
	 */
	private static WholeSaler wholeSaler = null;

	/**
	 * @return �������g�̃I�u�W�F�N�g
	 */
	public static WholeSaler getWholeSaler() {

		if (WholeSaler.wholeSaler != null) {
			return WholeSaler.wholeSaler;
		}

		WholeSaler.wholeSaler = new WholeSaler();
		return WholeSaler.wholeSaler;
	}

	/**
	 * @param breadOrderList
	 *            �����f�[�^�̃��X�g
	 * 
	 * @return �������󂯂��p���̃��X�g
	 * @throws Exception
	 */
	public List<Bread> order(List<BreadOrder> breadOrderList) throws Exception {
		BreadFactory fab = BreadFactory.getBreadFactory();
		List<Bread> breads = fab.makeBreads(breadOrderList);
		return breads;
	}

}
