/**
 * stdin (0), stdout (1), stderr (2)
 * ouverture et lecture fichiers (fopen, fclose, fgets, fgetc, fscanf)
 * écriture de fichiers (fprintf, fputc, fputs)
 */
#include <stdio.h> // STanDard Input Output
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int print_vowel(FILE *fp) {
    // Test si le pointeur est valide
    if (fp == NULL) {
        fprintf(stderr, "Pointeur de fichier invalide !\n");
        return 1;
    }

    // Ramène le curseur au début du fichier
    fseek(fp, 0, SEEK_SET);

    char c;
    while((c = fgetc(fp)) != EOF) {
        switch(tolower(c)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'y':
                printf("%c", c);
                break;
        }
    }
}

/**
 * Ouvre un fichier et détermine s'il y a une erreur
 *
 * @param filename Nom du fichier
 * @param fp Pointeur sur le fichier
 * @return true si il y eu une erreur
 */
bool open_file(char *filename, FILE **fp) {
    *fp = fopen("hello.txt", "r");
    return *fp == NULL;
}

int main() {
    FILE * fp = NULL;

    if (open_file("hello.txt", &fp)) {
        fprintf(stderr, "Fichier introuvable !\n");
        exit(1);
    }

    print_vowel(fp);

    fclose(fp);
}
