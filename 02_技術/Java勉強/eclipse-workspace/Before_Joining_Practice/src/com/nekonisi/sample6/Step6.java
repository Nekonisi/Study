package com.nekonisi.sample6;

/**
 * @author nl_konishi
 *
 */
public class Step6 {

	/**
	 * @param args コマンドライン引数
	 * Step6のメインクラス
	 */
	public static void main(String[] args) {
		try {
			if (args.length == 0) {
				
			} else if (args.length == 0) {
				
			} else {
				throw new NumberFormatException("コマンドライン引数が多すぎます。死ね");
			}
			
			// Step6 start here
			Exec exec = new Exec();
			exec.exec();
					
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("例外が発生したんで、詳細表示してから、プログラム終了するわ。¥r¥n¥r¥n");
			System.out.println("ほな、また……。¥r¥n¥r¥n");
			e.printStackTrace();
			return;
		}
	}

}
