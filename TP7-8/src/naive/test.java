package naive;

public class test {

	public static void main(String[] args) {
		int m = 10;
		int n = 7;
		int i = 5;
		int j = 3;
		Naif naif = new Naif(m,n,i,j);
		System.out.println(naif.f_rec(m,n,i,j));
	}

}
