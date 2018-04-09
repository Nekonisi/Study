package JavaChallnege;

import java.util.ArrayList;
import java.util.List;

import JavaChallnege.bread.Bread;

/**
 * @author nl_konishi
 * 
 *         �X�[�p�[�}�[�P�b�g�N���X(�V���O���g���p�^�[���Ő݌v)
 *
 */
public class SuperMarket {

	/*
	 * ==============================================================
	 * Singleton�p�^�[���Ő݌v����
	 * ==============================================================
	 */
	private static SuperMarket superMarket = null;

	/**
	 * @return �������g�̃I�u�W�F�N�g
	 */
	public static SuperMarket getSuperMarketInstance() {

		if (SuperMarket.superMarket != null) {
			return SuperMarket.superMarket;
		}

		SuperMarket.superMarket = new SuperMarket();
		return SuperMarket.superMarket;
	}

	/**
	 * �p���̍݌Ƀ��X�g
	 */
	private List<Bread> stock;

	/**
	 * �R���X�g���N�^
	 */
	private SuperMarket() {
		stock = new ArrayList<Bread>();
	}

	/**
	 * @return �݌ɂ̏��̕�����
	 * 
	 *         ���I�u�W�F�N�g���ێ�����p���̍݌ɂ𕶎���Ƃ��ĕԂ�
	 */
	// public String getStock() {
	// StringBuilder stockStringBuilder = new StringBuilder();
	// for (Bread bread : this.stock) {
	// String kind = bread.getKind();
	// stockStringBuilder.append(kind + "\r\n");
	// }
	// return stockStringBuilder.toString();
	// }

	public List<Bread> getStock() {
		return this.stock;
	}

	/**
	 * @param breadOrder
	 *            �p���̒������X�g(�����^�̔z��)
	 * @throws Exception
	 */
	public void order(int[] breadOrder) throws Exception {
		List<BreadOrder> breadorders = createBreadOrder(breadOrder);
		WholeSaler wholeSaler = WholeSaler.getInstance();

		this.stock = wholeSaler.order(breadorders);
	}

	/**
	 * @param breadOrder
	 * @return �p���̒������X�g(BreadOrder�^)
	 * @throws Exception
	 */
	private List<BreadOrder> createBreadOrder(int[] breadOrder) throws Exception {
		List<BreadOrder> breadOrders = new ArrayList<BreadOrder>();
		breadOrders.add(new BreadOrder("����p��", breadOrder[0]));
		breadOrders.add(new BreadOrder("�H�p��", breadOrder[1]));
		return breadOrders;
	}

}
