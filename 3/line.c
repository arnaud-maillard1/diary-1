#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Ouvre un fichier et détermine s'il y a une erreur
 *
 * @param filename Nom du fichier
 * @param fp Pointeur sur le fichier
 * @return true si il y eu une erreur
 */
bool open_file(char *filename, FILE **fp) {
    *fp = fopen(filename, "r");
    return *fp == NULL;
}

int main() {
    FILE * fp = NULL;

    // Ouvrir mon fichier
    if (open_file("hello.txt", &fp)) {
        fprintf(stderr, "Fichier introuvable !\n");
        exit(1);
    }

    // Lire une ligne
    char line[1024];
    const size_t line_size = sizeof(line) / sizeof(line[0]);

    while(!feof(fp)) {
        fgets(line, line_size, fp);
        printf("line: %s", line);

        // Position du curseur après une ligne
        printf("curseur: 0x%lx\n", ftell(fp));
    }

    fclose(fp);
}
