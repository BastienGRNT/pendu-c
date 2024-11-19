#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *pendu[] = {
    " \n\n\n\n\n\n\n  _|_\n |   |______\n |          |\n |__________|\n",
    " \n |\n |\n |\n |\n |\n  _|_\n |   |______\n |          |\n |__________|\n",
    "  ____\n |\n |\n |\n |\n |\n  _|_\n |   |______\n |          |\n |__________|\n",
    "  ____\n |    |\n |\n |\n |\n |\n  _|_\n |   |______\n |          |\n |__________|\n",
    "  ____\n |    |\n |    o\n |\n |\n |\n  _|_\n |   |______\n |          |\n |__________|\n",
    "  ____\n |    |\n |    o\n |   /|\\\n |\n |\n  _|_\n |   |______\n |          |\n |__________|\n",
    "  ____\n |    |\n |    o\n |   /|\\\n |    |\n |\n  _|_\n |   |______\n |          |\n |__________|\n",
    "  ____\n |    |\n |    o\n |   /|\\\n |    |\n |   / \\\n  _|_\n |   |______\n |          |\n |__________|\n"
};

char nom[100];
char mots_pendu[100];
char mots_trouver[100];
char lettres[2];
char lettres_essayer[100];

int erreur = 0;
int tentative_max = 8;
int lettre_trouvee = 0;
int lettre_deja_utiliser = 0;
int double_lettre = 0;

void nom_joueur(void) {  // Correction du type de retour pour 'void'
    printf("Donner votre Nom : ");
    fgets(nom, 100, stdin);
    nom[strcspn(nom, "\n")] = '\0';  // Supprimer le saut de ligne
    printf("Votre nom est : %s \n", nom);
}
void mot_pendu(void) {
    FILE *ouvrir_fichier = fopen("words.txt", "r");
    if (ouvrir_fichier == NULL) {  // Vérification de l'ouverture du fichier
        perror("Erreur d'ouverture du fichier");
        return;
    }

    srand(time(NULL));
    const int nombre_aleatoire = rand() % 835;
    for (int i = 0; i <= nombre_aleatoire; i++) {
        fgets(mots_pendu, sizeof(mots_pendu), ouvrir_fichier);
    }
    printf("%s", mots_pendu);
    fclose(ouvrir_fichier);
    mots_pendu[strcspn(mots_pendu, "\n")] = '\0';
}
void mot_trouver(void) {
    for (int i = 0; i < strlen(mots_pendu); i++) {
        mots_trouver[i] = '_';
    }
    mots_trouver[strlen(mots_pendu)] = '\0';
    printf("Mot a trouver : %s\n", mots_trouver);
}
void proposez_lettres(void) {
    printf("Proposez une lettre : ");
    scanf("%s", lettres);
    for (int i = 0; i < strlen(lettres_essayer); i++) {
        if (lettres[0] == lettres_essayer[i]) {
            lettre_deja_utiliser = 1;
        }
    }
}
int conditions(void) {
    if (lettre_deja_utiliser == 1) {
        printf("Vous avez deja selectionne cette lettres ! \n");
        return 1;
    }
    if (strlen(lettres) > 1) {
        printf("Rentrez qu'une seule lettres ! \n");
        return 1;
    }
    if (lettres[0] < 'a' || lettres[0] > 'z') {
        printf("Rentrez une lettres ! \n");
        return 1;
    }
    return 0;
}
void lettre_essayer(void) {
    printf("Lettres essayees : ");
    for (int i = 0; i < erreur; i++) {
        printf("%c ", lettres_essayer[i]);
    }
    printf("\n");
}
void remplacer_lettres(void) {
    for (int i = 0; i < strlen(mots_pendu); i++) {
        if (lettres[0] == mots_pendu[i]) {
            mots_trouver[i] = mots_pendu[i];
            lettre_trouvee = 1;
        }
    }
}
void compteur_erreur(void) {
    if (lettre_trouvee == 0) {
        lettres_essayer[erreur] = lettres[0];
        if (erreur < tentative_max) {
            printf("%s", pendu[erreur]);
        }
        erreur++;
    }
}
void afficher_mot_trouver(void) {
    printf("Mot trouve : ");
    for (int i = 0; i < strlen(mot_trouver); i++) {
        printf("%c", mots_trouver[i]);
    }
    printf("\n");
}
void boucle(void) {
    while (erreur <= tentative_max && strcmp(mots_trouver, mots_pendu) != 0) {
        lettre_trouvee = 0;
        lettre_deja_utiliser = 0;
        double_lettre = 0;

        proposez_lettres();

        if (conditions()) {
            continue;
        }

        lettre_essayer();
        remplacer_lettres();
        compteur_erreur();
        afficher_mot_trouver();

    }
}
void resultat(void) {
    if (strcmp(mots_trouver, mots_pendu) == 0) {
        printf("Felicitations, vous avez trouve le mot !\n");
    } else {
        printf("Dommage, vous avez depasse le nombre de tentatives. Le mot etait : %s\n", mots_pendu);
    }
}
void jeux_pendu(void) {
    nom_joueur();
    mot_pendu();
    mot_trouver();
    boucle();
    resultat();
}

int main(void) {
    jeux_pendu();
    return 0;
}