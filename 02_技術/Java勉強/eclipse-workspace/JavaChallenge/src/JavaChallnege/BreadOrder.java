package JavaChallnege;

import JavaChallnege.bread.BreadKind;

public class BreadOrder {

	/**
	 * @author nl_konishi
	 *
	 *         パンの種類
	 */
	private BreadKind kind;

	private int orderNumber = 0;

	// TODO 要不要を判断し、不要なら削除すること
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

	public BreadKind getKind() {
		return this.kind;
		// String で返したい場合は
		// return nthis.kind.name
		// TODO レビュー前に削除すること
	}

	public int getOrderNumber() {
		return this.orderNumber;
	}
}
