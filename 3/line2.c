#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define STORAGE_FILE ".session"

void store(int value) {
    FILE *fp = fopen(STORAGE_FILE, "w");
    fprintf(fp, "%d", value);
    fclose(fp);
}

int load() {
    int value;
    FILE *fp = fopen(STORAGE_FILE, "r");
    if (fp == NULL) {
        return 0;
    }
    if (fscanf(fp, "%d", &value) != 1) {
         return 0;
    };
    fclose(fp);
    return value;
}

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

unsigned int arg_to_uint(int argc, char *argv[], int arg) {
    int value;
    if (argc <= arg) {
        fprintf(stderr, "Veuillez indiquer le nombre de lignes à lire!\n");
        exit(2);
    }
    if (sscanf(argv[arg], "%d", &value) != 1) {
        fprintf(stderr, "Argument non valable!\n");
        exit(2);
    }
    if (value <= 0) {
        fprintf(stderr, "Valeur négative ou nulle non admise!\n");
        exit(3);
    }
    return (unsigned int)value;
}

int main(int argc, char *argv[]) {
    FILE * fp = NULL;

    // Ouvrir mon fichier
    if (open_file("lorem.txt", &fp)) {
        fprintf(stderr, "Fichier introuvable !\n");
        exit(1);
    }

    // Lecture du nombre de ligne à lire
    unsigned int lines = arg_to_uint(argc, argv, 1);

    // Lire une ligne
    char line[1024];
    const size_t line_size = sizeof(line) / sizeof(line[0]);

    fseek(fp, load(), SEEK_SET);

    for (int i = 0; i < lines; i++) {
        if (feof(fp)) {
            break;
        }
        fgets(line, line_size, fp);
        printf("line: %s", line);

        // Position du curseur après une ligne
        printf("curseur: %ld\n", ftell(fp));
    }
    store(ftell(fp));

    fclose(fp);
}
