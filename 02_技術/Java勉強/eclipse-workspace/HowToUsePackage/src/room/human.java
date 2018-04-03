/**
 * 
 */
/**
 * @author nl_konishi
 *
 */
package room;

public class human {
	// 属性{{
	// 身長
	private int height;
	// 体重
	private int weight;
	// 年齢
	private int age;
	// 性別
	private char sex;
	// 名前
	private String name;
	// }}

	// コンストラクタ{{
	public human(int height, int weight, int age, char sex, String name) {
		this.height = height;
		this.weight = weight;
		this.age = age;
		this.sex = sex;
		this.name = name;
	}
	//}}
	
	public int getAge() {
		return this.age;
	}
	public void introduce() {
		System.out.println("私は" + this.name);
	}
	
	public void eat(int foodWeight) {
		this.weight +=foodWeight;
	}
	
	public void measureWeight() {
		System.out.println(this.name+"の体重は" + this.weight);
	}
	

}