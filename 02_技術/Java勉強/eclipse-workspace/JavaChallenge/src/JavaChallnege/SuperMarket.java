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
	 * @return 自分自身のオブジェクト
	 */
	public static SuperMarket getSuperMarketInstance() {

		if (SuperMarket.superMarket != null) {
			return SuperMarket.superMarket;
		}

		SuperMarket.superMarket = new SuperMarket();
		return SuperMarket.superMarket;
	}

	/**
	 * パンの在庫リスト
	 */
	private List<Bread> stock;

	/**
	 * コンストラクタ
	 */
	private SuperMarket() {
		stock = new ArrayList<Bread>();
	}

	/**
	 * @return 在庫の情報の文字列
	 * 
	 *         当オブジェクトが保持するパンの在庫を文字列として返す
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
	 *            パンの注文リスト(整数型の配列)
	 * @throws Exception
	 */
	public void order(int[] breadOrder) throws Exception {
		List<BreadOrder> breadorders = createBreadOrder(breadOrder);
		WholeSaler wholeSaler = WholeSaler.getInstance();

		this.stock = wholeSaler.order(breadorders);
	}

	/**
	 * @param breadOrder
	 * @return パンの注文リスト(BreadOrder型)
	 * @throws Exception
	 */
	private List<BreadOrder> createBreadOrder(int[] breadOrder) throws Exception {
		List<BreadOrder> breadOrders = new ArrayList<BreadOrder>();
		breadOrders.add(new BreadOrder("あんパン", breadOrder[0]));
		breadOrders.add(new BreadOrder("食パン", breadOrder[1]));
		return breadOrders;
	}

}
