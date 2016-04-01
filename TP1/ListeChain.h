#ifndef LISTECHAIN_H
#define LISTECHAIN_H

typedef Client struct {
	int num;
	int nbAppel;
	int total;
	Client* next;
} Client;

Client* makeClient(int num, int nbAppel, int total);

Client* addLogLine(Client* list, int numero, int prixAppel);

void dumpList(Client* list);

#endif
