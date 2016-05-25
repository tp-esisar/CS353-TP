package game;

public class Plateau {
	
	public int m, n, i, j;
	
	public Plateau (int m, int n, int i, int j) {
		if (i<m && j<n){
			this.m = m;
			this.n = n;
			this.i = i;
			this.j = j;
		}
		else {
			System.out.println("Erreur dans le plateau");
			System.exit(-1);
		}	
	}
	
	public boolean fin () {
		if (i==0 && j==0 && m==1 && n==1)
			return true;
		else
			return false;
	}
	
	public boolean set (int m, int n, int i, int j){
		if (i<m && j<n){
			this.m = m;
			this.n = n;
			this.i = i;
			this.j = j;
			return true;
		}
		else {
			return false;
		}	
	}
	
	public boolean coupe (Sens sens, int a) {
		if (sens == Sens.horizontal) {
			if (0<a && a<m && a<i){
				m = a; 
				i = i-a;
			}
			else if (0<a && a<m && a>=i){
				m = a;
			}		
			return true;
		}
		else if (sens == Sens.vertical) {
			if (0<a && a<n && a<j){
				n = a;
				j = j-a;
			}
			else if (0<a && a<n && a>=j){
				n = a;
			}
			return true;
		}
		return false;
		
	}
	
	public String toString() {
		String s ="Representation du jeu :\n";
		for (int b=0; b<n; b++) {
			for (int a=0; a<m; a++) {
				if (a == i && b == j)
					s = s +"X ";
				else
					s = s +"O ";
			}
			s = s +"\n";
		}				
		return s; 
	}

}
