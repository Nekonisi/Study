package JavaChallnege;

import JavaChallnege.bread.BreadKind;

/**
 * @author nl_konishi
 * 
 *         パンの注文表クラス 注文を行うパンの種類と注文数を属性として保持する。
 * 
 */
public class BreadOrder {

	/**
	 * パンの種類
	 */
	private BreadKind kind;

	/**
	 * パンの注文数
	 */
	private int orderNumber = 0;

	/**
	 * @param kind
	 *            注文するパンの種類
	 * @param orderNumber
	 *            注文数
	 * @throws Exception
	 * 
	 *             コンストラクタ
	 */
	public BreadOrder(String kind, int orderNumber) throws Exception {
		switch (kind) {
		case "あんパン":
			this.kind = BreadKind.BeanPasteBread;
			break;
		case "食パン":
			this.kind = BreadKind.PlainBread;
			break;
		default:
			System.out.println(kind);
			throw new Exception("BreadOrderのフォーマットが違います。");
		}
		this.orderNumber = orderNumber;
	}

	/**
	 * @return パンの種類
	 * 
	 *         パンの種類のgetter
	 */
	public BreadKind getKind() {
		return this.kind;
	}

	/**
	 * @return パンの注文数
	 * 
	 *         パンの注文数のgetter
	 */
	public int getOrderNumber() {
		return this.orderNumber;
	}
}
