
public class HighballBuilder implements Builder{

	private Drink drink;
	public HighballBuilder() {
		this.drink=new Drink();
		
	}
	@Override
	public void water(int water) {
		
	}

	@Override
	public void soda(int soda) {
		
	}

	@Override
	public void whiskey(int whiskey) {
		
	}

	@Override
	public Drink getDrink() {
		return null;
	}

}
