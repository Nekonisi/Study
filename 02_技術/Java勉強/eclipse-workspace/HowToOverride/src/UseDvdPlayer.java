// �X�[�p�[�N���X
class Dvdplayer {
	public void play1() {
		System.out.println("�X�[�p�[�N���Xplay1���\�b�h���s");
	}

	public void play2() {
		System.out.println("�X�[�p�[�N���Xplay2���\�b�h���s");
	}

	private void play3() {
		System.out.println("�X�[�p�[�N���Xplay3���\�b�h���s");
	}

	public void test1() {
		System.out.println("�X�[�p�[�N���Xtest1���\�b�h���s");
		play1();
		play2();
		play3();
	}

	final public void test2() { // fianl�Ȃ̂ŁA�I�[�o�[���C�h�ł��Ȃ����\�b�h
		System.out.println("�X�[�p�[�N���Xtest2���\�b�h���s");
		play1();
		play2();
		play3();
	}
}

// �T�u�N���X
class Dvdrecorder extends Dvdplayer {
	// �X�[�p�[�N���X�Ɠ������O�A�߂�l�A�����̃��\�b�h
	public void play1() {
		System.out.println("�T�u�N���Xplay1���\�b�h���s");
	}

	// private�Ȃ̂ŁA�X�[�p�[�N���X��play3�Ƃ͕ʂ̃��\�b�h�ƂȂ�
	private void play3() {
		System.out.println("�T�u�N���Xplay3���\�b�h���s");
	}

	public void test1() {
		System.out.println("�T�u�N���Xtest1���\�b�h���s");
		play1();
		play2();
		play3();
	}
}

// Dvdplayer�ADvdrecorder�𗘗p����N���X
public class UseDvdPlayer {
	public static void main(String[] args) {
		Dvdplayer obj1 = new Dvdplayer(); // �X�[�p�[�N���X�̃I�u�W�F�N�g�𐶐�
		obj1.play1(); // �X�[�p�[�N���X�̃��\�b�h�����s
		obj1.play2(); // �X�[�p�[�N���X�̃��\�b�h�����s
		obj1.test1(); // �X�[�p�[�N���X�̃��\�b�h�����s
		obj1.test2(); // �X�[�p�[�N���X�̃��\�b�h�����s

		Dvdrecorder obj2 = new Dvdrecorder(); // �T�u�N���X�̃I�u�W�F�N�g�𐶐�
		obj2.play1(); // �I�[�o�[���C�h�������\�b�h�����s
		obj2.play2(); // �X�[�p�[�N���X�̃��\�b�h�����s
		obj2.test1(); // �I�[�o�[���C�h�������\�b�h�����s
		obj2.test2(); // �X�[�p�[�N���X�̃��\�b�h�����s

		// �T�u�N���X�̃I�u�W�F�N�g���X�[�p�[�N���X�ŎQ��
		Dvdplayer obj3 = new Dvdrecorder();
		obj3.play1(); // �I�[�o�[���C�h�������\�b�h�����s
		obj3.play2(); // �X�[�p�[�N���X�̃��\�b�h�����s
		obj3.test1(); // �I�[�o�[���C�h�������\�b�h�����s
		obj3.test2(); // �X�[�p�[�N���X�̃��\�b�h�����s
	}
}
