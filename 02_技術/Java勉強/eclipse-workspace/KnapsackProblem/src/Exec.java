import java.util.Scanner;

/**
 * @author kousuke 実行クラス シングルトンパターンで設計
 */
public class Exec {

	/**
	 * 整数チェックのパターン
	 */
	private static final String intPattern = "[0-9]+";

	private static Exec instance = new Exec();

	/**
	 * コンストラクタ
	 */
	private Exec() {
	}

	/**
	 * @return インスタンス
	 */
	public static Exec GetInstance() {
		return Exec.instance;
	}

	/**
	 * メイン処理
	 * 
	 * @throws Exception
	 */
	public void main() throws Exception {
		System.out.println("****************** ナップザック問題解放システム開始 ******************");
		Scanner scanner = new Scanner(System.in);

		Knapsack knapsack = createKnapsack(scanner);
		Item[] arrayItem = createItems(scanner);

		knapSackResolve(knapsack, arrayItem);
	}

	/**
	 * @param scanner
	 *            Scanner
	 * @throws Exception
	 * 
	 *             Knapsackオブジェクトを作成する
	 */
	private Knapsack createKnapsack(Scanner scanner) throws Exception {
		System.out.print("ナップザックの容量を入力してください: ");
		String inputString = scanner.next();

		// 整数値フォーマットチェック
		if (!inputString.matches(intPattern)) {
			throw new Exception("整数値を入力してください");
		}

		int knapSackSize = Integer.parseInt(inputString);
		return new Knapsack(knapSackSize);

	}

	/**
	 * @param scanner
	 * @throws Exception
	 * 
	 *             Itemの配列を作成する
	 */
	private Item[] createItems(Scanner scanner) throws Exception {

		System.out.println();

		System.out.print("アイテムの個数を入力してください: ");
		String inputString = scanner.next();

		// 整数値フォーマットチェック
		if (!inputString.matches(intPattern)) {
			throw new Exception("整数値を入力してください");
		}

		int itemNumber = Integer.parseInt(inputString);
		Item[] arrayItem = new Item[itemNumber];

		System.out.println("****************** アイテム作成 ******************");
		for (int itemCount = 0; itemCount < itemNumber; itemCount++) {
			System.out.print("アイテム" + (itemCount + 1) + "の価値: ");
			inputString = scanner.next();

			if (!inputString.matches(intPattern)) {
				throw new Exception("整数値を入力してください");
			}

			int itemValue = Integer.parseInt(inputString);

			System.out.print("アイテム" + (itemCount + 1) + "の重さ: ");
			inputString = scanner.next();

			if (!inputString.matches(intPattern)) {
				throw new Exception("整数値を入力してください");
			}

			int itemWeight = Integer.parseInt(inputString);

			arrayItem[itemCount] = new Item(itemValue, itemWeight);
		}
		return arrayItem;

	}

	/**
	 * ナップザック問題解決メソッド
	 */
	private void knapSackResolve(Knapsack knapsack, Item[] arrayItem) {

		// 動的計画法メイン
		for (int itemNumber = 0; itemNumber < arrayItem.length; itemNumber++) {
			for (int weight = arrayItem[itemNumber].getWeight(); weight < knapsack.getCapacity(); weight++) {
				int temp = knapsack.getMaxValue()[weight - arrayItem[itemNumber].getWeight()];
				if (temp > knapsack.getMaxValue()[weight]) {
					knapsack.setMaxValue(temp, weight);
					knapsack.setChoise(arrayItem[itemNumber], weight);
				}
			}
		}
		// 結果の出力。選んだ品物と価値合計を出力する。
		int k = arrayItem.length;
		while (knapsack.getChoise()[0].getValue() > 0) {
			System.out.println("choise[" + k + "]: " + knapsack.getChoise()[k].getValue());
			k = k - arrayItem[knapsack.getChoise()[k].getValue()].getValue();
		}
	}

}
