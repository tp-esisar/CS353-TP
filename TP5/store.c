/******************************************************************************
 * Implementation du module gestion de stock d'un magasin
 * avec une table de hachage
 ******************************************************************************/

#include "store.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*----------------------------------------------------------------------------
 * Cette fonction initialise le tableau hash_table
 * en positionnant tous les elements à NULL_ITEM
 *----------------------------------------------------------------------------*/
void init()
{
    int i;
    for(i=0;i<TABLE_SIZE;i++)
    {
        hash_table[i].code = NULL_ITEM;
        hash_table[i].price = 0.00f;
    }
}


/*----------------------------------------------------------------------------
 * Cette fonction calcule la valeur de hachage pour le produit itemCode
 *----------------------------------------------------------------------------*/
int hashkey(int itemCode,int nbTry)
{
	int h1 = itemCode % TABLE_SIZE;
	int h2 = 1 + (itemCode % (TABLE_SIZE-1));
	return (h1 + nbTry * h2) % TABLE_SIZE;
}


/*----------------------------------------------------------------------------
 * Cette fonction insère le produit indiqué dans la table de hachage.
 * Si le produit est inséré avec succès, alors la fonction retourne SUCCESS (0)
 * Si le produit existe déjà dans la table, alors la fonction retourne INSERT_ALREADY_EXIST (-1),
 * et la table de hachage n'est pas modifiée
 * Si la table est pleine, alors la fonction retourne TABLE_FULL (-2).
 *----------------------------------------------------------------------------*/
 
int present(Item k, int try) {
	int i = hashkey(k.code,try);
	if(hash_table[i].code == k.code) return 1;
	if(hash_table[i].code == NULL_ITEM) return 0;
	else return present(k,try+1);
}


int insRec(Item k, int try) {
	if(try >= TABLE_SIZE) return TABLE_FULL;
	int i = hashkey(k.code,try);
	if(hash_table[i].code == k.code) return INSERT_ALREADY_EXIST;
	if(hash_table[i].code == NULL_ITEM) {
		hash_table[i] = k;
		return SUCCESS;
	}
	if(hash_table[i].code == DELETED_ITEM) {
		if(present(k,try)) return INSERT_ALREADY_EXIST;
		else {
			hash_table[i] = k;
			return SUCCESS;
		}
	}
	else {
		return insRec(k,try+1);
	}
}

int insertItem(int itemCode, char* itemName, float itemPrice) {
	Item k;
	k.code = itemCode;
	int i = strlen(itemName)*sizeof(char);
	memcpy(k.name,itemName,(i>32)?32:i);
	k.price = itemPrice;
	k.dirty = false;
	return insRec(k,0);
}

/*----------------------------------------------------------------------------
 * Fonction qui permet de rechercher un élément par son numérp
 * Et retourne l'indice ou il est présent dans la hash table.
 *----------------------------------------------------------------------------*/
int searchItem(int itemCode) {
	int i = 0, hash;
	do {
		hash = hashkey (itemCode, i++);
		if (hash_table[hash].code == itemCode)
			return hash;
	} while (hash_table[hash].code != NULL_ITEM);
	return -1;
}

/*----------------------------------------------------------------------------
 * fonction de suppression d'un produit du magasin
 * Si le produit est supprimé avec succès, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne DELETE_NO_ROW (-4)
 *----------------------------------------------------------------------------*/
int suppressItem(int itemCode)
{
	int indice = searchItem(itemCode);
	if (indice != -1) {
		hash_table[indice].code = DELETED_ITEM;
    		hash_table[indice].price = 0.00f;
		return SUCCESS;
	}
		
	return DELETE_NO_ROW;
}

/*----------------------------------------------------------------------------
 * Pour chaque produit, cette fonction affiche sur une ligne
 * le code du produit
 * son libellé
 * son prix
 * son index dans la table de hashage
 * sa valeur de hash
 *----------------------------------------------------------------------------*/
void dumpItems()
{
	int i, indice;
	printf("CODE\tLIBELLE\t\tPRIX\tINDEX\n");
	for (i=0; i<100000; i++) {
		indice = searchItem(i);
		if (indice != -1)
			printf("%d\t%s\t%f0.2\t%d", hash_table[indice].code, hash_table[indice].name, hash_table[indice].price, indice);
	}
}


/*----------------------------------------------------------------------------
 * Cette fonction retourne le prix du produit dont le code est itemCode.
 * Cette fonction retourne SELECT_NO_ROW (-3) si le produit n'existe pas.
 *----------------------------------------------------------------------------*/
float getPrice(int itemCode)
{
	int indice = searchItem(itemCode);
	if (indice != -1)
		return hash_table[indice].price;  
	return SELECT_NO_ROW;
}



/*----------------------------------------------------------------------------
 *  fonction de mise à jour d'un produit :
 * Si le produit est mis à jour avec succès, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne UPDATE_NO_ROW (-5)
 *----------------------------------------------------------------------------*/
int updateItem(int itemCode, int itemName, float itemPrice)
{
  return SUCCESS;
}

/*----------------------------------------------------------------------------
 * la fonction de réorganisation in situ :
 *----------------------------------------------------------------------------*/
void rebuildTable()
{
}

/*----------------------------------------------------------------------------
 * Fonction simple de recherche des produits par libellé :
 *  
 * Cette fonction retourne un tableau avec tous les produits dont le libellé est égal à itemName.
 * Exemple : si il y a trois produits 1 - « Sel » , 2 - « Sel» et 3-« Confiture », alors
 * findItem(« Sel »)
 * retourne les deux produits 1-« Sel » et 2-« Sel ».
 *----------------------------------------------------------------------------*/
Item* findItem(char* itemName)
{
    return NULL;
}

/*----------------------------------------------------------------------------
 * Fonction de recherche des produits par libellé avec index
 *----------------------------------------------------------------------------*/
Item* findItemWithIndex(char* itemName)
{
    return NULL;
}

