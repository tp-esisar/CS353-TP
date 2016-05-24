package naive;

public class Naif {
	
	protected int tab[][][][];
	protected int m,n,i,j;
	
	public Naif (int m, int n, int i, int j) {
		this.m = m;
		this.n = n;
		this.i = i;
		this.j = j;
		tab = new int[m+1][n+1][i+1][j+1]; 
		for (int a=0; a<m+1; a++)
			for (int b=0; b<n+1; b++)
				for (int c=0; c<i+1; c++)
					for (int d=0; d<j+1; d++)
						tab[a][b][c][d]=-1;
	}
	
	
	public int f_rec(int m,int n,int i,int j) {
		//System.out.println(m+", "+ n+", "+i+", "+ j);
		
		if (m==1 && n==1) return 0;
		
		int maxSucc;
		if(m>=2){
			if(1<=i) {
				maxSucc = f_rec(m-1,n,i-1,j);
			}
			else {
				maxSucc = f_rec(1,n,i,j);
			}
		}
		else {
			if(1<=j) {
				maxSucc = f_rec(m,n-1,i,j-1);
			}
			else {
				maxSucc = f_rec(m,1,i,j);
			}
		}
		int maxSuccNegatif=42;
		boolean allSuccStrictPositif = true;
		int temp;
		if(m>=2){
			for(int k=1;k<m;k++) {
				if(k<=i) {
					temp = f_rec(m-k,n,i-k,j);
				}
				else {
					temp = f_rec(k,n,i,j);
				}
				maxSucc = Math.max(temp, maxSucc);
				if(temp<=0 && allSuccStrictPositif) {
					allSuccStrictPositif = false;
					maxSuccNegatif = temp;
				}
				if(!allSuccStrictPositif) {
					if(temp <= 0) {
						maxSuccNegatif = Math.max(temp,maxSuccNegatif);
					}
				}
			}
		}
		if(n>=2){
			for(int k=1;k<n;k++) {
				if(k<=j) {
					temp = f_rec(m,n-k,i,j-k);
				}
				else {
					temp = f_rec(m,k,i,j);
				}
				maxSucc = Math.max(temp, maxSucc);
				if(temp<=0 && allSuccStrictPositif) {
					allSuccStrictPositif = false;
					maxSuccNegatif = temp;
				}
				if(!allSuccStrictPositif) {
					if(temp <= 0) {
						maxSuccNegatif = Math.max(temp,maxSuccNegatif);
					}
				}
			}
		}
		if(allSuccStrictPositif) {
			return -(1+maxSucc);
		}
		else {
			return 1 - maxSuccNegatif;
		}
	}
	
	public int f_dyn(int m,int n,int i,int j) {
		//System.out.println(m+", "+ n+", "+i+", "+ j);
		
		if (tab[m][n][i][j] != -1)
			return tab[m][n][i][j];
		
		if (m==1 && n==1) return 0;
		
		int maxSucc;
		if(m>=2){
			if(1<=i) {
				maxSucc = tab[m-1][n][i-1][j] = f_dyn(m-1,n,i-1,j);
			}
			else {
				maxSucc = tab[1][n][i][j] = f_dyn(1,n,i,j);
			}
		}
		else {
			if(1<=j) {
				maxSucc = tab[m][n-1][i][j-1] = f_dyn(m,n-1,i,j-1);
			}
			else {
				maxSucc = tab[m][1][i][j] = f_dyn(m,1,i,j);
			}
		}
		int maxSuccNegatif=42;
		boolean allSuccStrictPositif = true;
		int temp;
		if(m>=2){
			for(int k=1;k<m;k++) {
				if(k<=i) {
					temp = tab[m-k][n][i-k][j] = f_dyn(m-k,n,i-k,j);
				}
				else {
					temp = tab[k][n][i][j] = f_dyn(k,n,i,j);
				}
				maxSucc = Math.max(temp, maxSucc);
				if(temp<=0 && allSuccStrictPositif) {
					allSuccStrictPositif = false;
					maxSuccNegatif = temp;
				}
				if(!allSuccStrictPositif) {
					if(temp <= 0) {
						maxSuccNegatif = Math.max(temp,maxSuccNegatif);
					}
				}
			}
		}
		if(n>=2){
			for(int k=1;k<n;k++) {
				if(k<=j) {
					temp = tab[m][n-k][i][j-k] = f_dyn(m,n-k,i,j-k);
				}
				else {
					temp = tab[m][k][i][j] = f_dyn(m,k,i,j);
				}
				maxSucc = Math.max(temp, maxSucc);
				if(temp<=0 && allSuccStrictPositif) {
					allSuccStrictPositif = false;
					maxSuccNegatif = temp;
				}
				if(!allSuccStrictPositif) {
					if(temp <= 0) {
						maxSuccNegatif = Math.max(temp,maxSuccNegatif);
					}
				}
			}
		}
		if(allSuccStrictPositif) {
			return -(1+maxSucc);
		}
		else {
			return 1 - maxSuccNegatif;
		}
	}
}
