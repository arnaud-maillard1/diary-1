# Semaine 2/16

- [ ] Suite des fichiers
  - [ ] C'est quoi un *filesystem*
  - [ ] Interaction avec le *filesystem*
  - [ ] La navigation dans les fichiers
  - [ ] Petit exercice

## Le filesystem (Le système de fichier)

                 v
0011001100001000 01110000 111000111 00001100 11110011 00011001 1001100011010100110000110111000000 00 0  00000
   'h'     'e'        'l'     'l'      'o'   ^

- taille du fichier
- adresse de début (emplacement)
- fichier
- dossier (peut contenir des fichiers ou des dossiers)
- root (le dossier parent)
- chaque élément à un nom
- extension
- gestion des droit (lecture, écriture, exécution)
- date de création et de modification
- drapeau (flag) exécutable

/ (origine)
|- home/
   |- yves/
      |- .gitconfig

## Chemins

/home/yves/.gitconfig  (chemin absolu)
C:\Users\yves\.gitconfig

yves/.gitignore (chemin relatif)
yves\.gitconfig

## À retenir

- Chaque fichier à:
  - Une taille
  - Un nom
  - Un propriétaire
  - Une date de modification
  - Une date de création
  - Des droits d'accès
- Il est dans une arborescence
  - Chemins absolus et relatifs
    - Sous Windows le séparateur c'est `\`
    - Sous POSIX le séparateur c'est `/`
