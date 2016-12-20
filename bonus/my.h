/*
** my.h for my.h in /home/pierre/work/Unix_System/PSU_2016_my_sokoban/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Wed Dec 14 14:37:12 2016 Pierre Narcisi
** Last update Tue Dec 20 22:01:08 2016 John Doe
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

typedef struct s_pos
{
  int rx;
  int ry;
  int bx;
  int by;
}              t_pos;

void my_init();
void print_map(char **tab, char **tab2);
int my_nb_line(char **tab);
void my_tel(t_var *p, char **tab, t_pos rbp);
void my_port_pos(t_var rb, t_pos *rbp);
t_var lalala(int index, char **tab, t_var p, t_var *incr);
int Win(char **tab, char **tab2);
char  **tab_cpy(char **tab, char **tab2);
char *my_strcpy(char *src, char *dest);
void affvar(t_var *var);
t_var *find_O(char **tab);
int verif(t_var *var, t_var *p);
void mouv(char **tab, t_var *p, int index, char **tab2, t_pos rbp);
int my_strlen(char *str);
void my_mouv_UP(char **tab, t_var *p, char **tab2, t_pos rbp);
void my_mouv_DOWN(char **tab, t_var *p, char **tab2, t_pos rbp);
void my_mouv_RIGHT(char **tab, t_var *p, char **tab2, t_pos rbp);
void my_mouv_LEFT(char **tab, t_var *p, char **tab2, t_pos rbp);
t_var find(char **tab);
