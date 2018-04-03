public class Sample {
	public static void main(String[] args) {
		// 基本データ型のキャストの例
		// ラッパークラスのフィールドを利用して、型で表現できる最大値を設定
		short sNumber = Short.MAX_VALUE;
		int iNumber = Integer.MAX_VALUE;
		long lNumber = Long.MAX_VALUE;

		// 精度の低い型(short)から、精度の高い型(int)へのキャスト
		iNumber = sNumber; // キャスト演算子は不要
		System.out.println("(" + sNumber + ", " + iNumber + ", " + lNumber + ")");

		// 精度の高い型(long)から、精度の低い型(int)へのキャスト
		iNumber = (int) lNumber; // キャスト演算子が必要
		System.out.println("(" + sNumber + ", " + iNumber + ", " + lNumber + ")");

		// 参照型のキャストの例
		Object objReference = null;
		String strString1 = "casting conversion test 1";
		Integer intInteger = Integer.MAX_VALUE;

		// 子クラスから親クラスへのキャスト
		objReference = strString1; // キャスト演算子は不要
		// 値の確認
		System.out.println(objReference.toString());

		// 親クラスから子クラスへのキャスト
		strString1 = (String) objReference; // キャスト演算子が必要
		// 値の確認
		System.out.println(strString1);

		// 無関係のクラスへのキャスト(String→Integer)
		// intInteger = (Integer) strString2; // コンパイル時にエラーとなる

		// 親クラスが共通な場合で、親クラス経由のキャスト
		if (objReference instanceof Integer) {
			// objReferenceはStringのオブジェクトを参照しているので、
			// 実行した場合、ClassCastExceptionが発生する
			intInteger = (Integer) objReference;
		} else {
			System.out.println("objReferenceはInteger型のオブジェクトを参照していません。");
		}
	}
}
