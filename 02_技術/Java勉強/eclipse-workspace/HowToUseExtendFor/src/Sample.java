public class Sample {
    public static void main(String[] args) {
        // �z��̊g��for���[�v�g�p��
        int[] ds = { 10, 20, 30, 40, 50 };
        for (int i : ds) {      // i��ds�̒l����
            System.out.println(i);
        }

        // �z��̔z��̊g��for���[�v�g�p��
        int[][] nns = { { 11, 22, 33 }, { 44, 55 }, { 66 } };
        for (int[] ns : nns) {  // ns��nns�̒l����
            for (int n : ns) {  // n��ns�̒l����
                System.out.println(n);
            }
        }
    }
}
