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
	private static final WholeSaler instance = new WholeSaler();

	/**
	 * @return 自分自身のオブジェクト
	 */
	public static WholeSaler getInstance() {
		return WholeSaler.instance;
	}

	/**
	 * @param breadOrderList
	 *            注文データのリスト
	 * 
	 * @return 注文を受けたパンのリスト
	 * @throws Exception
	 */
	public List<Bread> order(List<BreadOrder> breadOrderList) throws Exception {
		BreadFactory fab = BreadFactory.getInstance();
		List<Bread> breads = fab.makeBreads(breadOrderList);
		return breads;
	}

}
