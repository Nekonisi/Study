
/**
 * @author nl_konishi
 * 
 *         メインクラス
 *
 */
public class Main {

	/**
	 * @param args
	 *            コマンドライン引数
	 * 
	 *            ここから始まる
	 */
	public static void main(String args[]) {
		try {
			Exec exec = Exec.GetInstance();
			exec.main();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
