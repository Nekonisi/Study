package human;

// �l�ԃN���X
public class Human {

	// ����{{
	// �g��
	private int height;
	// �̏d
	private int weight;
	// �N��
	private int age;
	// ����
	private char sex;
	// ���O
	private String name;
	// }}

	// �R���X�g���N�^{{
	public Human(int height, int weight, int age, char sex, String name) {
		this.height = height;
		this.weight = weight;
		this.age = age;
		this.sex = sex;
		this.name = name;
	}
	// }}

	public int getAge() {
		return this.age;
	}

	public void introduce() {
		System.out.println("����" + this.name);
	}

	public void eat(int foodWeight) {
		this.weight += foodWeight;
	}

	public void measureWeight() {
		System.out.println(this.name + "�̑̏d��" + this.weight);
	}

}
