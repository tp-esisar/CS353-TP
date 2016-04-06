#include "ArbreBin.h"

struct Client * createSampleTree() {
  Client* arbre = createNode(15,0,0);
  arbre->fg = createNode(12,0,0);
  arbre->fg->fg = createNode(8,0,0);
  arbre->fg->fg->fd = createNode(10,0,0);
  arbre->fg->fd = createNode(14,0,0);
  arbre->fg->fd->fg = createNode(13,0,0);
  arbre->fd = createNode(20,0,0);
  arbre->fd->fd = createNode(21,0,0);
  arbre->fd->fg = createNode(16,0,0);
  arbre->fd->fg->fd = createNode(17,0,0);
  return arbre;
}

int main() {
  Client* arbre = createSampleTree();
  parcoursInfixe(arbre);
  arbre = insert(arbre,18,2);
  printf("\n");
  
  parcoursInfixe(arbre);
arbre = deleteNode(arbre, 15);

  printf("\n");
  
  parcoursInfixe(arbre);
  return 0;  
}
