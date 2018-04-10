package JavaChallnege.bread;

/**
 * @author nl_konishi
 * 
 *         あんパンクラス
 */
public class BeanPasteBread implements Bread {

	private static final String KIND = "あんパン";

	/*
	 * (非 Javadoc)
	 * 
	 * @see JavaChallnege.Bread#getKind()
	 */
	@Override
	public String getKind() {
		return BeanPasteBread.KIND;
	}

	/*
	 * (非 Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		return BeanPasteBread.KIND;
	}
}
