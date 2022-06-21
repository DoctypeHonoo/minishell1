<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/173183424-3797c756-5d1d-47cd-8019-04b8e2c1f07f.png" />
</p>
<h1 align="center">
   MINISHELL2
</h1>

---

## Motivation : 

Le **Minishell2** est un projet d'Epitech se déroulant vers milieu/fin d'année. Il fait parti d'une série de 3 grands projets sur le thème de la programmation de Terminal (Shell Programming). Il suit le Minishell1 et précède le 42sh, ça version finale qui est un des 3 grands projets d'Epitech.

---

## Description :

Le **Minishell2** à pour but de reprogrammer un terminal de commande en prenant le terminal TCSH comme exemple.
Ces caractéristiques doivent être les suivantes : 
- Pouvoir exécuter n'importe quel type de binaires
- Créer les fonctions builtins *cd*, *env*, *setenv*, *unsetenv*
- Gérer les séparateurs ";", les pipes "|" et les redirections "<", ">", "<<" et ">>"

Quand aux fonctionnalités tels que les && et les || mais aussi le reste des builtins (where, alias, repeat...), elles sont l'un des objectifs du projet suivant, le 42sh.

---

## Fonctions Autorisées : 

- malloc, free, exit, opendir, readdir, closedir, getcwd, chdir
- fork, stat, lstat, fstat, open, close, getline, strtok, strtok_r
- read, write, execve, access, isatty, wait, waitpid
- wait3, wait4, signal, kill, getpid, strerror, perror, strsignal
- pipe, dup, dup2

---

## Installer & Lancer le Projet :

Ouvrez un terminal et dirigez vous ou vous souhaitez que le projet soit installé, puis exécutez les commandes suivantes : 
```bash
$ git clone git@github.com:DoctypeHonoo/Minishell2.git
$ cd Minishell2
$ make
```
Le binaire se trouvera alors à la racine du projet, et il vous suffira de le lancer comme ceci : 
```bash
$ ./mysh
```
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174324257-643359eb-7f57-478c-85c6-128e540f568f.png">
</p>

---

## Comment l'utiliser ? : 

Le terminal Minishell2 s'utilise comme tout autre terminal, il vous est possible d'utiliser n'importe quel binaire interne, tel que *ls*, *cat*, *grep*, et bien d'autre, mais aussi les fonctions builtins, tel que *cd*, *setenv*, *unsetenv* et *env*. De plus, mon minishell2 dispose des séparateurs "**;**" et permet donc d'exécuter plusieurs commande sur une même ligne. Malheureusement il ne possède pas encore les fonctionnalités des pipes et des redirections. Pour finir mon Minishell2 permet aussi d'exécuter n'importe quel autre binaire se trouvant sur le pc, et indique aussi les Segmentation Faults.

<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174324680-877675c7-df21-46e5-bc8a-01379c644ab8.png">
</p>
