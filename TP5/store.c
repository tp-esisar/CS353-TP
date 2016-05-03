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
 * en positionnant tous les elements � NULL_ITEM
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
 * Cette fonction ins�re le produit indiqu� dans la table de hachage.
 * Si le produit est ins�r� avec succ�s, alors la fonction retourne SUCCESS (0)
 * Si le produit existe d�j� dans la table, alors la fonction retourne INSERT_ALREADY_EXIST (-1),
 * et la table de hachage n'est pas modifi�e
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
	else if(hash_table[i].code == DELETED_ITEM) {
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
	int i = strlen(itemName);
	memcpy(k.name,itemName,((i>32)?32:i)*sizeof(char));
	for (i=strlen(itemName); i<31; i++)
		k.name[i] = ' ';
	k.name[i] = '\0';
	k.price = itemPrice;
	k.dirty = false;
	return insRec(k,0);
}

/*----------------------------------------------------------------------------
 * Fonction qui permet de rechercher un �l�ment par son num�rp
 * Et retourne l'indice ou il est pr�sent dans la hash table.
 *----------------------------------------------------------------------------*/
int searchItem(int itemCode) {
	int i = 0, hash;
	do {
		hash = hashkey (itemCode, i++);
		if (hash_table[hash].code == itemCode)
			return hash;
	} while (hash_table[hash].code != NULL_ITEM && i<TABLE_SIZE);
	return -1;
}

/*----------------------------------------------------------------------------
 * fonction de suppression d'un produit du magasin
 * Si le produit est supprim� avec succ�s, alors la fonction retourne SUCCESS (0)
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
 * son libell�
 * son prix
 * son index dans la table de hashage
 * sa valeur de hash
 *----------------------------------------------------------------------------*/
void dumpItems()
{
	int i, indice;
	printf("CODE\tLIBELLE\t\t\t\tPRIX\tINDEX\n");
	for (i=0; i<100000; i++) {
		indice = searchItem(i);
		if (indice != -1)
			printf("%d\t%s\t%0.2f\t%d\n", hash_table[indice].code, hash_table[indice].name, hash_table[indice].price, indice);
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
 *  fonction de mise � jour d'un produit�:
 * Si le produit est mis � jour avec succ�s, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne UPDATE_NO_ROW (-5)
 *----------------------------------------------------------------------------*/
int updateItem(int itemCode, char* itemName, float itemPrice)
{
	int indice = searchItem(itemCode);
	int i = strlen(itemName);

	if (indice != -1) {
		memcpy(hash_table[indice].name,itemName,((i>32)?32:i)*sizeof(char));
		for (i=strlen(itemName); i<31; i++)
			hash_table[indice].name[i] = ' ';
		hash_table[indice].name[i] = '\0';
		hash_table[indice].price = itemPrice;
		return SUCCESS;  
	}
	return UPDATE_NO_ROW;
}

/*----------------------------------------------------------------------------
 * la fonction de r�organisation in situ�:
 *----------------------------------------------------------------------------*/
void rebuildTable()
{
	int i;
//Au d�but, tout les �l�ments sont sales	
	for (i=0; i<TABLE_SIZE; i++)
		if (hash_table[i].code !=  NULL_ITEM)
			hash_table[i].dirty = true;

//On nettoie tout les �l�ments
	/*for (i=0; i<TABLE_SIZE; i++)
		if (hash_table[i].code > 0 && hash_table[i].dirty == true) {
			//Proc�dure de d�placement
				do {
					hash = hashkey (itemCode, i++);
					if (hash_table[hash].code == itemCode)
						return hash;
				} while (hash_table[hash].code != NULL_ITEM);
			



			//Proc�dure d'�change
			Item temp;
			hash_table[i]


				int code;
				char name[ITEM_NAME_SIZE];
				float price;
				bool dirty;



		}
	}*/

//On vide les �l�ments DELETED
	for (i=0; i<TABLE_SIZE; i++)
		if (hash_table[i].code ==  DELETED_ITEM)
			hash_table[i].code = NULL_ITEM;
}

/*----------------------------------------------------------------------------
 * Fonction simple de recherche des produits par libell��:
 *  
 * Cette fonction retourne un tableau avec tous les produits dont le libell� est �gal � itemName.
 * Exemple�: si il y a trois produits 1 - ��Sel�� , 2 - ��Sel� et 3-��Confiture��, alors
 * findItem(��Sel��)
 * retourne les deux produits 1-��Sel�� et 2-��Sel��.
 *----------------------------------------------------------------------------*/
Item* findItem(char* itemName)
{
    return NULL;
}

/*----------------------------------------------------------------------------
 * Fonction de recherche des produits par libell��avec index
 *----------------------------------------------------------------------------*/
Item* findItemWithIndex(char* itemName)
{
    return NULL;
}

