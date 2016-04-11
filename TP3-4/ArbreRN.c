
#include "ArbreRN.h"
#include <stdlib.h>
#include <stdio.h>

struct Client * createNode(int numeroTel, int nbAppel,int cout, Color color) {
	Client* new = NULL;
	new = malloc(sizeof(Client));
	if (new == NULL) { //en cas d'erreur de malloc on quite immédiatement
		perror("Erreur malloc client");
		exit(1);
	}
	new->num = numeroTel;
	new->nbAppel = nbAppel;
	new->total = cout;
	new->pere = NULL;
	new->fg = NULL;
	new->fd = NULL;
	new->color = color;

	return new;
}

char toCharColor(Color color) {
	if (color == RED)
		return 'R';
	else
		return 'N';
}	

void parcoursPrefixeR(struct Client * noeud) {
	if (noeud->num == 0)
		printf("S ");
	else {
		printf("%d(%c) ", noeud->num, toCharColor(noeud->color));
		parcoursPrefixeR(noeud->fg);
		parcoursPrefixeR(noeud->fd);
	}
}

void parcoursPrefixe(struct Client * sentinelle) {
	if (sentinelle->fg != NULL)
		parcoursPrefixeR (sentinelle->fg);
}

void parcoursInfixe(struct Client * noeud) {
	if (noeurd->num == 0) 
		printf("S \n");
	else {
		parcoursInfixe(noeud->fg);
		printf("[numero=\"%d\",\tnbAppel=\"%d\",\tprixTotal=\"%d\"\n",noeud->num,noeud->nbAppel,noeud->total);
		parcoursInfixe(noeud->fd);
	}
}

void parcoursInfixe(struct Client * sentinelle) {
	if (sentinelle->fg != NULL)
		parcoursInfixeR (sentinelle->fg);
}

struct Client * search(struct Client * sentinelle,int numeroTel) {
	if (sentinelle->fg != NULL)
		searchR (sentinelle->fg);
}

struct Client * searchR(struct Client * noeud,int numeroTel) {
	if (noeud->num == numeroTel)
		return noeud;
	else if (noeud->num == 0)
		return NULL;
	else if (noeud->num < numeroTel)
		return searchR(noeud->fd,numeroTel);
	else if (noeud->num > numeroTel)
		return searchR(noeud->fg,numeroTel);
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

	else { //Si l'on a pas trouvé l'élément à supprimer
        if (numeroTel > abr->num) //Si le n° du client à supprimer est plus grand que l'actuel on le cherche à droite
		abr->fd = deleteNode (abr->fd, numeroTel);

        else if (numeroTel < abr->num) //Si le n° du client à supprimer est plus petit que l'actuel on le cherche à gauche
            abr->fg = deleteNode (abr->fg, numeroTel);

        return abr;
	}

}


