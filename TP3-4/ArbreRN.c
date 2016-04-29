
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
	if (noeud->num == 0) //On regarde sur le noeud est la sentinelle
		printf("S ");
	else {  //Sinon
		printf("%d(%c) ", noeud->num, toCharColor(noeud->color)); //On affiche le noeud
		parcoursPrefixeR(noeud->fg); //On parcours le sous-arbre gauche
		parcoursPrefixeR(noeud->fd); //On parcours le sous-arbre droit
	}
}

void parcoursPrefixe(struct Client * sentinelle) {
	if (sentinelle->fg != NULL)
		parcoursPrefixeR (sentinelle->fg);
}

void parcoursInfixeR(struct Client * noeud) {
	if (noeud->num != 0) { //Si on est pas la sentinelle
		parcoursInfixeR(noeud->fg); //Parcours sous-arbre gauche
		printf("[numero=\"%d\",\tnbAppel=\"%d\",\tprixTotal=\"%d\"\n",noeud->num,noeud->nbAppel,noeud->total); //Print élément en cours
		parcoursInfixeR(noeud->fd); //Parcours sous-arbre droit
	}
}

void parcoursInfixe(struct Client * sentinelle) {
	if (sentinelle->fg != NULL)
		parcoursInfixeR (sentinelle->fg);
}

struct Client * searchR(struct Client * noeud,int numeroTel) {
	if (noeud->num == numeroTel) //Si on a trouvé le client
		return noeud;
	else if (noeud->num == 0) //Si on est tombé sur une feuille de l'arbre (sentinelle)
		return NULL;
	else if (noeud->num < numeroTel) //Si le numéro du client que l'on cherche est plus grand que l'actuel
		return searchR(noeud->fd,numeroTel); //On le cherche à droite
	else if (noeud->num > numeroTel) //Si le numéro du client que l'on cherche est plus petit que l'actuel
		return searchR(noeud->fg,numeroTel); //On le cherche à gauche
    else
        return NULL;
}

struct Client * search(struct Client * sentinelle,int numeroTel) {
	if (sentinelle->fg != NULL)
		return searchR (sentinelle->fg, numeroTel);
    else
        return NULL;
}



Client* oncle(Client* x) {
	if (papy(x)->fg == x->pere)
		return papy(x)->fd;
	else
		return papy(x)->fg;
}

//fonctions d'insertion

int isLeft(Client* x) {
	if(x->pere->fg == x)
		return 1;
	else
		return 0;
}


void left_rotate( struct Client *y) {
	Client* pere = y->pere;
	Client* fd = y->fd;
	Client* temp;
	if (pere->fd == y)
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
	if (pere->fd == y)
		pere->fd = fg;
	else
		pere->fg = fg;
	fg->pere = pere;
	temp = fg->fd;
	fg->fd = y;
	y->fg = temp;
	y->pere = fg;
}


Client* classic_insert(Client* sentinelle, Client* root, Client* newNode) {
	if (root == sentinelle) { // On a trouvé une case de vide et donc on peut insérer l'élement
		newNode->pere = newNode->fg = newNode->fd = sentinelle;
		return newNode;
	}
	else {
		if (newNode->num < root->num) { //Soit l'élément est plus petit que l'actuel et donc on doit l'insérer à sa gauche
			root->fg=classic_insert(sentinelle,root->fg,newNode);
			root->fg->pere = root;
		}
		if (newNode->num > root->num) { //Soit l'élément est plus grand que l'actuel et donc on doit l'insérer à sa droite
			root->fd=classic_insert(sentinelle,root->fd,newNode);
			root->fd->pere = root;
		}
		return root;
	}
}




struct Client * insert(struct Client * sentinelle, int numeroTel, int prixAppel) {
	Client* newNode = createNode(numeroTel, 1, prixAppel, RED);
	newNode->fd = newNode->fg = sentinelle;
	sentinelle->fd = sentinelle->fg = classic_insert(sentinelle, sentinelle->fd, newNode);
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
				if(isLeft(x->pere) && isLeft(x)) {
					swapColor(x->pere,papy(x))
					right_rotate(papy(x));
					return sentinelle;
				}//LL case
				if(isLeft(x->pere) && !isLeft(x)) {
					left_rotate(x->pere);
					swapColor(x,papy(x))
					right_rotate(papy(x));
					return sentinelle;
				}//LR case
				if(!isLeft(x->pere) && !isLeft(x)) {
					swapColor(x->pere,papy(x))
					left_rotate(papy(x));
					return sentinelle;
				}//RR case
				if(!isLeft(x->pere) && isLeft(x)) {
					right_rotate(x->pere);
					swapColor(x,papy(x))
					left_rotate(papy(x));
					return sentinelle;
				}//RL case
			}
		}
		else return sentinelle;
	}
}

