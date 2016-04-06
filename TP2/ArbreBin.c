
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


