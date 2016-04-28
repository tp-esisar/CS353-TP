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
    return 0;
}


/*----------------------------------------------------------------------------
 * Cette fonction ins�re le produit indiqu� dans la table de hachage.
 * Si le produit est ins�r� avec succ�s, alors la fonction retourne SUCCESS (0)
 * Si le produit existe d�j� dans la table, alors la fonction retourne INSERT_ALREADY_EXIST (-1),
 * et la table de hachage n'est pas modifi�e
 * Si la table est pleine, alors la fonction retourne TABLE_FULL (-2).
 *----------------------------------------------------------------------------*/
int insertItem(int itemCode, char* itemName, float itemPrice)
{
   return SUCCESS;
}

/*----------------------------------------------------------------------------
 * fonction de suppression d'un produit du magasin
 * Si le produit est supprim� avec succ�s, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne DELETE_NO_ROW (-4)
 *----------------------------------------------------------------------------*/
int suppressItem(int itemCode)
{
  return SUCCESS;
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
}


/*----------------------------------------------------------------------------
 * Cette fonction retourne le prix du produit dont le code est itemCode.
 * Cette fonction retourne SELECT_NO_ROW (-3) si le produit n'existe pas.
 *----------------------------------------------------------------------------*/
float getPrice(int itemCode)
{
  return SELECT_NO_ROW;
}



/*----------------------------------------------------------------------------
 *  fonction de mise � jour d'un produit�:
 * Si le produit est mis � jour avec succ�s, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne UPDATE_NO_ROW (-5)
 *----------------------------------------------------------------------------*/
int updateItem(int itemCode, int itemName, float itemPrice)
{
  return SUCCESS;
}

/*----------------------------------------------------------------------------
 * la fonction de r�organisation in situ�:
 *----------------------------------------------------------------------------*/
void rebuildTable()
{
}

/*----------------------------------------------------------------------------
 * Fonction simple de recherche des produits par libell�:
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
 * Fonction de recherche des produits par libell�avec index
 *----------------------------------------------------------------------------*/
Item* findItemWithIndex(char* itemName)
{
    return NULL;
}

