# Semaine 4/16

- [ ] Écriture et lecture de fichiers binaires
  - [ ] Alignement mémoire et navigation
  - [ ] Écriture de structures
- [ ] Pointeurs (suite)
  - [ ] Arithmétique de pointeurs
  - [ ] Priorité des opérations sur les pointeurs
  - [ ] Exercices

## Exercice 1 : pointeurs

Considérez que chaque ligne est exécutée l'une après l'autre. Indiquez dans la colonne les différentes valeurs des variables :

| Code            | A   | B   | C   | P1  | P2  |
| --------------- | --- | --- | --- | --- | --- |
| `int A = 1;`    |     |     |     |     |     |
| `int B = 2;`    |     |     |     |     |     |
| `int C = 3;`    |     |     |     |     |     |
| `int *P1, *P2;` |     |     |     |     |     |
| `P1=&A;`        |     |     |     |     |     |
| `P2=&C;`        |     |     |     |     |     |
| `*P1=(*P2)++;`  |     |     |     |     |     |
| `P1=P2;`        |     |     |     |     |     |
| `P2=&B;`        |     |     |     |     |     |
| `*P1-=*P2;`     |     |     |     |     |     |
| `++*P2;`        |     |     |     |     |     |
| `*P1*=*P2;`     |     |     |     |     |     |
| `A=++*P2**P1;`  |     |     |     |     |     |
| `P1=&A;`        |     |     |     |     |     |
| `*P2=*P1/=*P2;` |     |     |     |     |     |

## Exercices 2 : pointeurs

Considérez ces déclarations :

```c
int A[] = {12, 23, 34, 45, 56, 67, 78, 89, 90};
int *P;
P = A;
```

Quelles valeurs ou adresses fournissent ces expressions ?

| Code               | Valeur |
| ------------------ | ------ |
| `*P+2`             |        |
| `*(P+2)`           |        |
| `&A[4]-3`          |        |
| `A+3`              |        |
| `&A[7]-P`          |        |
| `P+(*P-10)`        |        |
| `*(P+*(P+8)-A[7])` |        |

