package JavaChallnege.bread;

/**
 * @author nl_konishi
 * 
 *         あんパンクラス
 */
public class BeanPasteBread implements Bread {

	private String kind = "あんパン";

	/*
	 * (非 Javadoc)
	 * 
	 * @see JavaChallnege.Bread#getKind()
	 */
	@Override
	public String getKind() {
		return this.kind;
	}

	/*
	 * (非 Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		return this.kind;
	}
}
