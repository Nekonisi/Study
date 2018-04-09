
/**
 * @author nl_konishi
 * バーテンダークラス(ディレクター)
 */
public class Bartender {
	
	private Builder builder;
	
	public Bartender(Builder builder) {
		this.builder=builder;
	}
	
	void construct() {
		builder.water(10);
		builder.whiskey(20);
		builder.soda(30);
	}

}
