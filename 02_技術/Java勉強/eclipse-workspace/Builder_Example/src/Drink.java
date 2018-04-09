
/**
 * @author nl_konishi
 * 飲み物クラス
 */
public class Drink {
	
	private int whiskey; // ウイスキーの量（cc）
    private int soda; // 炭酸水の量（cc）
    private int water; // 水の量（cc）

    public void getRecipe() {
    	System.out.println("Whiskey: " + this.whiskey);
    	System.out.println("soda: " + this.soda);
    	System.out.println("water: " + this.water);
	}
    
    
}
