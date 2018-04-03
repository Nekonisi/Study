public class Sample {
	public static void main(String[] args) {
		// ① 配列の宣言
		int[] uriage;
		// ② 配列領域の生成
		uriage = new int[12];
		// ③ 配列への値の代入
		uriage[2] = 100;
		// ① 宣言、② 生成、③ 代入を同時に行う場合
		int[] price = { 800, 2500, 200 };
		// ④ 配列の要素数
		int a = price.length;
		// コンソールへ出力して値の確認
		System.out.println("a = " + a);

		// ⑤ 配列の配列
		int d[][] = { { 1, 2, 3, 4 }, { 5, 6 }, { 9 } };

		// 以下のようにアクセスした場合、
		// i = 1、j = 2でArrayIndexOutOfBoundsExceptionが発生する
		int i = 0, j = 0;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				try {
					System.out.println(" (" + i + ", " + j + ") = " + d[i][j]);
				} catch (ArrayIndexOutOfBoundsException e) {
					// コンソールへ出力して値の確認
					System.out.println("i = " + i + ", j = " + j + "でArrayIndexOutOfBoundsExceptionが発生しました。");
				}
			}
		}

		// 正しくは以下のようにアクセスする
		for (i = 0; i < d.length; i++) {
			for (j = 0; j < d[i].length; j++) {
				System.out.println(" (" + i + ", " + j + ") = " + d[i][j]);
			}
		}
	}
}
