package JavaChallnege.bread;

public enum BreadKind {

	BeanPasteBread("����p��"), PlainBread("�H�p��");

	// �t�B�[���h�̒�`
	public String name;

	// �R���X�g���N�^�̒�`
	private BreadKind(String name) {
		this.name = name;
	}
}
