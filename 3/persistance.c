#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]) {
    unsigned int old = load();
    printf("Vous aviez saisi la valeur %d\n", old);

    int k = arg_to_uint(argc, argv, 1);
    printf("Vous avez saisi la valeur %d\n", k);
    store(k);
}
