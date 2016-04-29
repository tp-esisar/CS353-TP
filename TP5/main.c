/******************************************************************************
 * Programme de test du gestionnaire de magasin                               *                                                               *
 ******************************************************************************/

#include "store.h"
#include <stdio.h>

int main()
{
    //
    printf("****** Gestionnaire de magasin ******\n");

    // 
    init();

    //
    int r;
    r = insertItem(10001,"Sucre",1.20f);
    printf("Resultat Insertion 10001 = %d\n",r);

    r = insertItem(10002,"Farine",0.80f);
    printf("Resultat Insertion 10002 = %d\n",r);

    r = insertItem(10003,"Confiture fraise",2.50f);
    printf("Resultat Insertion 10003 = %d\n",r);

    r = insertItem(10004,"Sel",0.50f);
    printf("Resultat Insertion 10004 = %d\n",r);

    //
    dumpItems();


    //
    printf("=======Gestionnaire de magasin ======\n");

    return 0;
}

