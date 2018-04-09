
/**
 * @author nl_konishi
 * ビルダーインターフェース
 */
public interface Builder {
	
	void water(int water);
	void soda(int soda);
	void whiskey(int whiskey);
	
	Drink getDrink();

}
