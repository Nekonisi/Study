
public class Student {

	// ����
	String name;
	char schoolRecord;

	// �R���X�g���N�^
	public Student() {
		this.name = "������";
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
		this.name = "������";
		this.schoolRecord = schoolRecord;
	}

	public void introduce(){
		System.out.print("���̖��O��" + this.name + "�ł��B\n" + "���̐��т́u" + this.schoolRecord + "�v�ł��B\n");
	}
}
