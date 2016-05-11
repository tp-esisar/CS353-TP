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
			System.out.println("Erreur importation");
			e.printStackTrace();
		}
		
		System.out.println("Décodage du mot de passe ...");
		int P0, px = 0;
		int i = 999;
		byte[] mdp = DatatypeConverter.parseHexBinary(args[0]);
		boolean find = false;
		
		while (!find) {
			//Partie 1
			do {
				px = chaine.reduction(mdp, i);
				px = chaine.CalculChaine(i + 1, px);
				i--;
			} while ((P0 = table.acces(px)) == -1 && i >= 0);

			if (i < 0) {
				System.out.println("Mot de passe non trouvé :-( ");
				System.exit(-1);
			}

			//Partie 2
			int j = 0;
			byte[] hash = chaine.md5(P0);
			while (!compare(hash, mdp) && j <= 1000) {
				px = chaine.reduction(hash, j++);
				hash = chaine.md5(px);
			}

			if (j <= 1000)
				find = true;
		}
		System.out.println("Mot de passe : " + px);
	}
}
