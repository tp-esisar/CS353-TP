package game;

import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		
		if (args.length != 4) {
			System.out.println("Arguments : m n i j");
			System.exit(0);
		}
		
		Plateau plateau = new Plateau(Integer.parseInt(args[0]), Integer.parseInt(args[1]), Integer.parseInt(args[2]), Integer.parseInt(args[3]));
		Joueur joueur = Joueur.pc; 
		
		Scanner sc = new Scanner(System.in);
		
		
		while(!plateau.fin()) {
			
			System.out.println(plateau);
			
			if (joueur == Joueur.pc) {
				//Choix de coup à jouer
				//Affichage du coup à jouer				
			}
			else if (joueur == Joueur.player1) {
				Sens senss;
				int coupe;
				do {
					System.out.println("A vous de jouer !");
					System.out.println("Taper le sens de la coupure : h/v");
					String sens = sc.nextLine();
					
					if (sens.equals("h"))
						senss = Sens.horizontal;
					else if (sens.equals("v"))
						senss = Sens.vertical;
					else
						senss = Sens.none;
					
					coupe = sc.nextInt();
				} while(plateau.coupe(senss, coupe));		
				
			}
			
			sc.nextLine();
		}
		
		if (joueur == Joueur.pc)
			System.out.println("Vous avez perdu face à l'odinateur !");
		else
			System.out.println("Bravo, vous avez battu l'ordinateur !");

	}

}
