
#include "ListeChain.h"
#include <stdlib.h>
#include <stdio.h>



Client* makeClient(int num, int nbAppel, int total) { //fonction de création de client
	Client* new = NULL;
	new = malloc(sizeof(Client));
	if (new == NULL) { //en cas d'erreur de malloc on quite immédiatement
		perror("Erreur malloc client");
		exit(1);
	}
	new->num = num;
	new->nbAppel = nbAppel;
	new->total = total;
	
	return new;

}

void updateClient(Client* cl, int prixAppel) { //fonction de mise à jour d'un client, utilisé par addLogLine()
	cl->total += prixAppel;
	cl->nbAppel += 1;
}

Client* addLogLine(Client* list, int numero, int prixAppel) {
	Client* i;
	Client* j;
	
	
	if(list == NULL || list->num > numero) { //Insertion en tête, cas liste vide et cas où le client a le plus petit des numéros
		i = makeClient(numero,1,prixAppel);
		i->next = list;
		return i; //le nouvel element est la tête
	}
	if(list->num == numero) { //Mise à jour en tête
		updateClient(list,prixAppel);
		return list;
	}
	
	for(i = list;i->next != NULL;i = i->next) { //cas général
		if(i->next->num == numero) {
			updateClient(i->next,prixAppel);
			return list;
		}
		if(i->next->num > numero) {
			j = makeClient(numero,1,prixAppel);
			j->next = i->next;
			i->next = j;
			return list;
		}
	}
	//cas de l'ajout en queue
	j = makeClient(numero,1,prixAppel);
	j->next = i->next;
	i->next = j;
	return list;
}


void dumpList(Client* list) {

	Client* i;
	for(i = list;i != NULL;i = i->next) {
		printf("[numero=\"%d\",\tnbAppel=\"%d\",\tprixTotal=\"%d\"\n",i->num,i->nbAppel,i->total);
	}
}




