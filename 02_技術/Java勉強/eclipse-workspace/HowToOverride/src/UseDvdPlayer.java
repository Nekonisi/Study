// スーパークラス
class Dvdplayer {
	public void play1() {
		System.out.println("スーパークラスplay1メソッド実行");
	}

	public void play2() {
		System.out.println("スーパークラスplay2メソッド実行");
	}

	private void play3() {
		System.out.println("スーパークラスplay3メソッド実行");
	}

	public void test1() {
		System.out.println("スーパークラスtest1メソッド実行");
		play1();
		play2();
		play3();
	}

	final public void test2() { // fianlなので、オーバーライドできないメソッド
		System.out.println("スーパークラスtest2メソッド実行");
		play1();
		play2();
		play3();
	}
}

// サブクラス
class Dvdrecorder extends Dvdplayer {
	// スーパークラスと同じ名前、戻り値、引数のメソッド
	public void play1() {
		System.out.println("サブクラスplay1メソッド実行");
	}

	// privateなので、スーパークラスのplay3とは別のメソッドとなる
	private void play3() {
		System.out.println("サブクラスplay3メソッド実行");
	}

	public void test1() {
		System.out.println("サブクラスtest1メソッド実行");
		play1();
		play2();
		play3();
	}
}

// Dvdplayer、Dvdrecorderを利用するクラス
public class UseDvdPlayer {
	public static void main(String[] args) {
		Dvdplayer obj1 = new Dvdplayer(); // スーパークラスのオブジェクトを生成
		obj1.play1(); // スーパークラスのメソッドを実行
		obj1.play2(); // スーパークラスのメソッドを実行
		obj1.test1(); // スーパークラスのメソッドを実行
		obj1.test2(); // スーパークラスのメソッドを実行

		Dvdrecorder obj2 = new Dvdrecorder(); // サブクラスのオブジェクトを生成
		obj2.play1(); // オーバーライドしたメソッドを実行
		obj2.play2(); // スーパークラスのメソッドを実行
		obj2.test1(); // オーバーライドしたメソッドを実行
		obj2.test2(); // スーパークラスのメソッドを実行

		// サブクラスのオブジェクトをスーパークラスで参照
		Dvdplayer obj3 = new Dvdrecorder();
		obj3.play1(); // オーバーライドしたメソッドを実行
		obj3.play2(); // スーパークラスのメソッドを実行
		obj3.test1(); // オーバーライドしたメソッドを実行
		obj3.test2(); // スーパークラスのメソッドを実行
	}
}
