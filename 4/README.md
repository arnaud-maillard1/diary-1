# Semaine 4/16

- [x] Théorie sur les typedefs structures
- [x] Écriture et lecture de fichiers binaires
  - [x] Écriture de structures
  - [x] Alignement mémoire et navigation

## Résumé du cours

- Typedefs et structures voir [fichier](typedefs.c)
- Écrire un fichier CSV [csv.c](csv.c)
- Écrire un fichier binaire [binary_write.c](binary_write.c)
- Décoder avec hexdump : `hexdump -C output.dat`
- Lire un fichier binaire [binary_read.c](binary_read.c)
- Écrire du binaire sur `stdout`: [binary_write_stdout.c](binary_write_stdout.c)
- Lire à un offset dans un fichier binaire : [binary_read_third.c](binary_read_third.c)

## Notes

```c
if (fscanf(fp, "%4d,%lf", &year, &temp) == 0) {
    char c;
    while((c = fgetc(fp)) != '\n' || c != EOF) {}
};

#define LINE 1024
char buffer[LINE];
while(fgets(buffer, LINE, fp) != NULL) {
    int year;
    double temp;
    if (sscanf(buffer, "%4d,%lf", &year, &temp) == 0) {
        continue;
    }
    printf("Année: %d, Température %f", year, temp);
}
```
