package JavaChallnege.bread;

public enum BreadKind {

	BEANPASTEBREAD("����p��"), PLAINBREAD("�H�p��");

	// �t�B�[���h�̒�`
	public String name;

	// �R���X�g���N�^�̒�`
	private BreadKind(String name) {
		this.name = name;
	}
}
