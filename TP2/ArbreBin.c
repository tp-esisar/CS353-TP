
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
	if (root == NULL) {
		return createNode(num,1,prixAppel);
	}
	else {
		if (num < root->num) {
			root->fg=insert(root->fg,num,prixAppel);
		}
		if (num > root->num) {
			root->fd=insert(root->fd,num,prixAppel);
		}
		return root;
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
	
	Client* retour = NULL;
	Client* elmSuiv = NULL;
	int i = numeroTel+1;

	if (abr == NULL)
		return abr;

	if (abr-> num == numeroTel) {
		if (abr->fg == NULL)
			retour = abr->fg;
		else if (abr->fg == NULL)
			retour = abr->fd;
		else {
			while ( (elmSuiv = search(abr,i++)) == NULL);
			retour = createNode(elmSuiv->num, elmSuiv->nbAppel, elmSuiv->total);
			deleteNode (abr, elmSuiv->num);
		}
		free(abr);
		return retour ;
	}
	else if (numeroTel > abr->num)
		abr->fd = deleteNode (abr->fd, numeroTel);

	else if (numeroTel < abr->num)
		abr->fg = deleteNode (abr->fg, numeroTel);
	return abr;

}


