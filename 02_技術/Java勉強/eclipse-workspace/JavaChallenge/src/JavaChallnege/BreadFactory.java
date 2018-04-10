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
 *         パン工場クラス(シングルトンパターンで設計)
 * 
 *         ※ メモ: シングルトンパターンはプログラム中にインスタンスが唯一であることを保証するデザイン
 */
public class BreadFactory {

	/*
	 * ==============================================================
	 * Singletonパターンで設計する
	 * ==============================================================
	 */
	private static BreadFactory breadFactory = null;

	/**
	 * @return BreadFactoryのインスタンスを取得
	 */
	public static BreadFactory getBreadFactory() {

		if (BreadFactory.breadFactory != null) {
			return BreadFactory.breadFactory;
		}

		BreadFactory.breadFactory = new BreadFactory();

		return BreadFactory.breadFactory;
	}

	/**
	 * コンストラクタ
	 */
	private BreadFactory() {
	}

	/**
	 * 現在のストック
	 */
	private List<Bread> stock;

	/**
	 * @param kind
	 *            作成するパンの種別
	 * 
	 * @return 作成したパン
	 * @throws Exception
	 * 
	 *             引数で受け取った種類のパンオブジェクトを作成する。
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
			throw new Exception("パンオブジェクトの生成失敗しました。");
		}
		return bread;
	}

	/**
	 * @param order
	 *            注文内容のリスト
	 * 
	 * @return 作成したパンのリスト
	 * @throws Exception
	 * 
	 *             パンの注文票オブジェクトのリスト型を受け取って、パンのリストを返します。
	 */
	public List<Bread> makeBreads(List<BreadOrder> breadOrderList) throws Exception {

		// 作ったパンのリスト
		List<Bread> breads = new ArrayList<Bread>();

		for (BreadOrder breadOrder : breadOrderList) {
			BreadKind kind = breadOrder.getKind();
			int orderCount = breadOrder.getOrderNumber();

			// 注文数文、パンの作成を行う。
			for (int breadOrderCount = 0; breadOrderCount < orderCount; breadOrderCount++) {
				breads.add(makeBread(kind));
			}

		}
		return breads;
	}

	/**
	 * @return 現在の在庫量
	 */
	public List<Bread> getStock() {
		return this.stock;
	}
}
