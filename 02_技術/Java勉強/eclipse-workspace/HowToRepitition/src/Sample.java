public class Sample {
    // �f���𐔂���v���O����
    public static void main(String[] args) {
        final int   iMaxCount    = 1000;
        int         iTargetNum   = 0;
        int         iDivideNum   = 0;

        // iTargetNum���C���N�������g����
        xxxLabel: for (iTargetNum = 1; iTargetNum < iMaxCount; iTargetNum++) {
            // iDivideNum���C���N�������g����
            for (iDivideNum = 2; iDivideNum < iTargetNum; iDivideNum++) {
                // ����؂��l���L��ꍇ�͌v�Z��ł��؂���xxxLabel���[�v�ɖ߂�
                if ((iTargetNum % iDivideNum) == 0) {
                    continue xxxLabel;
                }
            }

            // ����؂��l�������ꍇ�͒l�̕\�����s��
            if (iDivideNum == iTargetNum) {
                System.out.println(iTargetNum);
            }
        }
    }
}
