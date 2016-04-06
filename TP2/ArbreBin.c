
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
	new->pere = NULL;	
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

struct Client * search(struct Client * abr,int numeroTel) {
	if (abr == NULL)
		return NULL;
	else if (abr->num == numeroTel)
		return abr;
	else if (abr->num < numeroTel)
		return search (abr->fd, numeroTel);
	else 
		return search (abr->fg, numeroTel);

}

struct Client * deleteNode(struct Client * abr, int numeroTel) {
	
	/*Client* elm = NULL;
	elm = search (abr, numeroTel);
	if (elm == NULL) {
		printf("Element non present");
		return abr;
	}

	// Cas du père de l'arbre à 2 éléments !!!

	if (elm->fg == NULL || elm->fg == NULL) {
		if (elm == abr) {
			if(elm->fg == NULL)
				abr = elm->fd;
			else if(elm->fd == NULL)
				abr = elm->fg;
			abr->pere = NULL;
		}
		else if (elm->pere->fg == elm)
			elm->pere->fg = elm->fg;
		else if (abr->pere->fd == elm)
			elm->pere->fd = elm->fd;
	}
	else {
		while (search(struct Client * abr,int numeroTel)
	}

	free(abr);*/
	return NULL;

}


