package rainbow;

import java.io.Serializable;

public class Noeud implements Serializable {
	private static final long serialVersionUID = 1L;
	
	private int P999;
	private int PX;
	
	public int getP999() {
		return P999;
	}
	public void setP999(int p999) {
		P999 = p999;
	}
	public int getPX() {
		return PX;
	}
	public void setPX(int pX) {
		PX = pX;
	}
	
}
