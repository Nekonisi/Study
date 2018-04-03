
public class Student {

	// 属性
	String name;
	char schoolRecord;

	// コンストラクタ
	public Student() {
		this.name = "名無し";
		this.schoolRecord = 'E';
	}

	public Student(String name) {
		this.name = name;
		this.schoolRecord = 'E';
	}

	public Student(String name, char schoolRecord) {
		this.name = name;
		this.schoolRecord = schoolRecord;
	}

	public Student(char schoolRecord) {
		this.name = "名無し";
		this.schoolRecord = schoolRecord;
	}

	public void introduce(){
		System.out.print("私の名前は" + this.name + "です。\n" + "私の成績は「" + this.schoolRecord + "」です。\n");
	}
}
