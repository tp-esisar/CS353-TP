package game;

import naive.Naif;

public class Plateau extends Naif{
	
	public Plateau (int m, int n, int i, int j) {
		super(m,n,i,j);
	}
	
	public boolean fin () {
		if (i==0 && j==0 && m==1 && n==1)
			return true;
		else
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
