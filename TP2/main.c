#include <stdio.h>
#include <stdlib.h>
#include "ArbreBin.h"

// Nombre total de lignes dans le fichier
#define NBLOGLINE 20000000
// Nombre de clients
#define NBCLIENT 20000

int main()
{
	 int i, numeroTel, prixAppel;
	 struct Client * recherche = NULL;
	 struct Client * arbre = NULL;

	 // Aide au calcul du pourcentage d'avancement
	 int pas = NBLOGLINE/100;

	 printf("****** Facturation appels telephoniques - Arbre ******\n");
	 for(i=0;i<NBLOGLINE;i++)
	 {
		 // Génération d'un numéro de telephone portable
		 numeroTel = 600000000+(rand() % NBCLIENT);
		 // Donne un prix d'appel compris entre 0.01 et 4 euros
		 prixAppel = (rand() % 400)+1;

		 //Recherche si le client existe déjà dans l'arbre
		 recherche = search(arbre,numeroTel);

		 if (recherche == NULL) //Si le client n'existe pas, on l'insére dans l'arbre
            arbre = insert(arbre, numeroTel, prixAppel);
         else { //Sinon il faut le mettre à jour
                recherche->nbAppel ++;
                recherche->total += prixAppel;
            }

		 // Affichage du pourcentage d'avancement
		 if ((i % pas)==0)
		 {
			printf("Done = %d %%...\n",i/pas);
		 }
	 }

	 parcoursInfixe(arbre);
	 printf("======= Facturation appels telephoniques ======\n");
	 return 0;
}
