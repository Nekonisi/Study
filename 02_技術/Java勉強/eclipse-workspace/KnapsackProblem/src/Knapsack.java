/**
 * @author kousuke
 *
 *         ナップザッククラス
 */
public class Knapsack {

	/**
	 * ナップザックの容量制限
	 */
	private int capacity;

	/**
	 * 容量制限の小問題を解いたときに最後に選んだ品物を保持する配列
	 */
	private Item[] choise;

	/**
	 * @return 容量制限の小問題を解いたときに最後に選んだ品物を保持する配列
	 */
	public Item[] getChoise() {
		return choise;
	}

	/**
	 * @param Item
	 *            容量制限の小問題を解いたときに最後に選んだ品物
	 * @param size
	 *            容量制限
	 */
	public void setChoise(Item Item, int size) {
		this.choise[size] = Item;
	}

	/**
	 * 容量制限が添字の時の、小問題の価値合計を保持する配列
	 */
	private int[] maxValue;

	public int getCapacity() {
		return capacity;
	}

	/**
	 * @return 小問題の価値合計を保持する配列
	 */
	public int[] getMaxValue() {
		return maxValue;
	}

	/**
	 * @param maxValue
	 *            小問題の価値合計
	 * @param capacity
	 *            ナップザックの容量
	 */
	public void setMaxValue(int maxValue, int capacity) {
		this.maxValue[capacity] = maxValue;
	}

	/**
	 * @param capacity
	 *            ナップザックの容量制限
	 */
	public Knapsack(int capacity) {
		this.capacity = capacity;
		this.maxValue = new int[capacity];
		this.choise = new Item[capacity];
		System.out.println("大きさ[" + capacity + "]のナップザックを作成しました。");
	}
}
