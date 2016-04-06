
#include "ArbreBin.h"
#include <stdlib.h>
#include <stdio.h>

struct Client * createNode(int numeroTel, int nbAppel,int cout) {
	Client* new = NULL;
	new = malloc(sizeof(Client));
	if (new == NULL) { //en cas d'erreur de malloc on quite immédiatement
		perror("Erreur malloc client");
		exit(1);
	}
	new->num = numeroTel;
	new->nbAppel = nbAppel;
	new->total = cout;
	new->fg = NULL;
	new->fd = NULL;

	return new;
}

void parcoursInfixe(struct Client * abr) {
	if (abr != NULL){
		parcoursInfixe(abr->fg);
		printf("[numero=\"%d\",\tnbAppel=\"%d\",\tprixTotal=\"%d\"\n",abr->num,abr->nbAppel,abr->total);
		parcoursInfixe(abr->fd);
	}
}

struct Client* insert(struct Client* root, int num, int prixAppel) {
	if (root == NULL) // On a trouvé une case de vide et donc on peut insérer l'élement
		return createNode(num,1,prixAppel);
	else {
		if (num < root->num) { //Soit l'élément est plus petit que l'actuel et donc on doit l'insérer à sa gauche
			root->fg=insert(root->fg,num,prixAppel);
		}
		if (num > root->num) { //Soit l'élément est plus grand que l'actuel et donc on doit l'insérer à sa droite
			root->fd=insert(root->fd,num,prixAppel);
		}
		return root;
	}
}

struct Client * search(struct Client * abr,int numeroTel) {
	if (abr == NULL) //Soit l'élément n'existe pas
		return NULL;
	else if (abr->num == numeroTel) //Soit on l'a trouvé et on le retourne
		return abr;
	else if (abr->num < numeroTel) //Soit il est plus grand que l'élément actuel et il faut le chercher sur son fils droit
		return search (abr->fd, numeroTel);
	else //Soit il est plus petit que l'élément actuel et il faut le chercher sur son fils gauche
		return search (abr->fg, numeroTel);

}

struct Client * deleteNode(struct Client * abr, int numeroTel) {

	Client* retour = NULL;
	Client* elmSuiv = NULL;
	int i = numeroTel+1;

	if (abr == NULL) //Si l'arbre est vide ou que l'élément n'existe pas
		return abr;

	if (abr-> num == numeroTel) { //Si on a tourvé l'élement à supprimer
		if (abr->fg == NULL) //Si n'a pas de fils gauche, on le supprime et on lit le fils droit à son père
			retour = abr->fd;
		else if (abr->fg == NULL) //Si n'a pas de fils droit, on le supprime et on lit le fils gauche à son père
			retour = abr->fg;
		else { //Si il a deux fils
			while ( (elmSuiv = search(abr,i++)) == NULL); //On cherche l'élément suivant
			retour = createNode(elmSuiv->num, elmSuiv->nbAppel, elmSuiv->total); //On recopie l'élément suivant, que l'on va placer à la place du client que l'on veut supprimer
			retour->fg = abr->fg; //On renseigner ces fils (qui sont ceux de l'actuel client
			retour->fd = deleteNode (abr->fd, elmSuiv->num); //On peut supprimer le client que l'on a copié
		}
		free(abr); //On supprime le client
		return retour ; //On envoie au père son nouveau (ou inchangé) fils
	}
	else {
        if (numeroTel > abr->num) //Si le n° du client à supprimer est plus grand que l'actuel on le cherche à droite
		abr->fd = deleteNode (abr->fd, numeroTel);

        else if (numeroTel < abr->num) //Si le n° du client à supprimer est plus petit que l'actuel on le cherche à gauche
            abr->fg = deleteNode (abr->fg, numeroTel);

        return abr;
	}


}


