#include <stdio.h>
#include <string.h>

void version() {
    printf(
        "Version 0.1.1 Copyright HEIG-VD "
        "<yves.chevallier@heig-vd.ch>"
    );
}
/**
 * char *argv[]
 *         ^     Argv est
 *           ^            un tableau
 *      ^                            de pointeur
 * ^                                 sur des caractères
 *
 * Un pointeur sur des caractères == Chaîne de caractère
 * -> Tableau de chaînes de caractères
 */
int main(int argc, char *argv[]) {
#if 0 // Ne faites jamais ça !!!
    printf("%s", argv[132]);
#else // On test toujours si l'argument existe !
    const int arg = 132;
    if (argc > arg) printf("%s", argv[arg]);
#endif

    // Traite les options sur les arguments
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0) {
            version();
            return 0;
        }
    }

    // Affiche ARGument Count et les arguments
    printf("Nombre d'arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("%d. \"%s\"\n", i, argv[i]);
    }
}