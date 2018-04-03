public class Sample {
    public static void main(String[] args) {
        // 配列の拡張forループ使用例
        int[] ds = { 10, 20, 30, 40, 50 };
        for (int i : ds) {      // iにdsの値を代入
            System.out.println(i);
        }

        // 配列の配列の拡張forループ使用例
        int[][] nns = { { 11, 22, 33 }, { 44, 55 }, { 66 } };
        for (int[] ns : nns) {  // nsにnnsの値を代入
            for (int n : ns) {  // nにnsの値を代入
                System.out.println(n);
            }
        }
    }
}
