package JavaChallnege.bread;

/**
 * @author nl_konishi
 * 
 *         ����p���N���X
 */
public class BeanPasteBread implements Bread {

	private String kind = "����p��";

	/*
	 * (�� Javadoc)
	 * 
	 * @see JavaChallnege.Bread#getKind()
	 */
	@Override
	public String getKind() {
		return this.kind;
	}

	/*
	 * (�� Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		return this.kind;
	}
}
