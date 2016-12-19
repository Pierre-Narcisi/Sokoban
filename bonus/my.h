/*
** my.h for my.h in /home/pierre/work/Unix_System/PSU_2016_my_sokoban/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Wed Dec 14 14:37:12 2016 Pierre Narcisi
** Last update Mon Dec 19 14:45:38 2016 Pierre Narcisi
*/

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

typedef struct s_var
{
  char c;
  int x;
  int y;
}             t_var;

void lalala(int index, char **tab, t_var p);
int Win(char **tab, char **tab2);
char  **tab_cpy(char **tab, char **tab2);
char *my_strcpy(char *src, char *dest);
void affvar(t_var *var);
t_var *find_O(char **tab);
int verif(t_var *var, t_var *p);
void mouv(char **tab, t_var *p, int index, char **tab2);
int my_strlen(char *str);
void my_mouv_UP(char **tab, t_var *p, char **tab2);
void my_mouv_DOWN(char **tab, t_var *p, char **tab2);
void my_mouv_RIGHT(char **tab, t_var *p, char **tab2);
void my_mouv_LEFT(char **tab, t_var *p, char **tab2);
t_var find(char **tab);
