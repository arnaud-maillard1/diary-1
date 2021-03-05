/**
 * Lire des données tabulées (periodicité)
 * - [ ] Lire le fichier data.dat
 * - [ ] Lire l'année
 * - [ ] Lire la température
 * - [ ] Afficher pour toutes les valeurs le texte "Il a fait %g degré en %d"
 * - [ ] Afficher la température pour la xième entrée
 */
#include <stdio.h>
#include <stdlib.h>

#define LINE_WIDTH (27)

// Afficher chaque entrée
void display_all_entries(FILE *fp) {
    char entry[64];
    while(fgets(entry, sizeof(entry), fp)) {
        int year;
        double temp;
        sscanf(entry, "%4d-%*d-%*dT%*d:%*d:%*d %lf", &year, &temp);
        printf("Il a fait %g degré en %d\n", temp, year);
    }
}

// Lire la température à la position X
double temperature(FILE *fp, size_t line) {
    // Position au début la ligne voulue
    fseek(fp, line * LINE_WIDTH, SEEK_SET);

    // Position devant la température
    fseek(fp, 21, SEEK_CUR);

    double temp;
    if (fscanf(fp, "%lf", &temp) != 1) {
        perror("Pas lu lire la température");
        return 0;
    };
    return temp;
}

int main(int argc, char *argv[]) {
    // Lire le nom du fichier sur les arguments
    if (argc < 2) {
        perror("Nom de fichier manquant");
        exit(5);
    }
    char *filename = argv[1];

    // Ouvrir le fichier
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Impossible d'ouvrir le fichier");
        exit(6);
    }

    display_all_entries(fp);

    int line = 4;
    printf("Voici la température à la ligne %d: %g\n", line, temperature(fp, line));

    fclose(fp);
}
