package naive;

public class Naif {
	public static int f(int m, int n, int i, int j) {
		System.out.println(m+", "+ n+", "+i+", "+ j);
		if (m==i+1 && n==j+1) return 0;
		int maxSuccPositif;
		if(m==1) {
			if(1<=j) {
				maxSuccPositif = f(m,n-1,i,j-1);
			}
			else {
				maxSuccPositif = f(m,1,i,j);
			}
		}
		else {
			if(1<=i) {
				maxSuccPositif = f(m-1,n,i-1,j);
			}
			else {
				maxSuccPositif = f(1,n,i,j);
			}
		}
		int maxSuccNegatif=0;
		boolean allSuccStrictPositif = true;
		int temp;
		for(int k=2;k<m;k++) {
			if(k<=i) {
				temp = f(m-k,n,i-k,j);
			}
			else {
				temp = f(k,n,i,j);
			}
			if(temp<=0 && allSuccStrictPositif) {
				allSuccStrictPositif = false;
				maxSuccNegatif = temp;
			}
			
			
			if(!allSuccStrictPositif) {
				if(temp <= 0) {
					maxSuccNegatif = Math.max(temp,maxSuccNegatif);
				}
			}
			else {
				maxSuccPositif = Math.max(temp, maxSuccPositif);
			}
		}
		for(int k=1;k<n;k++) {
			if(k<=j) {
				temp = f(m,n-k,i,j-k);
			}
			else {
				temp = f(m,k,i,j);
			}
			if(temp<=0 && allSuccStrictPositif) {
				allSuccStrictPositif = false;
				maxSuccNegatif = temp;
			}
			
			
			if(!allSuccStrictPositif) {
				if(temp <= 0) {
					maxSuccNegatif = Math.max(temp,maxSuccNegatif);
				}
			}
			else {
				maxSuccPositif = Math.max(temp, maxSuccPositif);
			}
		}
		if(allSuccStrictPositif) {
			return -(1+maxSuccPositif);
		}
		else {
			return 1 - maxSuccNegatif;
		}
	}
}
