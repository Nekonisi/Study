package JavaChallnege.bread;

public enum BreadKind {

	BEANPASTEBREAD("あんパン"), PLAINBREAD("食パン");

	// フィールドの定義
	public String name;

	// コンストラクタの定義
	private BreadKind(String name) {
		this.name = name;
	}
}
