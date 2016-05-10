/******************************************************************************
 * Fichier d'entete du module gestion de stock d'un magasin
 * avec une table de hachage
 ******************************************************************************/

#include <stdbool.h>

/*----------------------------------------------------------------------------
 * Parametres globaux
 *----------------------------------------------------------------------------*/
#define TABLE_SIZE            13
#define NULL_ITEM              -1
#define DELETED_ITEM           -2
#define ITEM_NAME_SIZE        32

/*----------------------------------------------------------------------------
 * Definition des constantes pour les retours des fonctions
 *----------------------------------------------------------------------------*/
#define SUCCESS                 0
#define INSERT_ALREADY_EXIST   -1
#define TABLE_FULL             -2
#define SELECT_NO_ROW          -3
#define DELETE_NO_ROW          -4
#define UPDATE_NO_ROW          -5





/*----------------------------------------------------------------------------
 * Definition de la structure d'un produit
 * Chaque produit est identifi� par 3 champs�:
 *     - son code sur 5 chiffres
 *     - son libell�
 *     - son prix en euros
 *
 *----------------------------------------------------------------------------*/
typedef struct structItem
{
	int code;
	char name[ITEM_NAME_SIZE];
	float price;
	bool dirty;
} Item;


/*----------------------------------------------------------------------------
 * Variable globale contenant le tableau
 *----------------------------------------------------------------------------*/
Item hash_table[TABLE_SIZE];
Item* hash_index[TABLE_SIZE];

/*----------------------------------------------------------------------------
 * Cette fonction initialise un tableau hash_table
 *----------------------------------------------------------------------------*/
void init();


/*----------------------------------------------------------------------------
 * Cette fonction calcule la valeur de hachage pour le produit itemCode
 *----------------------------------------------------------------------------*/
int hashkey(int itemCode,int nbTry);


/*----------------------------------------------------------------------------
 * Cette fonction ins�re le produit indiqu� dans la table de hachage.
 * Si le produit est ins�r� avec succ�s, alors la fonction retourne SUCCESS (0)
 * Si le produit existe d�j� dans la table, alors la fonction retourne INSERT_ALREADY_EXIST (-1),
 * et la table de hachage n'est pas modifi�e
 * Si la table est pleine, alors la fonction retourne TABLE_FULL (-2).
 *----------------------------------------------------------------------------*/
int insertItem(int itemCode, char* itemName, float itemPrice);

/*----------------------------------------------------------------------------
 * fonction de suppression d'un produit du magasin
 * Si le produit est supprim� avec succ�s, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne DELETE_NO_ROW (-4)
 *----------------------------------------------------------------------------*/
int suppressItem(int itemCode);

/*----------------------------------------------------------------------------
 * Pour chaque produit, cette fonction affiche sur une ligne
 * le code du produit
 * son libell�
 * son prix
 * son index dans la table de hashage
 * sa valeur de hash
 *----------------------------------------------------------------------------*/
void dumpItems();


/*----------------------------------------------------------------------------
 * Cette fonction retourne le prix du produit dont le code est itemCode.
 * Cette fonction retourne SELECT_NO_ROW (-3) si le produit n'existe pas.
 *----------------------------------------------------------------------------*/
float getPrice(int itemCode);

/*----------------------------------------------------------------------------
 *  fonction de mise � jour d'un produit�:
 * Si le produit est mis � jour avec succ�s, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne UPDATE_NO_ROW (-5)
 *----------------------------------------------------------------------------*/
int updateItem(int itemCode, char* itemName, float itemPrice);


/*----------------------------------------------------------------------------
 * la fonction de r�organisation in situ�:
 *----------------------------------------------------------------------------*/
void rebuildTable();

/*----------------------------------------------------------------------------
 * Fonction simple de recherche des produits par libell��:
 *
 * Cette fonction retourne un tableau avec tous les produits dont le libell� est �gal � itemName.
 * Exemple�: si il y a trois produits 1 - ��Sel�� , 2 - ��Sel� et 3-��Confiture��, alors
 * findItem(��Sel��)
 * retourne les deux produits 1-��Sel�� et 2-��Sel��.
 *----------------------------------------------------------------------------*/
Item* findItem(char* itemName);

/*----------------------------------------------------------------------------
 * Fonction de recherche des produits par libell��avec index
 *----------------------------------------------------------------------------*/
Item* findItemWithIndex(char* itemName);



int searchItem(int itemCode);







