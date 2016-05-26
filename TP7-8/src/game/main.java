package game;

import java.util.Scanner;
import naive.Naif;

public class main {

	public static void main(String[] args) {
		
		if (args.length != 4) {
			System.out.println("Arguments : m n i j");
			System.exit(0);
		}
		
		Plateau plateau = new Plateau(Integer.parseInt(args[0]), Integer.parseInt(args[1]), Integer.parseInt(args[2]), Integer.parseInt(args[3]));
		Joueur joueur = Joueur.pc; 
		Naif naif = new Naif(plateau);
		Scanner sc = new Scanner(System.in);
		
		while(!plateau.fin()) {
			int valNewPlateau = naif.f_accel(plateau.m, plateau.n, plateau.i, plateau.j);
			System.out.println(plateau);
			
			if (joueur == Joueur.pc) {
				System.out.println("----- Au tour du PC -----");
				System.out.println("Evalution de la configuration : "+valNewPlateau);
				valNewPlateau = naif.perfectPlay(plateau);
				joueur = Joueur.player1;
			}
			else if (joueur == Joueur.player1) {
				Sens senss;
				int coupe;
				do {
					System.out.println("----- A vous de jouer ! -----");
					System.out.println("Evalution de la configuration : "+valNewPlateau);
					System.out.println("Taper le sens de la coupure : h/v");
					String sens = sc.nextLine();
					
					if (sens.equals("h"))
						senss = Sens.horizontal;
					else if (sens.equals("v"))
						senss = Sens.vertical;
					else
						senss = Sens.none;
					
					System.out.println("Taper l'indice de la coupure : ");
					try {
						coupe = Integer.parseInt(sc.nextLine());
					} catch (Exception e){
						coupe = -1;
					} 
					
				} while(!plateau.coupe(senss, coupe));
				valNewPlateau = naif.f_accel(plateau.m, plateau.n, plateau.i, plateau.j);
				joueur = Joueur.pc;
			}
		}
		System.out.println(plateau);
		if (joueur == Joueur.player1)
			System.out.println("Vous avez perdu face à l'ordinateur !");
		else
			System.out.println("Bravo, vous avez battu l'ordinateur !");
		
		sc.close();

	}

}
