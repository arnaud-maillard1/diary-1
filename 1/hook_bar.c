#include <stdio.h>
#include <stdlib.h>

// ça marche pas ! je ne sais pas pourquoi

int main(int argc, char *argv[]) {
    FILE *fa = fopen("bar", "w+");
    printf("Pressez enter...");
    scanf("%*d");
}
