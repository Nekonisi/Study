
public class Sample {

		    public static void main(String[] args) {
		        // ��{�f�[�^�^�̏ꍇ
		        int x = 10;
		        int y = x; // ���̎��_��x = 10�Ay = 10
		        // ���̌��x��ύX���Ă�y�̒l�͕ς��Ȃ�
		        x = 20; // y�̒l��20�ɂȂ�Ȃ�

		        // �R���\�[���֏o�͂��Ēl�̊m�F
		        System.out.println("x = " + x + ", y = " + y);

		        // �Q�ƌ^�̏ꍇ
		        // Hoge�N���X�̎Q�ƌ^�ϐ�h1�̐錾
		        Hoge h1 = null;
		        // Hoge�I�u�W�F�N�g�̍쐬(�C���X�^���X��)
		        h1 = new Hoge();
		        // Hoge�N���X�̎Q�ƌ^�ϐ�h2�̐錾�ƎQ�Ɛ��h1�Ɠ����ɐݒ�
		        Hoge h2 = new Hoge();
		        // h2��Hoge�I�u�W�F�N�g�ɑ΂��đ�����s���ƁA
		        // h1����Hoge�I�u�W�F�N�g���Q�Ƃ��Ă��ύX��̒l���Q�Ƃł���
		        h2.iHoge = 1000;

		        // �R���\�[���֏o�͂��Ēl�̊m�F
		        System.out.println("h1.iHoge = " + h1.iHoge + ", h2.iHoge = " + h2.iHoge);

		        // String�̏ꍇ
		        // String a = new String("HELLO")�Ɠ�������
		        // ���p�t�H�[�}���X���x���Ȃ�̂Ő�������Ă��Ȃ�
		        String a = "HELLO";
		        String b = "JAVA";

		        b = a; // a��b��"HELLO"�Ƃ����l���Q�Ƃ��Ă���

		        // b = new String("JAVA")�Ɠ�������
		        // "HELLO"�Ƃ���������ɑ΂��ĕύX���Ă���킯�ł͂Ȃ�
		        b = "JAVA";

		        // �R���\�[���֏o�͂��Ēl�̊m�F
		        System.out.println("a = " + a + ", b = " + b);
		    }
		}

		class Hoge {
		    int iHoge = 0;

	}

