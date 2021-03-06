#include "ArbreRN.h"
#include <stdio.h>
#include <stdlib.h>

struct Client * createSampleTree() {
  Client* temp= NULL;
  Client* sentinelle = createNode(0,0,0, BLACK);
  sentinelle->pere = sentinelle;
  temp = createNode(7,0,0, BLACK); //Racine de l'arbre
  temp->fg = createNode(2,0,0, RED);
  temp->fd = createNode(11,0,0, RED);
  temp->pere = sentinelle;
  temp->fg->pere = temp->fd->pere = temp;
  sentinelle->fg = sentinelle->fd = temp;

	//Eléments de gauche de l'arbre
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

	//Eléments de droite de l'arbre
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

Client* testInsert() {
  Client* sentinelle = createNode(0,0,0, BLACK);
  sentinelle->pere = sentinelle->fd = sentinelle->fg = sentinelle;
  sentinelle = insert(sentinelle,8,0);
  sentinelle = insert(sentinelle,15,0);
  sentinelle = insert(sentinelle,1,0);
  sentinelle = insert(sentinelle,5,0);
  sentinelle = insert(sentinelle,7,0);
  sentinelle = insert(sentinelle,14,0);
  sentinelle = insert(sentinelle,2,0);
  sentinelle = insert(sentinelle,4,0);
  sentinelle = insert(sentinelle,11,0);

  return sentinelle;
}


struct Client * createSampleTreeDoubleBlack() {
  Client* temp= NULL;
  Client* sentinelle = createNode(0,0,0, BLACK);
  sentinelle->pere = sentinelle;
  temp = createNode(7,0,0, BLACK); //Racine de l'arbre
  temp->fg = createNode(2,0,0, BLACK);
  temp->fd = createNode(11,0,0, BLACK);
  temp->pere = sentinelle;
  temp->fg->pere = temp->fd->pere = temp;
  sentinelle->fg = sentinelle->fd = temp;

	//Eléments de gauche de l'arbre
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

	//Eléments de droite de l'arbre
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
  printf("\n---------Test de parcours de l'arbre de test---------\n");
	Client* sentinelle = createSampleTree();
	printf("\n\nParcours Prefixe : \n");
	parcoursPrefixe(sentinelle);
	printf("\n\nParcours Infixe : \n");
	parcoursInfixe(sentinelle);
	freeTree(sentinelle);
	
	printf("\n---------Création d'un arbre par insertion aléatoire de ces mêmes éléments---------\n");
	sentinelle = testInsert();
	printf("\n\nParcours Infixe testInsert : \n");
	parcoursInfixe(sentinelle);
	printf("\n\nParcours Prefixe testInsert : \n");
	parcoursPrefixe(sentinelle);
	printf("\n\nsuppression de 1 : \n");
	deleteNode(sentinelle, 1);
	parcoursPrefixe(sentinelle);
	printf("\n\nsuppression de 7 : \n");
	deleteNode(sentinelle, 7);
	parcoursPrefixe(sentinelle);
	
  freeTree(sentinelle);
  printf("\n---------Création d'un arbre pour test du cas doubleBlack---------\n");
  sentinelle = createSampleTreeDoubleBlack();
  parcoursPrefixe(sentinelle);
	printf("\n\nsuppression de 15 : (cas simple)\n");
	deleteNode(sentinelle, 15);
	parcoursPrefixe(sentinelle);
	printf("\n\nsuppression de 14 : (DoubleBlack récursif)\n");
	deleteNode(sentinelle, 14);
	parcoursPrefixe(sentinelle);
	printf("\n\nsuppression de 7 : (root)\n");
	deleteNode(sentinelle, 7);
	parcoursPrefixe(sentinelle);
	
// 	printf("\n\nsuppression de 7 : \n");
// 	deleteNode(sentinelle, 7);
// 	parcoursPrefixe(sentinelle);
	freeTree(sentinelle);
	
  return 0;
}
