#include <stdio.h>
#include <string.h>

char titres[50][50];
char auteurs[50][50];
float prix[50];
int quantite[50];
char titrerechercher[50];
int i;

int nomberliver = 0;

void ajouterLivre() {
    if (nomberliver < 50) {
        printf("Titre du livre : ");
        scanf("%s", titres[nomberliver]);  

        printf("Auteur du livre : ");
        scanf("%s", auteurs[nomberliver]);  

        printf("Prix du livre : ");
        scanf("%f", &prix[nomberliver]);

        printf("Quantite en stock : ");
        scanf("%d", &quantite[ nomberliver]);

        nomberliver++;
        printf(" Livre ajoute avec succes !\n");
    } else {
        printf(" Stock plein.\n");
    }
}

void afficherLivres() {
    if (nomberliver == 0) {
        printf(" Aucun livre en stock.\n");
    } else {
        for (int i = 0; i < nomberliver; i++) {
            printf("%d. titre: %s | Auteur: %s | Prix: %.2f | Quantite: %d\n",
                   i+1, titres[i], auteurs[i], prix[i], quantite[i]);
        }
    }
}

void  rechercherlivre(){
    printf("entrer le titre de livre a rechercher :");
    scanf("%s",&titrerechercher);
    for (i=0;i<nomberliver;i++){
        int s = strcmp(titrerechercher,titres[i]);
        if (s == 0){
            printf("le livre est trouve : %s %s %.2f %d\n",titres[i],auteurs[i],prix[i],quantite[i]);
        }
        else{
            printf("le livre n'est pas trouve\n");
        }
    }
}
void supprimerlivre(){
        if (nomberliver == 0) {
            printf("aucun livre en stock.\n");
        } else {
            char titresupprimer[50];
            printf("entrer le titre de livre a supprimer :");
            scanf("%s",titresupprimer);
            for (i=0;i<nomberliver;i++){
                if (stricmp( titresupprimer,titres[i])==0){
                    for (int j = i; j < nomberliver - 1; j++) {
                        strcpy(titres[j], titres[j + 1]);
                        strcpy(auteurs[j], auteurs[j + 1]);
                        prix[j] = prix[j + 1];
                        quantite[j] = quantite[j + 1];
                    }
                    nomberliver--;
                    printf("Livre supprime avec succes.\n");
                    return;
                }
            }
            printf("Livre non trouve.\n");
        }



}
void affichagelenombretotal(){
    printf("le nombre total des livres est : ¨%d\n",nomberliver);
}

int main() {
    int choix;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterLivre(); break;
            case 2: afficherLivres(); break;
            case 3: rechercherlivre();break;
            case 4: supprimerlivre();break;
            case 5: affichagelenombretotal();break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide !\n");
        }
    } while (choix != 0); 

    return 0;
}