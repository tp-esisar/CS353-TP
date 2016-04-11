#include "ArbreRN.h"
#include <stdio.h>
#include <stdlib.h>

struct Client * createSampleTree() {
  Client* temp= NULL;
  Client* sentinelle = createNode(0,0,0, BLACK);

  temp = createNode(7,0,0, BLACK);
  temp->fg = createNode(2,0,0, RED);
  temp->fd = createNode(11,0,0, RED);
  temp->pere = sentinelle;
  sentinelle->fg = temp;

  temp->fg->fg = createNode(1,0,0, BLACK);
  temp->fg->fg->fg = sentinelle;
  temp->fg->fg->fd = sentinelle;
  temp->fg->fg->pere = temp->fg;

  temp->fg->fd = createNode(5,0,0, BLACK);
  temp->fg->fd->fg = createNode(4,0,0, RED);
  temp->fg->fd->fd = sentinelle;
  temp->fg->fd->pere = temp->fg;

  temp->fg->fd->fg->fg = sentinelle;
  temp->fg->fd->fg->fd = sentinelle;
  temp->fg->fd->fg->pere = temp->fg->fd;

  temp->fd->fg = createNode(8,0,0, BLACK);
  temp->fd->fd = createNode(14,0,0, BLACK);
  temp->fd->pere = temp;

  temp = temp->fd;
  temp->fg->fg = sentinelle;
  temp->fg->fd = sentinelle;
  temp->fg->pere= temp;

  temp->fd->fg = sentinelle;
  temp->fd->fd = createNode(15,0,0, RED);
  temp->fd->pere= temp;

  temp = temp->fd;
  temp->fd->fg = sentinelle;
  temp->fd->fd = sentinelle;
  temp->fd->pere = temp;

  return sentinelle;
}

int main() {
    Client* sentinelle = createSampleTree();
    printf("\n\nParcours Prefixe : \n");
	parcoursPrefixe(sentinelle);
	printf("\n\nParcours Infixe : \n");
	parcoursInfixe(sentinelle);

    return 0;
}
