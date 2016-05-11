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
		//HashTable table = new HashTable(10061);
		HashTable table = new HashTable(1000003);
		
		//System.out.println("ChaineCalcul(1) = "+chaine.CalculChaine(0, 1));			
		int nbitems=0;
		//for (int i=1; i<=10000; i++) {
		for (int i=1; i<=1000000; i++) {
			//int px = rand.nextInt(1000000);
			int px = rand.nextInt(1000000000);
			int p999 = chaine.CalculChaine(0, px);

			if (table.insert(p999, px))
				nbitems++;
				
			if (i%10000 == 0)
				System.out.print("\rAvancement : "+i/10000+"%");
		}
		System.out.println("\n"+ nbitems + " elements dans la table\n");
			
		System.out.print("\nCréation du fichier... ");
		File file = new File("rainbow.table");
		ObjectOutputStream ecriture;
		try {
			ecriture = new ObjectOutputStream( new FileOutputStream(file));
			ecriture.writeObject(table);
	        ecriture.close();
		} catch (IOException e) {
			System.out.println("Erreur lors de l'écriture du fichier");
			e.printStackTrace();
		}
		System.out.println("\nFini ! ");
	}
}
