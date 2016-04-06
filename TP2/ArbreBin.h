#ifndef ARBREBIN_H
#define ARBREBIN_H

struct Client {
	int num;
	int nbAppel;
	int total;
	struct Client* pere;
	struct Client* fg;
	struct Client* fd;
};
typedef struct Client Client;

struct Client * createNode(int numeroTel, int nbAppel,int cout);
void parcoursInfixe(struct Client * abr);
struct Client * search(struct Client * abr,int numeroTel);
struct Client * deleteNode(struct Client * abr, int numeroTel);
struct Client * insert(struct Client * abr, int numeroTel, int prixAppel);


#endif
