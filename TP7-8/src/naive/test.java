package naive;

public class test {

	public static void main(String[] args) throws InterruptedException {
		/**Récursif**/
		int m = 10; int n = 7; int i = 5; int j = 3;
		Naif naif = new Naif(m,n,i,j);
		
		long debut = System.currentTimeMillis();
		//System.out.println(naif.f_rec(m,n,i,j));
		long step = System.currentTimeMillis();
		//System.out.println(naif.f_dyn(m,n,i,j));
		long fin = System.currentTimeMillis();
		System.out.println("Temps (secondes) : \n- Récursif : " + (step-debut)/1000 + "\n- Dynamique : " + (fin-step)/1000 ); 
		
		/**Dynamique**/
		m = 100; n = 100; i = 48; j = 52;
		Naif naif2 = new Naif(m,n,i,j);
		
		debut = System.currentTimeMillis();
		System.out.println(naif2.f_dyn(m,n,i,j));
		fin = System.currentTimeMillis();
		System.out.println("Temps (secondes) : \n- Dynamique : " + (fin-debut)/1000 );
		
		/**Suite**/
		m = 127; n = 127;
		Naif naif3 = new Naif(m,n,m-1,n-1);
		
		debut = System.currentTimeMillis();
		for (i=0; i<m; i++)
			for(j=0; j<n; j++)
				if (naif3.f_dyn(m,n,i,j) == 127)
					System.out.println("("+i+","+j+")");
		fin = System.currentTimeMillis();
		System.out.println("Temps (secondes) : \n- Dynamique : " + (fin-debut)/1000 );
		
		
		
	}

}
