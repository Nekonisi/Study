package JavaChallnege;

/**
 * @author nl_konishi
 *
 *         メインクラス
 */
public class Main {

	/**
	 * @param args
	 *            コマンドライン引数
	 * 
	 *            メイン処理
	 */
	public static void main(String args[]) {
		MakeBreadSystem makeBreadSystem = MakeBreadSystem.getMakeBreadSystem();

		// メイン処理
		makeBreadSystem.exec();
	}

}
