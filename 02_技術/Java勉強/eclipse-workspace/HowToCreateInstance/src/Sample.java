
public class Sample {

		    public static void main(String[] args) {
		        // 基本データ型の場合
		        int x = 10;
		        int y = x; // この時点でx = 10、y = 10
		        // この後にxを変更してもyの値は変わらない
		        x = 20; // yの値は20にならない

		        // コンソールへ出力して値の確認
		        System.out.println("x = " + x + ", y = " + y);

		        // 参照型の場合
		        // Hogeクラスの参照型変数h1の宣言
		        Hoge h1 = null;
		        // Hogeオブジェクトの作成(インスタンス化)
		        h1 = new Hoge();
		        // Hogeクラスの参照型変数h2の宣言と参照先をh1と同じに設定
		        Hoge h2 = new Hoge();
		        // h2でHogeオブジェクトに対して操作を行うと、
		        // h1からHogeオブジェクトを参照しても変更後の値が参照できる
		        h2.iHoge = 1000;

		        // コンソールへ出力して値の確認
		        System.out.println("h1.iHoge = " + h1.iHoge + ", h2.iHoge = " + h2.iHoge);

		        // Stringの場合
		        // String a = new String("HELLO")と同じ処理
		        // ※パフォーマンスが遅くなるので推奨されていない
		        String a = "HELLO";
		        String b = "JAVA";

		        b = a; // aもbも"HELLO"という値を参照している

		        // b = new String("JAVA")と同じ処理
		        // "HELLO"という文字列に対して変更しているわけではない
		        b = "JAVA";

		        // コンソールへ出力して値の確認
		        System.out.println("a = " + a + ", b = " + b);
		    }
		}

		class Hoge {
		    int iHoge = 0;

	}

