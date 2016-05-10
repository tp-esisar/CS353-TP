/******************************************************************************
 * Programme de test du gestionnaire de magasin                               *                                                               *
 ******************************************************************************/

#include "store.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insert_Random(int nb, unsigned int seed) {
	char str[32];
	int i=0,k;
	srand(seed);
	while(i<nb) {
		k = rand()%100000;
		if(searchItem(k) == -1) {
			sprintf(str, "itemRand code: %d", k);
			insertItem(k,str,k/100.0);
			i++;
		}
	}
}

void delete_Random(int nb, unsigned int seed) {
	int i=0,k;
	srand(seed);
	while(i<nb) {
		k = rand()%TABLE_SIZE;
		if(hash_table[k].code != NULL_ITEM && hash_table[k].code != DELETED_ITEM) {
			suppressItem(hash_table[i].code);
			i++;
		}
	}
}


void afficheMeta() {
	int indice;
	printf("CODE\tPRIX\tINDEX\tDIRTY\n");
	for (indice=0; indice<TABLE_SIZE; indice++) {
		if (indice == NULL_ITEM)
			printf("NULL\t%0.2f\t%d\t%s\n", hash_table[indice].price, indice, hash_table[indice].dirty==true?"true":"false");
		else if (indice == DELETED_ITEM)
			printf("DELL\t%0.2f\t%d\t%s\n", hash_table[indice].price, indice, hash_table[indice].dirty==true?"true":"false");
		else
			printf("%d\t%0.2f\t%d\t%s\n", hash_table[indice].code, hash_table[indice].price, indice, hash_table[indice].dirty==true?"true":"false");
	}
}

int main()
{
    //
    printf("****** Gestionnaire de magasin ******\n");

    // 
    init();
		insert_Random(TABLE_SIZE,time(NULL));
/*    //
    int r;
    r = insertItem(10001,"Sucre",1.20f);
    printf("Resultat Insertion 10001 = %d\n",r);

    r = insertItem(10002,"Farine",0.80f);
    printf("Resultat Insertion 10002 = %d\n",r);

    r = insertItem(10003,"Confiture fraise",2.50f);
    printf("Resultat Insertion 10003 = %d\n",r);

    r = insertItem(10004,"Sel",0.50f);
    printf("Resultat Insertion 10004 = %d\n",r);

*/    //
    dumpItems();
		

    //
    printf("=======Gestionnaire de magasin ======\n");
		printf("=======Suppression aléatoire de la moitié des éléments ======\n");
		delete_Random(TABLE_SIZE/2,time(NULL));
		dumpItems();
		printf("=======Ré-insertion des éléments ======\n");
		insert_Random(TABLE_SIZE/2,time(NULL)+1);
		dumpItems();
		printf("=======Suppression de tous les éléments ======\n");
		delete_Random(TABLE_SIZE,time(NULL)+2);
		printf("=======Ré-insertion de la moitié des éléments avec seed 42 ======\n");
		insert_Random(TABLE_SIZE/2,time(NULL));
		dumpItems();
		int item = 4242;
		insertItem(item,"item à mette à jour",9999);
		printf("*******Utilisation de getPrice pour l'item %d ******\n",item);
		printf("Le Prix de l'item %d est %0.2f\n",item, getPrice(item));
		printf("Mise à jour de cet item via updateItem(), Code de retour:%d\n",updateItem(item, "item mis à jour", 42.4242));
		printf("Le Prix de l'item %d est %0.2f, son nom est \"%s\"\n",item, getPrice(item),hash_table[2].name);
		dumpItems();
		printf("*******Affichage des métadonnées de la table*****\n");
		afficheMeta();
		printf("*******Reconstruction de la table inSitu*********\n");
		rebuildTable();
		afficheMeta();
		dumpItems();
		printf("*******Test de findItem(), ajout d'un deuxième \"item mis à jour\" et recherche de ces deux items\n");
		insertItem(314,"item mis à jour",3.14);
		Item* found = findItem("item mis à jour");
		printf("CODE\tLIBELLE\t\t\t\tPRIX\n");
		printf("%d\t%s\t%0.2f\n", found[0].code, found[0].name, found[0].price);
		printf("%d\t%s\t%0.2f\n", found[1].code, found[1].name, found[1].price);
		
    return 0;
}

