public class Sample {
    // 素数を数えるプログラム
    public static void main(String[] args) {
        final int   iMaxCount    = 1000;
        int         iTargetNum   = 0;
        int         iDivideNum   = 0;

        // iTargetNumをインクリメントする
        xxxLabel: for (iTargetNum = 1; iTargetNum < iMaxCount; iTargetNum++) {
            // iDivideNumをインクリメントする
            for (iDivideNum = 2; iDivideNum < iTargetNum; iDivideNum++) {
                // 割り切れる値が有る場合は計算を打ち切ってxxxLabelループに戻る
                if ((iTargetNum % iDivideNum) == 0) {
                    continue xxxLabel;
                }
            }

            // 割り切れる値が無い場合は値の表示を行う
            if (iDivideNum == iTargetNum) {
                System.out.println(iTargetNum);
            }
        }
    }
}
