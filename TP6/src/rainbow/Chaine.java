package rainbow;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Chaine {
	private MessageDigest digest = null;
	
	public Chaine(){
		try {
			digest = MessageDigest.getInstance("MD5");
		} catch (NoSuchAlgorithmException e) {
			System.out.println("Erreur d'initialisation du cryptage MD5");
			System.exit(1);
		}
	}
	
	public int CalculChaine (int i, int px) {
		byte[] hash;
				
		for ( ; i<1000; i++) {
			hash = md5(px);
			px = reduction(hash, i);
			//System.out.println("- "+i +" / "+ px);
		}
		
		return px;
	}
	
	public int reduction(byte[] hash, int num) {
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
	
	public byte[] md5(int px) {
		return digest.digest(String.format("%06d", px) .getBytes());
	}
}
