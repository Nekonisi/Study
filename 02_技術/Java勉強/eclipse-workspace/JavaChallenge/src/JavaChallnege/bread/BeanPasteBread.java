package JavaChallnege.bread;

/**
 * @author nl_konishi
 * 
 *         ����p���N���X
 */
public class BeanPasteBread implements Bread {

	private static final String KIND = "����p��";

	/*
	 * (�� Javadoc)
	 * 
	 * @see JavaChallnege.Bread#getKind()
	 */
	@Override
	public String getKind() {
		return BeanPasteBread.KIND;
	}

	/*
	 * (�� Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		return BeanPasteBread.KIND;
	}
}
