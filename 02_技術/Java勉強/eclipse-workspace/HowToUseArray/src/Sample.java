public class Sample {
	public static void main(String[] args) {
		// �@ �z��̐錾
		int[] uriage;
		// �A �z��̈�̐���
		uriage = new int[12];
		// �B �z��ւ̒l�̑��
		uriage[2] = 100;
		// �@ �錾�A�A �����A�B ����𓯎��ɍs���ꍇ
		int[] price = { 800, 2500, 200 };
		// �C �z��̗v�f��
		int a = price.length;
		// �R���\�[���֏o�͂��Ēl�̊m�F
		System.out.println("a = " + a);

		// �D �z��̔z��
		int d[][] = { { 1, 2, 3, 4 }, { 5, 6 }, { 9 } };

		// �ȉ��̂悤�ɃA�N�Z�X�����ꍇ�A
		// i = 1�Aj = 2��ArrayIndexOutOfBoundsException����������
		int i = 0, j = 0;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				try {
					System.out.println(" (" + i + ", " + j + ") = " + d[i][j]);
				} catch (ArrayIndexOutOfBoundsException e) {
					// �R���\�[���֏o�͂��Ēl�̊m�F
					System.out.println("i = " + i + ", j = " + j + "��ArrayIndexOutOfBoundsException���������܂����B");
				}
			}
		}

		// �������͈ȉ��̂悤�ɃA�N�Z�X����
		for (i = 0; i < d.length; i++) {
			for (j = 0; j < d[i].length; j++) {
				System.out.println(" (" + i + ", " + j + ") = " + d[i][j]);
			}
		}
	}
}
