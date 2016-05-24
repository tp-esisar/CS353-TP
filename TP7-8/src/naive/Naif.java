package naive;

public class Naif {
	
	int tab[][][][];
	public Naif (int m, int n, int i, int j) {
		int dim = Math.max(m, n);
		int dim2 = Math.max(i, j);
		tab = new int[dim+1][dim+1][dim2+1][dim2+1]; 
		for (int a=0; a<m+1; a++)
			for (int b=0; b<n+1; b++)
				for (int c=0; c<i+1; c++)
					for (int d=0; d<j+1; d++)
						tab[a][b][c][d]=-1;
	}
	public Naif(Pateau) {
		super()
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
				maxSucc = f_dyn(m-1,n,i-1,j);
			}
			else {
				maxSucc = f_dyn(1,n,i,j);
			}
		}
		else {
			if(1<=j) {
				maxSucc = f_dyn(m,n-1,i,j-1);
			}
			else {
				maxSucc = f_dyn(m,1,i,j);
			}
		}
		int maxSuccNegatif=42;
		boolean allSuccStrictPositif = true;
		int temp;
		if(m>=2){
			for(int k=1;k<m;k++) {
				if(k<=i) {
					temp = f_dyn(m-k,n,i-k,j);
				}
				else {
					temp = f_dyn(k,n,i,j);
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
					temp = f_dyn(m,n-k,i,j-k);
				}
				else {
					temp = f_dyn(m,k,i,j);
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
		int result;
		if(allSuccStrictPositif) {
			result = -(1+maxSucc);
		}
		else {
			result = 1 - maxSuccNegatif;
		}
		tab[m][n][i][j] = result;
		return result;
	}
	
	private void cacheWriteAccel(int m,int n,int i,int j,int value) {
		tab[m][n][i][j] = value;
		tab[m][n][m-i-1][j] = value;
		tab[m][n][i][n-j-1] = value;
		tab[m][n][m-i-1][n-j-1] = value;
		tab[n][m][j][i] = value;
		tab[n][m][n-j-1][i] = value;
		tab[n][m][j][m-i-1] = value;
		tab[n][m][n-j-1][m-i-1] = value;
	}
	
	public int f_accel(int m,int n,int i,int j) {
		//System.out.println(m+", "+ n+", "+i+", "+ j);
		
		if (tab[m][n][i][j] != -1)
			return tab[m][n][i][j];
		
		if (m==1 && n==1) return 0;
		
		int maxSucc;
		if(m>=2){
			if(1<=i) {
				maxSucc = f_accel(m-1,n,i-1,j);
			}
			else {
				maxSucc = f_accel(1,n,i,j);
			}
		}
		else {
			if(1<=j) {
				maxSucc = f_accel(m,n-1,i,j-1);
			}
			else {
				maxSucc = f_accel(m,1,i,j);
			}
		}
		int maxSuccNegatif=42;
		boolean allSuccStrictPositif = true;
		int temp;
		if(m>=2){
			for(int k=1;k<m;k++) {
				if(k<=i) {
					temp = f_accel(m-k,n,i-k,j);
				}
				else {
					temp = f_accel(k,n,i,j);
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
					temp = f_accel(m,n-k,i,j-k);
				}
				else {
					temp = f_accel(m,k,i,j);
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
		int result;
		if(allSuccStrictPositif) {
			result = -(1+maxSucc);
		}
		else {
			result = 1 - maxSuccNegatif;
		}
		cacheWriteAccel(m,n,i,j,result);
		return result;
	}
	
}


