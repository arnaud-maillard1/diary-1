# Semaine 3/16

- [x] fseek, appels systèmes (strace), ouvrir et fermer des fichiers
- [x] fonction de traitement de chaîne de caractères
- [ ] exercice
  - [ ] détecter la taille d'un fichier
  - [ ] somme des chiffres dans ce fichier

## Étapes

1. Revu le mecanisme de déplacement du curseur `seek.c`
2. Lit un certain nombre de lignes dans un fichier `line.c`
3. Comment sauvegarder un entier entre plusieurs appels du programme `persistance.c`
4. Lit un certain nombre de lignes avec mémorisation de la dernière position `line2.c`

## Sizeof

```c
double array[10];
const size_t size = sizeof(array) / sizeof(array[0]);
```
