package JavaChallnege.bread;

public class PlainBread implements Bread {

	private final static String KIND = "Hƒpƒ“";

	@Override
	public String getKind() {
		return PlainBread.KIND;
	}

	@Override
	public String toString() {
		return PlainBread.KIND;
	}
}
