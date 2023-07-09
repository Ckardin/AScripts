# Ascripts

## Qu'est-ce que c'est ?

AScripts est un ensemble de scripts courts (moins d'une cinquantaine de lignes "effectives") qui permettent d'effectuer des actions utiles.

## Utilisation

### Diff

Diff est un script qui retourne "Same Directory", si les deux dossiers passés en paramètre sont identiques, et "Not Same Directory" sinon.

Identiques au sens du fait qu'ils ont les mêmes noms de fichier à l'intérieur.

### Echo

Echo une commande qui permets d'afficher un texte (comme celle du même nom sans la majuscule ^^), mais avec des couleurs. Les couelurs dispos sont les suivantes:

* Blanc (white)
* Noir (black)
* Rouge (red)
* Vert (green)
* Bleue (blue)
* Jaune (yellow)
* Cyan (cyan)
* Magenta (magenta)
* Couleur par défaut (default)

Elle s'utilise comme ceci:

    Echo "texte" couleurpremierplan couleurarriereplan

En sous-jacent, il y a des appels à tput.

### Lines

Lines permets de laisser des lignes vides, lors de l'affichage dans un terminal. Le script ne prends qu'un seul paramètre, le nombre de lignes souhaité.

### Spaces

Même chose que Lines, mais avec des espaces. Un seul paramètre aussi, le nombre souhaité.

### MakeInfo

Ce script est le plus long. Aussi, il permets d'afficher l'état d'une execution via un Makefile, où on aurait enlever l'affichage de retour d'une commande.

La commande prends 3 paramètres:

* Le type de la compilation/linkage
* Le nom de la cible ou de la compilation en cours (exemple plus bas)

Les types acceptés sont les suivants:

* making (on éxécute une cible particulière ou un ensemble de modules ou une lib)
* clean (explicite, on "nettoie" quelque chose)
* install (explicite, on installe une cible ou une librairie)
* module (on compile un module)
* static (on fait l'édition des liens d'une librairie, de manière statique)
* dynamic (on fait l'édition des liens d'une librairie, de manière dynamique)
* program_s (on fait le linkage d'un program de manière staique)
* program_d (on fait le linkage d'un program de manière dynamique)
* doc (on compile une documentation latex/doxygen)

#### Exemples

Voici un exemple, où l'on voudrait indiquer qu'un module est en train d'être compilé:

    MakeInfo module TestModule

Ici, on a un exemple pour une librairie statique:

    MakeInfo static LibTest

## Compatibilité

Comme tous les outils Ashes, cet ensemble de scripts est multi-plateformes. On peut l'utiliser sur un système Windows (avec PowerShell) ou bien sur un système Linux. En principe, il est possible également d'executer les scripts sur Mac OS, les commandes utilisées y étant normalement intégrées. A piori, de même avec les sytèmes BSD Like. Cependant, les commandes n'ont été testées que sur Windows et un système Linus "standard" à l'installation (sans ajout supplémentaire et sur une distribution minimaliste).

## Installation

Pour l'installer, rien de plus simple il suffit d'executer, en fonction de votre sytème, l'un des scripts d'installation disponibles à la racine du projet. Avant ça, vous pouvez définir une variable d'envirronnement ASHES_DIR (si possible immuable (enregistrée dans un fichier de config, ou avec la commande `setx` sur Windows)) qui contiendra le chemin d'accès vers le dossier Ashes (dossier utilisé pour l'installation de l'envirronnement).

Aussi, le fichier d'installion détecte si la variable existe, et si ce n'est pas le cas, il la créera et l'enregistrera. Également, vous pouvez ajouter le dossier $ASHES_DIR/bin (Linux) ou $($env:ASHES_DIR)\bin (Windows), au PATH de votre système. Le fichier d'installation ne le fera pas de lui même.

## Licence

Ce projet est sous Licence GPL V3. Vous pouvez trouver sur chaque fichier une entête correspondante, et une copie de la licence est placée dans le fichier COPYING.
