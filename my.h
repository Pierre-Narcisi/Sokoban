/*
** my.h for my.h in /home/pierre/work/Unix_System/PSU_2016_my_sokoban/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Wed Dec 14 14:37:12 2016 Pierre Narcisi
** Last update Wed Dec 14 16:10:15 2016 Pierre Narcisi
*/

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>


typedef struct s_var
{
  int x;
  int y;
}             t_var;

void my_mouv_UP(char **tab, t_var *p);
void my_mouv_DOWN(char **tab, t_var *p);
void my_mouv_RIGHT(char **tab, t_var *p);
void my_mouv_LEFT(char **tab, t_var *p);
