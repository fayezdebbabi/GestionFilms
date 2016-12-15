#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lesfonctions.h"
film nouveau() /* pour la création d'une fiche d'un nouveau film */
 {
          int i;
          film nouv;
          system("cls");
          printf("************************CREATION D UNE FICHE D UN FILM**************************\n");
          printf("________________________________________________________________________________\n\n\n");

          printf("\n\n\n");
          do{
          printf("le titre du film   : ");
          fflush(stdin);
          gets(nouv.titre);
          }
          while(strlen(nouv.titre)>39);
          printf("\n\n\n");
          system("cls");
           printf("************************CREATION D UNE FICHE D UN FILM**************************\n");
          printf("________________________________________________________________________________\n\n\n");

          printf("\n\n\n");
          do{
          printf("le realisateur du film est   : ");
          fflush(stdin);
          gets(nouv.realisateur);
          }
          while(strlen(nouv.realisateur)>39);
          system("cls");
           printf("************************CREATION D UNE FICHE D UN FILM**************************\n");
          printf("________________________________________________________________________________\n\n\n");

          printf("\n\n\n");
          do{
          printf("donner le nombre des acteurs:" );
          scanf("%d",&nouv.nb);}
          while (nouv.nb<=0);
          printf("\n");
          fflush(stdin);

          for (i=0;i<nouv.nb;i++)
          {
              printf("   veuillez ecrire le nom de l'acteur num %d  :   ",i+1);
              gets(nouv.acteurs[i]);
              printf("\n\n");
          }
          system("cls");
          printf("************************CREATION D UNE FICHE D UN FILM**************************\n");
          printf("________________________________________________________________________________\n\n\n");

          printf("\n\n\n");
          printf("Notez la qualitee du film   : ");
          gets(nouv.qualite);
          system("cls");
           printf("************************CREATION D UNE FICHE D UN FILM**************************\n");
          printf("________________________________________________________________________________\n\n\n");

          printf("\n\n\n");
          printf("donnez un resumee du film   : ");
          gets(nouv.resumee);
          system("cls");
          do{
           printf("************************CREATION D UNE FICHE D UN FILM**************************\n");
          printf("________________________________________________________________________________\n\n\n");

          printf("\n\n\n");
          printf("donnez la duree du film en minutes   : ");
          scanf("%d",&nouv.duree);
          system("cls");
          }while(nouv.duree<=0);
          system("cls");
          printf("************************CREATION D UNE FICHE D UN FILM**************************\n");
          printf("________________________________________________________________________________\n\n\n");

          printf("\n\n\n");
        printf("Donner la date de sortie du film\n");
    do
    {
        printf("jour(jj)\t");
        scanf("%d",&nouv.j);
    }while((nouv.j<=0)|| (nouv.j>31));
    do
    {
        printf("Mois(mm)\t");
        scanf("%d",&nouv.m);
    }while((nouv.m<=0)||(nouv.m>12));
    do
    {
        printf("Annee(an)\t");
        scanf("%d",&nouv.a);
    }while(((nouv.a)>2014)||((nouv.a)<1900));

          return nouv ;


};
liste ajouter(film nouv,liste l){ /*ajouter du film nouv à la tête de la liste */

   liste p;
   p=malloc(sizeof(cellule));
   p->valeur=nouv;
   p->suivant=l;
   l=p;
   return l;
};
liste lire_fichier(liste l)/* cette fonction permet le chargement du fichier à partir des données déja enregistrées*/
{
    int i;
    cellule *pc;

    FILE*fichier=NULL;
    fichier=fopen("biblio.txt","r");
while (!feof(fichier))
{
    pc=(cellule*)malloc(sizeof(cellule));
    while (fichier){
            fscanf(fichier,"%s\n",pc->valeur.titre);
            fscanf(fichier,"%s\n",pc->valeur.realisateur);
            fscanf(fichier,"%d\n",&pc->valeur.nb);
            for (i=0;i<pc->valeur.nb;i++)
            {
                     fscanf(fichier,"%s\n",pc->valeur.acteurs[i]);
            }

            fscanf(fichier,"%s\n",pc->valeur.qualite);
            fscanf(fichier,"%s\n",pc->valeur.resumee);
            fscanf(fichier,"%d\n",&pc->valeur.duree);
            fscanf(fichier,"%d\n",&pc->valeur.j);
            fscanf(fichier,"%d\n",&pc->valeur.m);
            fscanf(fichier,"%d\n",&pc->valeur.a);
            break;
        }
       pc->suivant=l;
		l=pc;
    };
     fclose(fichier);
     return l;
}
void ecrire_fichier(liste l)/*cette fonction permet de sauvegerder les données dans fichier txt*/
{
    int i;
    liste pc;
    pc=l;
    FILE*cata=NULL;
    cata=fopen("biblio.txt","w");
    while (pc!=NULL)
    {
        fprintf(cata,"%s\n",pc->valeur.titre);
        fprintf(cata,"%s\n",pc->valeur.realisateur);
            fprintf(cata,"%d\n",pc->valeur.nb);
        for(i=0;i<pc->valeur.nb;i++)
        {
                fprintf(cata,"%s\n",pc->valeur.acteurs[i]);
        }

        fprintf(cata,"%s\n",pc->valeur.qualite);
        fprintf(cata,"%s\n",pc->valeur.resumee);
        fprintf(cata,"%d\n",pc->valeur.duree);
        fprintf(cata,"%d\n",pc->valeur.j);
        fprintf(cata,"%d\n",pc->valeur.m);
        fprintf(cata,"%d\n",pc->valeur.a);
        pc=pc->suivant;
    };
    fclose(cata);
}
void recherche_globale(liste l){ /* cette fonction permet la recherche d'un film à l'aide d'un mot clé en parcourant toute la liste ,en utlisant la fonction recherche_particuliére declarée en dessous*/
    char mot_cle[20];
    int existe=0;
    int i;
    liste pc=l;
    do{
    system("cls");
     printf("******************************RECHERCHER UN FILM********************************\n");
     printf("________________________________________________________________________________\n\n\n");
    printf("\n\ndonner le mot cle     : ");
    fflush(stdin);


    gets(mot_cle);

    printf("\n\n");
    int valeur;
    while( pc!=NULL){
            valeur=recherche_particuliere(mot_cle,pc->valeur.titre);
            if(valeur!=-1){
                    existe=1;
                    printf("\n\nLe film est               :  ");
                    puts(pc->valeur.titre);
                    printf("\n\n");
                    printf("Le realisateurs est       :  ");
                    puts(pc->valeur.realisateur);
                    printf("\n\n");
                    printf("les acteurs sont  :  \n");
                    for(i=0;i<pc->valeur.nb;i++)
                    {
                    printf("                   - %s\n",pc->valeur.acteurs[i]);
                    }

                    printf("\n\n");
                    printf("La qualitee du film       :  ");
                    puts(pc->valeur.qualite);
                    printf("\n\n");
                    printf("Le resumee du film        :  ");
                    puts(pc->valeur.resumee);
                    printf("\n\n");
                    printf("la duree du film          :  ");
                    printf("%d minutes ",pc->valeur.duree);
                    printf("\n\n");
                    printf("la date de sortie du film est %d/%d/%d \n\n",pc->valeur.j,pc->valeur.m,pc->valeur.a);

            }
            pc=pc->suivant;
            }
    }
    while(existe==0);}
int recherche_particuliere(char mot_cle[],char titre[]){ /*cette fonction permet la recherche d'une chaine de caractére dans une autre en retournant -1  en cas d'inexistence ,sinon ,elle retourne l'indice de debut d'existence*/
int carac, pat, longueurPatron, longueurTexte;
 longueurPatron = strlen(mot_cle);
longueurTexte = strlen(titre);
 pat = 0;
if(longueurPatron <= longueurTexte){
carac = 0;
do{
if((mot_cle[pat] == titre[carac])||(('a'<=mot_cle[pat]<='z')&&(mot_cle[pat]-32)==titre[carac])||(('A'<=mot_cle[pat]<='Z')&&(mot_cle[pat]+32)==titre[carac])){
pat++;
carac++;
}
else{
carac = carac - pat + 1; // avance dans Texte
pat = 0;
} //if
} while(pat < longueurPatron && carac < longueurTexte);
} //if;
if((pat >= longueurPatron)) // trouvé
return carac - longueurPatron;
else
return -1;
}
liste supprimer(liste l){
    liste p;
    liste pre;
	char  nom[25];
	p=l;
	system("cls");
	printf("*****************************SUPPRIMER UN FILM*********************************\n");
    printf("________________________________________________________________________________\n\n\n");


        printf("nom du film a supprimer:\t");
        fflush(stdin);
        gets(nom);





    while ((p!=NULL)&&((strcmp(p->valeur.titre,nom)!=0)))
    {
			pre=p;
			p=p->suivant;
    };

    if(p==NULL)
    {
            printf("\n film introuvable \n");
            return l;
    }

    if(p==l)
    {
            l=l->suivant;
            free(p);
            printf("\n\a\a FILM SUPPRIME \n\n");
            return l;
    }
    pre->suivant=p->suivant;
    free(p);
    printf("\n FILM SUPPRIME\n\n");
    return l;
}



liste CreerListeVide() /*creation d'une liste vide */
{
	liste l;
	l=NULL;
	return l;
}

liste conv(liste l)/* c'est pour effacer toute occurence de ' ' à cause de quelques problémes rencontrées lors de l'utilisation de fscanf*/
{
    int i,j;
    liste p;
    p=l;
    while(p!=NULL)
    {
for(i=0;i<strlen(p->valeur.titre);i++)
        {
            if (p->valeur.titre[i]==' ')
                p->valeur.titre[i]='_';
        }
        for(i=0;i<strlen(p->valeur.realisateur);i++)
        {
            if (p->valeur.realisateur[i]==' ')
                p->valeur.realisateur[i]='_';
        }
        for (j=0;j<4;j++)
        {
            for(i=0;i<strlen(p->valeur.acteurs[j]);i++)
        {
            if (p->valeur.acteurs[j][i]==' ')
                p->valeur.acteurs[j][i]='_';
        }
        }



         for(i=0;i<strlen(p->valeur.qualite);i++)
        {
            if (p->valeur.qualite[i]==' ')
                p->valeur.qualite[i]='_';
        }
         for(i=0;i<strlen(p->valeur.resumee);i++)
        {
            if (p->valeur.resumee[i]==' ')
                p->valeur.resumee[i]='_';
        }
        p=p->suivant;
    }
    return l;
}
liste reciproque(liste l)/*c'est le même principe de la fonction précedentes mais celle ci c'est pour remplacer toute '_' rencontrée par ' '*/
{
    int i,j;
    liste p;
    p=l;
    while (p!=NULL)
    {
     for(i=0;i<strlen(p->valeur.titre);i++)
        {
            if (p->valeur.titre[i]=='_')
                p->valeur.titre[i]=' ';
        }
         for(i=0;i<strlen(p->valeur.realisateur);i++)
        {
            if (p->valeur.realisateur[i]=='_')
                p->valeur.realisateur[i]=' ';
        }
        for (j=0;j<4;j++)
        {
            for(i=0;i<strlen(p->valeur.acteurs[j]);i++)
          {
            if (p->valeur.acteurs[j][i]=='_')
                p->valeur.acteurs[j][i]=' ';
           }
        }

         for(i=0;i<strlen(p->valeur.qualite);i++)
        {
            if (p->valeur.qualite[i]=='_')
                p->valeur.qualite[i]=' ';
        }
         for(i=0;i<strlen(p->valeur.resumee);i++)
        {
            if (p->valeur.resumee[i]=='_')
                p->valeur.resumee[i]=' ';
        }
        p=p->suivant;
}
return l;
}
int testSiFichierVide(FILE* fichier)
{
    int caracterePremier = 0;

    //On lit le prmeier caractère du fichier
    caracterePremier = fgetc(fichier);
    if(caracterePremier==EOF)
    {
        return 1;//le fichier est vide donc on retourne 1
    }
    else
        return 0;//le fichier n'est pas vide donc on retourne 0
}
