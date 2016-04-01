#ifndef LISTECHAIN_H
#define LISTECHAIN_H

struct Client {
	int num;
	int nbAppel;
	int total;
	struct Client* next;
};
typedef struct Client Client;

Client* makeClient(int num, int nbAppel, int total);

Client* addLogLine(Client* list, int numero, int prixAppel);

void dumpList(Client* list);

#endif
