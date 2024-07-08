# moduleImageSDL2

Ce module Image utilise une version très simple de SDL2 pour afficher une image dans une fenêtre SDL.

Il fonctionne avec une structure pixel, une classe Image et une classe ImageViewer.

La documentation est déjà générée exceptionnellement et se trouve dans le dossier doc. Vous pouvez ouvrir le fichier index.html dans le dossier doc/html pour lire et comprendre la documentation.

## Compilation

Pour compiler ce projet, vous aurez besoin d'un terminal Linux et de cmake.

Placez-vous à la racine du projet et tapez les instructions suivantes dans le terminal :

```sh
cd build
cmake ..
make
```
## Les exécutables

Il y aura dans le dossier bin trois exécutables après la compilation :

    -affichage : affiche l'image passée en paramètre.
    -test : exécute le test de régression et enregistre une image.
    -exemple : fournit un exemple en enregistrant deux images.

## Exécution principale

Une fois les instructions de compilation terminées, vous pouvez exécuter le programme comme suit :

Placez-vous à la racine du projet et tapez la commande suivante :

```sh
bin/affichage
```

## Rendu

Une fenêtre SDL s'ouvre avec une image représentant des anneaux olympiques carrés.

L'image peut être changée en modifiant celle qui est donnée dans src/mainAffichage.cpp (vous pouvez vous amuser à dessiner d'autres images en plaçant vous-même les pixels, bien sûr).

Vous pourrez exécuter les deux autres exécutables de la même manière que affichage.
