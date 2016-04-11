
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

struct Client * search(struct Client * sentinelle,int numeroTel) {
	if (sentinelle->fg != NULL)
		return searchR (sentinelle->fg, numeroTel);
    else
        return NULL;
}

