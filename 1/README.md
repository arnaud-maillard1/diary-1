# Semaine 1/16

## Plan

### Mercredi

- [x] Points administratifs
- [x] Liens vers les supports de cours
- [x] Mise à niveau
- [x] Arguments
- [x] La ligne de commande avec `gcc -E`
- [x] Lecture de fichiers

### Vendredi

- [x] Git / GitHub
- [x] Ouvrir plusieurs fichiers
- [ ] Comment naviguer dans un fichier
- [ ] Ce qui se passe derrière quand on manipule des fichiers
- [ ] Différents types de fichiers

## Support de cours

- Cours Web https://heig-tin-info.github.io/handout/
  - Possibilité de demander une version imprimée si vous le souhaitez
- Carte de référence Info1/Info2 https://github.com/heig-tin-info/refcard
- Journal de cours https://github.com/info2-tin-b/diary

## Mise à niveau

- WSL2 (Ubuntu) pour Windows version 2004 ou 20H2
  - Menu démarrer puis "about"
- Microsoft Visual Studio Code

- [x] Structures

## Arguments

- Permet de configurer un programme à son exécution
- Les arguments sont un tableau de chaînes de caractères
- L'argument 0 c'est le nom du programme
- Un programme a toujours un argument 0

## Compilation d'un programme

```sh
gcc source.c
```

1. Préprocesseur (traite tous les # dans le fichier source)
2. Compilation (génère du langage machine, génération de l'objet)
3. Édition des liens
4. Production de l'exécutable (génère un ELF)

## Notes sur Git

- Git c'est logiciel de gestion de version (SCM)
- GitHub c'est une plateforme de stockage de référentiels Git sur Internet

```sh
git clone git@github.com:info2-tin-b/diary.git
git commit -am "Commentaire"
git push
git status
git pull --rebase
git checkout .
git checkout file.c
```

Un bon livre : https://git-scm.com/book/en/v2

## Exemple

```c
/*
./phonetics input.txt [output.txt]
      0         1          2
*/

FILE *fout = argc > 1 ? fopen(argv[2], "w") : stdout;


FILE *fout = stdout;
if (argc > 1) {
    fout = fopen(argv[2], "w")
}

fprintf(fout, "quelque chose");

```
