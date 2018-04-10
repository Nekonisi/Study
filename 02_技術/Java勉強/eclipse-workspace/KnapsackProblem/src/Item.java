
/**
 * @author nl_konishi
 * 
 *         アイテムクラス<br>
 *         重さと価値を保持する
 * 
 */
public class Item {

	/**
	 * @return 価値
	 */
	public int getValue() {
		return value;
	}

	/**
	 * @param value
	 *            価値
	 */
	public void setValue(int value) {
		this.value = value;
	}

	/**
	 * @return 重さ
	 */
	public int getWeight() {
		return weight;
	}

	/**
	 * @param weight
	 *            重さ
	 */
	public void setWeight(int weight) {
		this.weight = weight;
	}

	/**
	 * 価値
	 */
	private int value;

	/**
	 * 重さ
	 */
	private int weight;

	/**
	 * @param value
	 *            価値
	 * @param weight
	 *            重さ
	 * 
	 *            コンストラクタ
	 */
	public Item(int value, int weight) {
		this.value = value;
		this.weight = weight;
		System.out.println("価値[" + this.value + "], 重さ[" + this.weight + "]のアイテムを作成しました。");
	}
}
