package prog;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.security.NoSuchAlgorithmException;

import javax.xml.bind.DatatypeConverter;

import rainbow.Chaine;
import rainbow.HashTable;

public class Main {
	
	public static boolean compare(byte[] a, byte[] b) {
		for(int i=0;i<a.length;i++) {
			if(a[i] != b[i])
				return false;
		}
		return true;
	}

	public static void main(String[] args) throws NoSuchAlgorithmException {
		/*MessageDigest digest = MessageDigest.getInstance("MD5");
		String toHash = "toto";
		String cle = "f71dbe52628a3f83a77ab494817525c6";
		byte[] hash = digest.digest(toHash.getBytes());
		byte[] test = DatatypeConverter.parseHexBinary(cle);*/
		
		/*byte[] temp = chaine.md5(712333);
		byte[] mdp = args[0].getBytes();*/
		
		HashTable table = null;
		Chaine chaine = new Chaine();
			
		if (args.length!=1) {
		       System.out.println("Argument : mdp en md5 !");
		       System.exit(0);
		}

		System.out.println("Importation du fichier ...");
		File file = new File("rainbow.table");
		ObjectInputStream lecture;
		try {
			lecture = new ObjectInputStream( new FileInputStream(file));
			table = (HashTable) lecture.readObject();
	        lecture.close();
		} catch (IOException | ClassNotFoundException e) {
			System.out.println("Erreur lors de l'�criture du fichier");
			e.printStackTrace();
		}
		
		String cle = "cec72301f148e7b0a8a79d3612cb24ba";
		
		System.out.println("D�codage du mot de passe ...");
		int P0, px = 0;
		int i = 999;
		byte[] mdp = DatatypeConverter.parseHexBinary(cle);
		boolean find = false;
		
		while(!find) {
			do {
				px = chaine.reduction(mdp, i);
				px = chaine.CalculChaine(i+1, px);
				i--;
			} while((P0 = table.acces(px)) == -1 && i>=0);
			
			/*if (i<0) {
				System.out.println("D�sol�, le mot de passe n'a pas �t� trouv� :-( ");
				find = true;
			}
				
			else {*/
				int j=0;
				byte[] hash = chaine.md5(P0);
				
				while (!compare(hash,mdp) && j<=1000){
					px = chaine.reduction(hash, j++);
					hash = chaine.md5(px);
				}
				
				if (j<=1000) {
					find = true;
					System.out.println("Mot de passe : " + px);
				}
				
						
			//}
			
		}
		

	}
}
