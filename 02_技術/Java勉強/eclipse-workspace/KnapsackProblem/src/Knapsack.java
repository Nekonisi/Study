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
	 * 容量制限が添字の時の、小問題の価値合計を保持する配列
	 */
	private int[] maxValue;

	public int getCapacity() {
		return capacity;
	}

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
	private Knapsack(int capacity) {
		this.capacity = capacity;
		this.maxValue = new int[capacity];
	}

}
