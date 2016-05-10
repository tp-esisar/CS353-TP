package rainbow;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.Random;

public class Main {

	public static void main(String[] args) {
		Random rand = new Random();
		Chaine chaine = new Chaine();
		HashTable table = new HashTable(10061);
		
		System.out.println("ChaineCalcul(1) = "+chaine.CalculChaine(0, 1));			
		int nbitems=0;
		for (int i=1; i<=10000; i++) {
			int px = rand.nextInt(1000000);
			int p999 = chaine.CalculChaine(0, px);

			if (table.insert(p999, px))
				nbitems++;
				
			if (i%100 == 0)
				System.out.print("\rAvancement : "+i/100+"%");
		}
		System.out.println("\n"+" elements dans la table\n");
			
		System.out.print("\nCr�ation du fichier... ");
		File file = new File("rainbow.table");
		ObjectOutputStream ecriture;
		try {
			ecriture = new ObjectOutputStream( new FileOutputStream(file));
			ecriture.writeObject(table);
	        ecriture.close();
		} catch (IOException e) {
			System.out.println("Erreur lors de l'�criture du fichier");
			e.printStackTrace();
		}
		System.out.println("\nFini ! ");
	}
}
