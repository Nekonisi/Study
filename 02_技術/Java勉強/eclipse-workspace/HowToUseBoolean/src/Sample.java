public class Sample {
    public static void main(String[] args) {
        int     iNumber1 = 1;
        int     iNumber2 = 2;
        boolean bResult1 = false;
        boolean bResult2 = false;

        // &&
        // ���E�����̃I�y�����h��]������ꍇ
        // �]����ɃC���N�������g
        bResult1 = ((1 == iNumber1) && (2 == iNumber2++));          // true
        bResult2 = ((1 == iNumber1) && (2 == iNumber2));            // false
        System.out.println("(" + bResult1 + ", " + bResult2 + ")"); // �l�̊m�F
        System.out.println("(" + iNumber1 + ", " + iNumber2 + ")"); // �l�̊m�F

        // ���I�y�����h�̂ݕ]��������ꍇ��iNumber2�ɑ΂��鑀��͍s���Ȃ�
        bResult1 = ((0 == iNumber1) && (1 == iNumber2--));          // false
        bResult2 = ((0 == iNumber1) && (1 == --iNumber2));          // false
        System.out.println("(" + bResult1 + ", " + bResult2 + ")"); // �l�̊m�F
        System.out.println("(" + iNumber1 + ", " + iNumber2 + ")"); // �l�̊m�F
        
        // ||
        // ���E�����̃I�y�����h��]������ꍇ
        bResult1 = ((1 != iNumber1) || (2 == --iNumber2));          // true
        bResult2 = ((1 != iNumber1) || (2 != iNumber2));            // false
        System.out.println("(" + bResult1 + ", " + bResult2 + ")"); // �l�̊m�F
        System.out.println("(" + iNumber1 + ", " + iNumber2 + ")"); // �l�̊m�F

        // ���I�y�����h�̂ݕ]��������ꍇ��iNumber2�ɑ΂��鑀��͍s���Ȃ�
        bResult1 = ((0 != iNumber1) || (1 == iNumber2--));          // true
        bResult2 = ((0 != iNumber1) || (1 == --iNumber2));          // true
        System.out.println("(" + bResult1 + ", " + bResult2 + ")"); // �l�̊m�F
        System.out.println("(" + iNumber1 + ", " + iNumber2 + ")"); // �l�̊m�F

        // !
        bResult1 = !(bResult2);
        System.out.println("(" + bResult1 + ", " + bResult2 + ")"); // �l�̊m�F
    }
}
