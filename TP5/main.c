/******************************************************************************
 * Programme de test du gestionnaire de magasin                               *                                                               *
 ******************************************************************************/

#include "store.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fullTableRandom(unsigned int seed) {
	int randCodes[TABLE_SIZE];
	char str[32];
	int i,j,k,found,err;
	srand(seed);
	for(i = 0;i<TABLE_SIZE;i++) {
		k = rand()%100000;
		//printf("%d\t", k);
		found = 0;
		for(j = 0;j<i;j++) {
			if(randCodes[j] == k) {
				found = 1;
				break;
			}
		}
		if(!found) {
			
			sprintf(str, "itemRand no %d", i);
			err = insertItem(k,str,k/100.0);
			randCodes[i] = k;
			printf("%d,",err);
		}
		else {
			i--;
		}
	}
	
}


int main()
{
    //
    printf("****** Gestionnaire de magasin ******\n");

    // 
    init();
	fullTableRandom(time(NULL));
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

    return 0;
}

