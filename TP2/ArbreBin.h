#ifndef ARBREBIN_H
#define ARBREBIN_H

struct Client {
	int num;
	int nbAppel;
	int total;
	struct Client* fg;
	struct Client* fd;
};
typedef struct Client Client;

struct Client * createNode(int numeroTel, int nbAppel,int cout);


#endif
