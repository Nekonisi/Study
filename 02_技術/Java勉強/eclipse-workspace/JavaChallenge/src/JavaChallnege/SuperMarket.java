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
	 * @return SuperMarket�̃C���X�^���X
	 */
	public static SuperMarket getSuperMarketInstance() {

		if (SuperMarket.superMarket != null) {
			return SuperMarket.superMarket;
		}

		SuperMarket.superMarket = new SuperMarket();
		return SuperMarket.superMarket;
	}

	/**
	 * �R���X�g���N�^
	 */
	private SuperMarket() {
		stock = new ArrayList<Bread>();
	}

	/**
	 * �p���̍݌Ƀ��X�g
	 */
	private List<Bread> stock;

	/**
	 * @return �p���̍݌Ƀ��X�g
	 */
	public List<Bread> getStock() {
		return this.stock;
	}

	/**
	 * @param breadOrder
	 *            �p���̒������X�g(�����^�̔z��)
	 * @return ���݂̃X�g�b�N
	 * @throws Exception
	 */
	public List<Bread> order(int[] breadOrder) throws Exception {
		List<BreadOrder> breadorders = createBreadOrders(breadOrder);
		WholeSaler wholeSaler = WholeSaler.getWholeSaler();

		this.stock = wholeSaler.order(breadorders);
		return this.stock;
	}

	/**
	 * @param breadOrder
	 * @return �p���̒������X�g(BreadOrder�^)
	 * @throws Exception
	 */
	private List<BreadOrder> createBreadOrders(int[] breadOrder) throws Exception {
		List<BreadOrder> breadOrders = new ArrayList<BreadOrder>();
		breadOrders.add(new BreadOrder("����p��", breadOrder[0]));
		breadOrders.add(new BreadOrder("�H�p��", breadOrder[1]));
		return breadOrders;
	}

}
