
#include "ArbreBin.h"
#include <stdlib.h>
#include <stdio.h>

Client * createNode(int numeroTel, int nbAppel,int cout) {
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
	nex->fd = NULL;
	
	return new;
}

void parcoursInfixe(struct Client * abr) {
	if (x != NULL){
		parcoursInfixe(abr->fg);
		printf("[numero=\"%d\",\tnbAppel=\"%d\",\tprixTotal=\"%d\"\n",abr->num,abr->nbAppel,abr->total);
		parcoursInfixe(abr->fd);
	}
}

