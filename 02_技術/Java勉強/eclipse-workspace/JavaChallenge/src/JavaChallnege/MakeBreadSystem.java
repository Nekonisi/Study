package JavaChallnege;

import java.util.Scanner;

/**
 * @author nl_konishi パン作成システム
 * 
 *         シングルトンパターンで設計
 */
public class MakeBreadSystem {

	/**
	 * フォーマットチェックの定数
	 */
	private final static String FORMATCHECKPATTERN = "[0-9]+";

	/*
	 * ==============================================================
	 * Singletonパターンで設計する
	 * ==============================================================
	 */

	private static MakeBreadSystem makeBreadSystem = null;

	/**
	 * @return MakeBreadSystemのインスタンス
	 */

	/**
	 * パン作成システムのインスタンスを生成します。<br>
	 * <br>
	 * 
	 * @return パン作成システムのインスタンス
	 */
	public static MakeBreadSystem getMakeBreadSystem() {

		if (MakeBreadSystem.makeBreadSystem != null) {
			return MakeBreadSystem.makeBreadSystem;
		}

		MakeBreadSystem.makeBreadSystem = new MakeBreadSystem();

		return MakeBreadSystem.makeBreadSystem;
	}

	/**
	 * コンストラクタ
	 */
	private MakeBreadSystem() {

		// デフォルトコンストラクタを抑止

	}

	/**
	 * メイン処理
	 */
	public void exec() {
		try (Scanner scan = new Scanner(System.in)) {
			int[] breadOrder = new int[2];

			System.out.println("注文するあんパンの個数を入力してください。");
			String inputValue = scan.next();

			if (!checkIntegerValue(inputValue)) {
				throw new Exception("フォーマットエラー: 整数値を入力してください");
			}

			breadOrder[0] = Integer.parseInt(inputValue);

			System.out.println("注文する食パンの個数を入力してください。");
			inputValue = scan.next();

			if (!checkIntegerValue(inputValue)) {
				throw new Exception("フォーマットエラー: 整数値を入力してください");
			}

			breadOrder[1] = Integer.parseInt(inputValue);

			SuperMarket superMarket = SuperMarket.getSuperMarketInstance();

			System.out.println("在庫を表示");
			System.out.println(superMarket.order(breadOrder));

		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			System.out.println("パン作成システムを終了します。");
		}
	}

	/**
	 * @param value
	 * @return フォーマットチェックの成否
	 * 
	 */
	private static boolean checkIntegerValue(String value) {
		return value.matches(FORMATCHECKPATTERN);
	}
}