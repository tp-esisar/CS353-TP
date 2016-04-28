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
		
		System.out.print("Avancement : 0%");
		for (int i=1; i<=10000; i++) {
			boolean boucle = true;
			while(boucle) {
				int px = rand.nextInt(1000000);
				int p999 = chaine.CalculChaine(px);
				if (table.insert(p999, px))
					boucle = false;
			}
			if (i%100 == 0)
				System.out.print("Avancement : "+i/100+"%\r");
		}
			
		System.out.print("\nCréation du fichier... ");
		File file = new File("rainbow.txt");
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
