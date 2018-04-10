package JavaChallnege;

import java.util.List;

import JavaChallnege.bread.Bread;

/**
 * @author nl_konishi
 *
 *         卸売業者クラス(シングルトンパターンで設計)
 * 
 *         ※ メモ: シングルトンパターンはプログラム中にインスタンスが唯一であることを保証するデザイン
 */
public class WholeSaler {

	/*
	 * ==============================================================
	 * Singletonパターンで設計する
	 * ==============================================================
	 */
	private static WholeSaler wholeSaler = null;

	/**
	 * @return 自分自身のオブジェクト
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
	 *            注文データのリスト
	 * 
	 * @return 注文を受けたパンのリスト
	 * @throws Exception
	 */
	public List<Bread> order(List<BreadOrder> breadOrderList) throws Exception {
		BreadFactory fab = BreadFactory.getBreadFactory();
		List<Bread> breads = fab.makeBreads(breadOrderList);
		return breads;
	}

}
