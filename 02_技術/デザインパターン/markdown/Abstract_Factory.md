Abstract Factory
===

## 目的

- 状況に応じて、プログラムの一部を丸ごと交換したい。

## 背景(問題)

- 特定のOSやDBMSに依存した機能を考えた時に、指定したOSやDBMSで挙動を変える。

## 効果

- 状況に応じて挙動が変わるプログラムを作成できる。

## 概要

<code>
	public abstract class OsDbFactory{
	    // 抽象メソッド
	    public abstract OS createOS();
	    public abstract DBMS createDBMS();
	
	    // ファクトリクラスのオブジェクトを返すメソッド
	    public static OsDbFactory getFactory(String db) {
	        if (db.equals("WinSql") {
	            return new WinSqlFactory();
	        }
	        else if (db.equals("UnixOracle")) {
	            return new UnixOracleFactory();
	        }
	        else {
	            return null;
	        }
	    }
	}

	public static void main(String args[]){

	// 変数envに環境を示す文字列が格納されているとする
	OsDbFactory f = OsDbFactory.getFactory(env);

	// 環境に応じたクラスのオブジェクトを取得する
	OS sys = f.createOS();
	DBMS db = f.createDBMS();
}
</code>

OsDbFactory.getFactoryで適切なファクトリクラスのオブジェクトを取得し、
OSクラスのオブジェクトと、DBMSクラスのオブジェクトの作成を行う。

以上
