package JavaChallnege.bread;

public class PlainBread implements Bread {

	private String kind = "�H�p��";

	@Override
	public String getKind() {
		return this.kind;
	}

	@Override
	public String toString() {
		return this.kind;
	}
}
