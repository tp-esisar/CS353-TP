package rainbow;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Chaine {
	
	int CalculChaine (int px) {
		byte[] hash;
		
		MessageDigest digest = null;
		try {
			digest = MessageDigest.getInstance("MD5");
		} catch (NoSuchAlgorithmException e) {
			System.out.println("Erreur d'initialisation du cryptage MD5");
			System.exit(1);
		}
		
		for (int i=0; i<1000; i++) {
			hash = digest.digest(Integer.toString(px).getBytes());
			px = reduction(hash, i);
		}
		
		return px;
	}
	
	int reduction(byte[] hash, int num) {
		int res = num;
		int mult = 1;
		for (int i = 0; i < 4; i++) {
			res = res + mult * hash[i];
			mult = mult * 256;
		}
		if (res < 0) {
			res = -res;
		}
		res = res % 1000000;
		return res;
	}
	
	
	
	
}
