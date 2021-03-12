/**
 * Afficher la taille d'un fichier sur la sortie standard.
 * Faire la somme de tous les chiffres dans ce fichier.
 * Afficher cette somme sur la sortie standard.
 *
 * ./a.out file.txt
 * Taille : 12354 bytes
 * Somme des chiffres : 4551
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



void display_size(size_t size, FILE *fp) {
    fprintf(fp, "Taille : %ld bytes\n", size);
}

void display_sum(size_t sum, FILE *fp) {
    fprintf(fp, "Somme des chiffres : %ld\n", sum);
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

/**
 * Calcul la taille fichier.
 *
 * @param fp Fichier d'entrée
 * @return La taille du fichier
 */
size_t compute_size(FILE *fp) {
    size_t pos = ftell(fp); // Store cursor position

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);

    fseek(fp, pos, SEEK_SET); // Restore cursor position

    return size;
}

/**
 * Calcul la somme des chiffres dans un fichier.
 *
 * @param fp Un fichier d'entrée
 * @return La somme des chiffres du fichier
 */
int compute_sum(FILE *fp) {
    if (fp == NULL)
        return 0;

    int sum = 0;
    while(!feof(fp)) {
        char c = fgetc(fp);
        if (isdigit(c)) {
            int digit = c - '0';
            sum += digit;
        }
    }
    return sum;
}

void version(FILE * fp) {
    fprintf(fp,
        "Version 0.0.1 (c) "
        "Yves Chevallier <yves.chevallier@heig-vd.ch>\n"
    );
}

void help(FILE * fp) {
    fprintf(fp,
        "usage: ./a.out filename\n\n"
        "Ce programme affiche la taille du fichier et\n"
        "la somme des chiffres contenus dans ce fichier.\n"
    );
}


int main(int argc, char *argv[]) {
    // Traitement des arguments
    char * filename = NULL;
    for (int k = 1; k < argc; k++) {
        char *arg = argv[k];
        if (strcmp(arg, "--version") == 0) {
            version(stdout);
            exit(EXIT_SUCCESS);
        }
        if (strcmp(arg, "--help") == 0) {
            help(stdout);
            exit(EXIT_SUCCESS);
        }
        filename = arg;
    }

    // Traitement des cas d'exception
    if (filename == NULL) {
        fprintf(stderr, "Erreur: nom de fichier manquant !\n");
        exit(4);
    }

    // Ouvrir le fichier
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Erreur: fichier introuvable !\n");
        exit(7);
    }

    // Programme principal
    display_size(compute_size(fp), stdout);
    display_sum(compute_sum(fp), stdout);
}
