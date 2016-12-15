
typedef struct film
{
     char titre[40];
     char realisateur[40];
     int nb;
     char acteurs[10][20];
     char qualite[20];
     char resumee[100];
     int duree;
     int j;
     int m;
     int a;
     }film;
     typedef struct cellule{
     film valeur;
     struct cellule *suivant;
     }cellule;
     typedef cellule *liste ;
film nouveau();
liste ajouter(film nouv,liste l);
liste lire_fichier(liste l);
void ecrire_fichier(liste l);
void recherche_globale(liste l);
int recherche_particuliere(char mot_cle[],char titre[]);
liste supprimer(liste l);
liste CreerListeVide();
liste reciproque(liste l);
liste conv(liste l);
int testSiFichierVide(FILE* fichier);
