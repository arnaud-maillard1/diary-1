#include <stdio.h>

void change(int *p) { // p est un pointeur sur un entier
    *p = 4; // Je vais modifier la valeur pointée par p (déréférencement)
}

int main() {
    int i = 42;

    change(&i);

    // q est un pointeur sur un entier (quelque part en mémoire)
    // q est assigné à l'adresse de i
    // donc q pointe sur la valeur de i (à l'adresse de i)
    int *q = &i;

    // je déréférencie le pointeur q (qui pointe sur i)
    // q contient l'adresse de i à la quelle je veux modifier une valeur
    // -> Je me rends à l'adresse de i, je frappe à la porte
    // -> i ouvre, "je lui" modifie sa valeur
    // -> je rentre chez moi...
    *q = 23;

    printf("Adresse de i : %p\n", &i);
}
