<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174792211-2db9aca5-15a5-413c-8fbc-16809e58c09c.png" />
</p>
<h1 align="center">
   MINISHELL1
</h1>

---

## Motivation : 

Le **Minishell1** est un projet d'Epitech se déroulant vers milieu d'année. Il fait parti d'une série de 3 grands projets sur le thème de la programmation de Terminal (Shell Programming). Il précède le Minishell2 et le 42sh, la version finale qui est un des 3 grands projets d'Epitech.

---

## Description :

Le **Minishell1** à pour but de reprogrammer un terminal de commande en prenant le terminal TCSH comme exemple.
Ces caractéristiques doivent être les suivantes : 
- Pouvoir exécuter n'importe quel type de binaires
- Créer les fonctions builtins *cd*, *env*, *setenv*, *unsetenv*

Les fonctionnalités tel que les séparateurs, les redirections et les pipes seront ajouter sur les projets du minishell2 ou bien le 42sh.

---

## Fonctions Autorisées : 

- malloc, free, exit, opendir, readdir, closedir, getcwd, chdir
- fork, stat, lstat, fstat, open, close, getline, strtok, strtok_r
- read, write, execve, access, isatty, wait, waitpid
- wait3, wait4, signal, kill, getpid, strerror, perror, strsignal

---

## Installer & Lancer le Projet :

Ouvrez un terminal et dirigez vous ou vous souhaitez que le projet soit installé, puis exécutez les commandes suivantes : 
```bash
$ git clone git@github.com:DoctypeHonoo/minishell1.git
$ cd minishell1
$ make
```
Le binaire se trouvera alors à la racine du projet, et il vous suffira de le lancer comme ceci : 
```bash
$ ./mysh
```
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174791267-34abac86-b25c-4e09-afc4-bfa16f31bd0f.png">
</p>

---

## Comment l'utiliser ? : 

Le terminal **Minishell1** s'utilise comme tout autre terminal, il vous est possible d'utiliser n'importe quel binaire interne, tel que *ls*, *cat*, *grep*, et bien d'autre, mais aussi les fonctions builtins, tel que *cd*, *setenv*, *unsetenv* et *env*. 
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174793117-2ed8992d-33a9-4037-b861-6d4e1bcdec43.png">
</p>
