package JavaChallnege;

import java.util.ArrayList;
import java.util.List;

import JavaChallnege.bread.Bread;

/**
 * @author nl_konishi
 * 
 *         スーパーマーケットクラス(シングルトンパターンで設計)
 *
 */
public class SuperMarket {

	/*
	 * ==============================================================
	 * Singletonパターンで設計する
	 * ==============================================================
	 */
	private static SuperMarket superMarket = null;

	/**
	 * @return SuperMarketのインスタンス
	 */
	public static SuperMarket getSuperMarketInstance() {

		if (SuperMarket.superMarket != null) {
			return SuperMarket.superMarket;
		}

		SuperMarket.superMarket = new SuperMarket();
		return SuperMarket.superMarket;
	}

	/**
	 * コンストラクタ
	 */
	private SuperMarket() {
		stock = new ArrayList<Bread>();
	}

	/**
	 * パンの在庫リスト
	 */
	private List<Bread> stock;

	/**
	 * @return パンの在庫リスト
	 */
	public List<Bread> getStock() {
		return this.stock;
	}

	/**
	 * @param breadOrder
	 *            パンの注文リスト(整数型の配列)
	 * @return 現在のストック
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
	 * @return パンの注文リスト(BreadOrder型)
	 * @throws Exception
	 */
	private List<BreadOrder> createBreadOrders(int[] breadOrder) throws Exception {
		List<BreadOrder> breadOrders = new ArrayList<BreadOrder>();
		breadOrders.add(new BreadOrder("あんパン", breadOrder[0]));
		breadOrders.add(new BreadOrder("食パン", breadOrder[1]));
		return breadOrders;
	}

}
