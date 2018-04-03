
public class Main {

	public static void main(String[] args) {
		Student yamada = new Student("山田太郎");
		Student tanaka = new Student("田中太郎",'B');
		Student nanasi = new Student();
		Student aaa = new Student('D');
		
		yamada.introduce();
		tanaka.introduce();
		nanasi.introduce();
		aaa.introduce();
		
		
	}
}
