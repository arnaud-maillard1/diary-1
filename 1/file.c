#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE * fp; // File Pointer (type abstrait)

    if (argc < 2) abort();

    // 1. Ouvrir le fichier
    if (!(fp = fopen(argv[1], "r"))) {
        printf("Oops, on peut pas ouvrir le fichier!\n");
    };

    // 2. Lire contenu
    // feof == (File) End Of File ?
    int line = 1;
    while(!feof(fp)) {
        char buffer[100];
        fgets(buffer, sizeof(buffer), fp);

        // 3. Affichage du contenu
        printf("%d. %s", line++, buffer);
    }

    // 4. Fermer ce fichier
    if (fclose(fp) != 0) {
        printf("Oops, il y a eu une erreur!\n");
    }
}