#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *filename_a = "foo";
    char *filename_b = "bar";

    FILE *fa = fopen(filename_a, "r"); // Le fichier doit exister
    FILE *fb = fopen(filename_b, "w"); // Attention le fichier est écrasé !

    if (fa == NULL) {
        fprintf(stderr, "Erreur: Il y a eu un problème avec de %s ! "
            "Est-ce que %s existe?\n", filename_a, filename_a
        );
        exit(EXIT_FAILURE);
    }

    if (fb == NULL) {
        fprintf(stderr, "Erreur: Il y a eu un problème avec de %s ! "
            "Est-ce que ce fichier est déjà ouvert par un autre programme ?\n"
            , filename_b
        );
        exit(EXIT_FAILURE);
    }

    char c;
    while((c = fgetc(fa)) != EOF) {
        fputc(c, fb);
        fflush(fb);
    }

    if (fclose(fa)) {fprintf(stderr, "Erreur avec fa\n");}
    if (fclose(fb)) {fprintf(stderr, "Erreur avec fb\n");}
}
