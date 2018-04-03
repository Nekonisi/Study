public class Sample {
    public static void main(String[] args) {
        int     iNumber1 = 1;
        int     iNumber2 = 2;
        boolean bResult1 = false;
        boolean bResult2 = false;

        // &&
        // 左右両方のオペランドを評価する場合
        // 評価後にインクリメント
        bResult1 = ((1 == iNumber1) && (2 == iNumber2++));          // true
        bResult2 = ((1 == iNumber1) && (2 == iNumber2));            // false
        System.out.println("(" + bResult1 + ", " + bResult2 + ")"); // 値の確認
        System.out.println("(" + iNumber1 + ", " + iNumber2 + ")"); // 値の確認

        // 左オペランドのみ評価がする場合→iNumber2に対する操作は行われない
        bResult1 = ((0 == iNumber1) && (1 == iNumber2--));          // false
        bResult2 = ((0 == iNumber1) && (1 == --iNumber2));          // false
        System.out.println("(" + bResult1 + ", " + bResult2 + ")"); // 値の確認
        System.out.println("(" + iNumber1 + ", " + iNumber2 + ")"); // 値の確認
        
        // ||
        // 左右両方のオペランドを評価する場合
        bResult1 = ((1 != iNumber1) || (2 == --iNumber2));          // true
        bResult2 = ((1 != iNumber1) || (2 != iNumber2));            // false
        System.out.println("(" + bResult1 + ", " + bResult2 + ")"); // 値の確認
        System.out.println("(" + iNumber1 + ", " + iNumber2 + ")"); // 値の確認

        // 左オペランドのみ評価がする場合→iNumber2に対する操作は行われない
        bResult1 = ((0 != iNumber1) || (1 == iNumber2--));          // true
        bResult2 = ((0 != iNumber1) || (1 == --iNumber2));          // true
        System.out.println("(" + bResult1 + ", " + bResult2 + ")"); // 値の確認
        System.out.println("(" + iNumber1 + ", " + iNumber2 + ")"); // 値の確認

        // !
        bResult1 = !(bResult2);
        System.out.println("(" + bResult1 + ", " + bResult2 + ")"); // 値の確認
    }
}
