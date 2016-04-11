#ifndef ARBRERN_H
#define ARBRERN_H

typedef enum {
	RED=0, BLACK=1 
} Color;
	
	
struct Client {
	int num;
	int nbAppel;
	int total;
	struct Client* pere;
	struct Client* fg;
	struct Client* fd;
	Color color;
};
typedef struct Client Client;

struct Client * createNode(int numeroTel, int nbAppel,int cout, Color color);
void parcoursPrefixe(struct Client * sentinelle);
void parcoursInfixe(struct Client * sentinelle);
struct Client * search(struct Client * sentinelle,int numeroTel);


#endif
