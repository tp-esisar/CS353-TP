
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

void parcoursInfixeR(struct Client * noeud) {
	if (noeud->num != 0) {
		parcoursInfixeR(noeud->fg);
		printf("[numero=\"%d\",\tnbAppel=\"%d\",\tprixTotal=\"%d\"\n",noeud->num,noeud->nbAppel,noeud->total);
		parcoursInfixeR(noeud->fd);
	}
}

void parcoursInfixe(struct Client * sentinelle) {
	if (sentinelle->fg != NULL)
		parcoursInfixeR (sentinelle->fg);
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
    else
        return NULL;
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

Client* oncle(Client* x) {
	if (papy(x)->fg == x->pere)
		return papy(x)->fd;
	else
		return papy(x)->fg;
}

//fonctions d'insertion

int isLeft()

void left_rotate( struct Client *y) {
	Client* pere = y->pere;
	Client* fd = y->fd;
	Client* temp;
	if (pere->fd == y) {
		pere->fd = fd;
	else
		pere->fg = fd;
	fd->pere = pere;
	temp = fd->fg;
	fd->fg = y;
	y->fd = temp;
	y->pere = fd;
}
void right_rotate( struct Client *y) {
	Client* pere = y->pere;
	Client* fg = y->fg;
	Client* temp;
	if (pere->fd == y) {
		pere->fd = fg;
	else
		pere->fg = fg;
	fg->pere = pere;
	temp = fg->fd;
	fg->fd = y;
	y->fg = temp;
	y->pere = fg;
}


Client* classic_insert(Client* sentinelle, Client* newNode) {
	Client* root = sentinelle->fd;
	if (root == sentinelle) { // On a trouvé une case de vide et donc on peut insérer l'élement
		newNode->pere = newNode->fg = newNode->fd = sentinelle;
		return newNode;
	}
	else {
		if (num < root->num) { //Soit l'élément est plus petit que l'actuel et donc on doit l'insérer à sa gauche
			root->fg=classic_insert(sentinelle,root->fg,num,newNode);
			root->fg->pere = root;
		}
		if (num > root->num) { //Soit l'élément est plus grand que l'actuel et donc on doit l'insérer à sa droite
			root->fd=classic_insert(sentinelle,root->fd,num,newNode);
			root->fd->pere = root;
		}
		return root;
	}
}




struct Client * insert(struct Client * sentinelle, int numeroTel, int prixAppel) {
	Client* newNode = createNode(numeroTel, 1, prixAppel, RED);
	sentinelle->fd = sentinelle->fg = classic_insert(sentinelle, newNode);
	Client* x = newNode;
	while(1) {
		if (x->pere == sentinelle) {//on est root
			x->color = BLACK;
			return sentinelle;
		}
		if (papy(x) == sentinelle) {
			return sentinelle;
		}
		if (x->pere->color != BLACK) {
			if (oncle(x)->color == RED) {
				
				x->pere->color = oncle(x)->color = BLACK;
				papy(x)->color = RED;
				x = papy(x);
				continue;
			}
			else {
				
				
			}
		}
	}
}


struct Client * search(struct Client * sentinelle,int numeroTel) {
	if (sentinelle->fg != NULL)
		return searchR (sentinelle->fg, numeroTel);
    else
        return NULL;
}


