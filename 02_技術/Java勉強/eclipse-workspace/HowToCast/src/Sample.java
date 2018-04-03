public class Sample {
	public static void main(String[] args) {
		// ��{�f�[�^�^�̃L���X�g�̗�
		// ���b�p�[�N���X�̃t�B�[���h�𗘗p���āA�^�ŕ\���ł���ő�l��ݒ�
		short sNumber = Short.MAX_VALUE;
		int iNumber = Integer.MAX_VALUE;
		long lNumber = Long.MAX_VALUE;

		// ���x�̒Ⴂ�^(short)����A���x�̍����^(int)�ւ̃L���X�g
		iNumber = sNumber; // �L���X�g���Z�q�͕s�v
		System.out.println("(" + sNumber + ", " + iNumber + ", " + lNumber + ")");

		// ���x�̍����^(long)����A���x�̒Ⴂ�^(int)�ւ̃L���X�g
		iNumber = (int) lNumber; // �L���X�g���Z�q���K�v
		System.out.println("(" + sNumber + ", " + iNumber + ", " + lNumber + ")");

		// �Q�ƌ^�̃L���X�g�̗�
		Object objReference = null;
		String strString1 = "casting conversion test 1";
		Integer intInteger = Integer.MAX_VALUE;

		// �q�N���X����e�N���X�ւ̃L���X�g
		objReference = strString1; // �L���X�g���Z�q�͕s�v
		// �l�̊m�F
		System.out.println(objReference.toString());

		// �e�N���X����q�N���X�ւ̃L���X�g
		strString1 = (String) objReference; // �L���X�g���Z�q���K�v
		// �l�̊m�F
		System.out.println(strString1);

		// ���֌W�̃N���X�ւ̃L���X�g(String��Integer)
		// intInteger = (Integer) strString2; // �R���p�C�����ɃG���[�ƂȂ�

		// �e�N���X�����ʂȏꍇ�ŁA�e�N���X�o�R�̃L���X�g
		if (objReference instanceof Integer) {
			// objReference��String�̃I�u�W�F�N�g���Q�Ƃ��Ă���̂ŁA
			// ���s�����ꍇ�AClassCastException����������
			intInteger = (Integer) objReference;
		} else {
			System.out.println("objReference��Integer�^�̃I�u�W�F�N�g���Q�Ƃ��Ă��܂���B");
		}
	}
}
