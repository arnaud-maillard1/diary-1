/**
 * Afficher la taille d'un fichier sur la sortie standard.
 * Faire la somme de tous les chiffres dans ce fichier.
 * Afficher cette somme sur la sortie standard.
 */

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

void display_size(FILE *fp) {

}

int compute_sum(FILE *fp) {

}

int main() {

}
