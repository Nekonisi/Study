import room.*;

public class Main {

	public static void main(String[] args) {
		
		human nekonisi = new human(178, 60, 26, 'íj', "Ç±Ç§Ç∑ÇØ");
		human ketyan = new human(140, 42, 36, 'èó', "ÇØÅ[ÇøÇ·ÇÒ");
		
		Food potato = new Food(10);
		
		nekonisi.introduce();
		nekonisi.measureWeight();
		
		ketyan.introduce();
		ketyan.measureWeight();
		
		for (int i = 0; i < nekonisi.getAge(); i++) {
			nekonisi.eat(potato.getFoodWeight());;
		}
		ketyan.eat(potato.getFoodWeight());
		
		nekonisi.measureWeight();
		ketyan.measureWeight();
		
	}
}
