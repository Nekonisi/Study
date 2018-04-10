/**
 * @author kousuke 実行クラス シングルトンパターンで設計
 */
public class Exec {

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

}
