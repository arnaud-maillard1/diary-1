#include <stdio.h>

/**
 * L'entrée standard (0) [stdin]
 * Sortie standard (1) [stdout]
 * Sortie d'erreur (2) [stderr]
 */
int main() {
    FILE * fp = fopen("2/README.md", "r");
    printf("Position du curseur: %ld\n", ftell(fp));
    char c = fgetc(fp); // Le curseur se déplace de 1
    printf("Position du curseur: %ld\n", ftell(fp));

    // Positionner le curseur à la fin du fichier
    fseek(fp, 0, SEEK_END); // SEEK_SET, SEEK_END, SEEK_CUR
    printf("Position du curseur: %ld\n", ftell(fp));

    // Position depuis le début du fichier
    int k = 5;
    fseek(fp, k, SEEK_SET);
    printf("Caractère à la position %d : 0x%hhx\n", k, fgetc(fp));

    fseek(fp, -k, SEEK_END);
    printf("Caractère à la position %d depuis la fin du fichier : 0x%hhx\n", k, fgetc(fp));
}
