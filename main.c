#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lesfonctions.h"
int main()
{  FILE*fic=NULL;
        film nouv;
        liste l=CreerListeVide();
        int choix,t;

         system("color 1F");

    fic=fopen("biblio.txt","r");
    t=testSiFichierVide(fic);
    fclose(fic);

    if (t==0)
{
         l=lire_fichier(l);
}

         l=reciproque(l);


        do
        {
        system("color 1F");
        system("cls");
        printf("         **************<Menu Principal>*********************\n\n\n");
        printf("         ---------------------------------------------------\n");
        printf("         ---------*|Gestion des films|*---------------------\n");
        printf("         ---------------------------------------------------\n\n");
        printf("         |   ->1: Creer une fiche du film                   |\n");
        printf("         |   ->2: Ajouter un film au catalogue              |\n");
        printf("         |   ->3: supprimer un film du catalogue            |\n");
        printf("         |   ->4: Rechercher un film dans le catalogue      |\n");
        printf("         |   ->5: Quitter                                   |\n\n");
        printf("          --------------------------------------------------\n\n");
        printf("                                             CHOIX:");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1 :
            system("cls");
            nouv=nouveau();

            system("PAUSE");
            break;
        case 2 :
            system("cls");

            nouv=nouveau();
            l=ajouter(nouv,l);
    l=conv(l);
            ecrire_fichier(l);

            system("PAUSE");
            break;
        case 3 :
            system("cls");
            l=reciproque(l);
            l=supprimer(l);
               l=conv(l);
            ecrire_fichier(l);
            system("PAUSE");
            break;
        case 4:
            system("cls");
              l=reciproque(l);
            recherche_globale(l);
            system("PAUSE");
            break;
        }
        }while (choix!=5);
        printf("  \n\n");

    return 0;
}

