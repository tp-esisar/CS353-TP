package prog;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

import rainbow.Chaine;
import rainbow.HashTable;

public class Main {

	public static void main(String[] args) {
		HashTable table = null;
		Chaine chaine = new Chaine();
		
		byte[] temp = chaine.md5(712333);
		byte[] mdp = args[0].getBytes();
		
		
		/*if (args.length!=1) {
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
			System.out.println("Erreur lors de l'écriture du fichier");
			e.printStackTrace();
		}
		
		System.out.println("Décodage du mot de passe ...");
		int P0, px = 0;
		int i = 999;
		byte[] mdp = args[0].getBytes();
		boolean find = false;
		
		while(!find) {
			do {
				px = chaine.reduction(mdp, i);
				px = chaine.CalculChaine(i+1, px);
				//System.out.println(i +" / "+ px);
				i--;
			} while((P0 = table.acces(px)) == -1 && i>=0);
			
			if (i<0) {
				System.out.println("Désolé, le mot de passe n'a pas été trouvé :-( ");
				find = true;
			}
				
			else {
				int j=0;
				byte[] hash = chaine.md5(P0);
				while (!hash.equals(mdp) && j<=1000){
					px = chaine.reduction(hash, j++);
					hash = chaine.md5(px);
				}
				
				if (j<=1000)
					find = true;
				
						
			}
			
		}
		System.out.println("Mot de passe : " + px);	*/

	}
}
